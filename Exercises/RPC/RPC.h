#pragma once

// RPC structure
struct stRPCInfo{
    double dfLINE_OFF;
    double dfSAMP_OFF;
    double dfLAT_OFF;
    double dfLONG_OFF;
    double dfHEIGHT_OFF;
    double dfLINE_SCALE;
    double dfSAMP_SCALE;     
    double dfLAT_SCALE;
    double dfLONG_SCALE;
    double dfHEIGHT_SCALE;

    double adfLINE_NUM_COEFF[20];
    double adfLINE_DEN_COEFF[20];   
    double adfSAMP_NUM_COEFF[20];
    double adfSAMP_DEN_COEFF[20];
};

void RPCComputeCoeffTerms( double dfLong, double dfLat, double dfHeight, double *padfTerms );

double RPCEvaluateSum( double *padfTerms, double *padfCoefs );

void RPCInverseTransform(stRPCInfo *pRPC, double *dbGeoTran,
                         double dfPixel, double dfLine, double dfHeight,
                         double *pdfLong, double *pdfLat);


void RPCTransform(stRPCInfo *pRPC,
                  double dfLong, double dfLat, double dfHeight,
                  double *pdfPixel, double *pdfLine);
