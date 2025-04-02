#include "RPC.h"
#include <cmath>

void RPCComputeCoeffTerms( double dfLong, double dfLat, double dfHeight, double *padfTerms )
{
	padfTerms[0] = 1.0;
	padfTerms[1] = dfLong;
	padfTerms[2] = dfLat;
	padfTerms[3] = dfHeight;
	padfTerms[4] = dfLong * dfLat;
	padfTerms[5] = dfLong * dfHeight;
	padfTerms[6] = dfLat * dfHeight;
	padfTerms[7] = dfLong * dfLong;
	padfTerms[8] = dfLat * dfLat;
	padfTerms[9] = dfHeight * dfHeight;
 
	padfTerms[10] = dfLong * dfLat * dfHeight;
	padfTerms[11] = dfLong * dfLong * dfLong;
	padfTerms[12] = dfLong * dfLat * dfLat;
	padfTerms[13] = dfLong * dfHeight * dfHeight;
	padfTerms[14] = dfLong * dfLong * dfLat;
	padfTerms[15] = dfLat * dfLat * dfLat;
	padfTerms[16] = dfLat * dfHeight * dfHeight;
	padfTerms[17] = dfLong * dfLong * dfHeight;
	padfTerms[18] = dfLat * dfLat * dfHeight;
	padfTerms[19] = dfHeight * dfHeight * dfHeight;
}

double RPCEvaluateSum( double *padfTerms, double *padfCoefs )
{
	double dfSum = 0.0;
	int i;
 
	for( i = 0; i < 20; i++ )
		dfSum += padfTerms[i] * padfCoefs[i];
 
	return dfSum;
}

void RPCInverseTransform(stRPCInfo *pRPC, double *dbGeoTran,
                         double dfPixel, double dfLine, double dfHeight,
                         double *pdfLong, double *pdfLat)
{
    double dfResultX, dfResultY;

    // 初始值使用放射变换系数求解
    dfResultX = dbGeoTran[0] + dbGeoTran[1] * dfPixel + dbGeoTran[2] * dfLine;

    dfResultY = dbGeoTran[3] + dbGeoTran[4] * dfPixel + dbGeoTran[5] * dfLine;

    // 开始用正变换的函数进行迭代
    double dfPixelDeltaX = 0.0, dfPixelDeltaY = 0.0;

    int nIter;
    for (nIter = 0; nIter < 20; nIter++)
    {
        double dfBackPixel, dfBackLine;

        // 反算像点坐标，计算阈值
        RPCTransform(pRPC, dfResultX, dfResultY, dfHeight,
                     &dfBackPixel, &dfBackLine);

        dfPixelDeltaX = dfBackPixel - dfPixel;
        dfPixelDeltaY = dfBackLine - dfLine;

        dfResultX = dfResultX - dfPixelDeltaX * dbGeoTran[1] - dfPixelDeltaY * dbGeoTran[2];
        dfResultY = dfResultY - dfPixelDeltaX * dbGeoTran[4] - dfPixelDeltaY * dbGeoTran[5];

        if (fabs(dfPixelDeltaX) < 0.001 && fabs(dfPixelDeltaY) < 0.001)
        {
            break;
        }
    }

    *pdfLong = dfResultX;
    *pdfLat = dfResultY;
}

void RPCTransform(stRPCInfo *pRPC,
                  double dfLong, double dfLat, double dfHeight,
                  double *pdfPixel, double *pdfLine)
{
    double dfResultX, dfResultY;
    double adfTerms[20];

    RPCComputeCoeffTerms(
        (dfLong - pRPC->dfLONG_OFF) / pRPC->dfLONG_SCALE,
        (dfLat - pRPC->dfLAT_OFF) / pRPC->dfLAT_SCALE,
        (dfHeight - pRPC->dfHEIGHT_OFF) / pRPC->dfHEIGHT_SCALE,
        adfTerms);

    dfResultX = RPCEvaluateSum(adfTerms, pRPC->adfSAMP_NUM_COEFF) / RPCEvaluateSum(adfTerms, pRPC->adfSAMP_DEN_COEFF);

    dfResultY = RPCEvaluateSum(adfTerms, pRPC->adfLINE_NUM_COEFF) / RPCEvaluateSum(adfTerms, pRPC->adfLINE_DEN_COEFF);

    *pdfPixel = dfResultX * pRPC->dfSAMP_SCALE + pRPC->dfSAMP_OFF;
    *pdfLine = dfResultY * pRPC->dfLINE_SCALE + pRPC->dfLINE_OFF;
}

// 通过控制点对计算仿射变换系数