#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>

struct Info {
        double  min = 0;
        double max = 0;
        double sum = 0;
        unsigned long long count = 1;
};

constexpr int countProvices = 34;
constexpr char* strProviceName[] = { "河北","山西","辽宁","吉林","黑龙江","江苏",
                                "浙江","安徽","福建","江西","山东","河南",
                                "湖北","湖南","广东","海南","四川","贵州",
                                "云南","陕西","甘肃","青海","台湾","内蒙古",
                                "广西","西藏","宁夏","新疆","北京","天津",
                                "上海","重庆","香港","澳门" };

void statisticDataset(std::map<std::string, Info>& mapInfo)
{
    unsigned long long count = 0;
    while (count++ < 1000000)   //记录数量
    {
        time_t  curr_time;
        time(&curr_time);

        srand(curr_time+count);
        int index = rand() % countProvices; // 随机生成索引

        double score = rand() % 101;    //随机生成分值

        std::map<std::string, Info>::iterator    iter;
        iter = mapInfo.find(std::string(strProviceName[index]));
        if (iter != mapInfo.end())  //查找到记录，更新sum和count
        {
            iter->second.min = iter->second.min < score ? iter->second.min : score;
            iter->second.max = iter->second.max > score ? iter->second.max : score;
            iter->second.sum += score;
            iter->second.count++;
        }
        else    //未查找到记录，新增记录
        {
            Info    info;
            info.min = info.max = info.sum = score;
            info.count = 1;
            mapInfo.insert(std::pair<std::string, Info>(std::string(strProviceName[index]), info));
        }
    }
}

int main()
{
    std::map<std::string, Info>  mapInfo;

    statisticDataset(mapInfo);  // 统计记录

    // 输出记录统计
    std::cout << mapInfo.size() << "\n";
    for (const auto& elem : mapInfo)
    {
        std::cout << elem.first << "\t";
        std::cout << elem.second.min << "\t";
        std::cout << elem.second.max << "\t";
        std::cout << elem.second.sum / elem.second.count << "\t";
        std::cout << elem.second.count << std::endl;
    }

    return 0;
}