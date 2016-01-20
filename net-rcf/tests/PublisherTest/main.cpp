/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年01月17日 星期日 09时25分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include "PubSubProtocolDefine.h"
#include "RCFPublisherWrapper.hpp"

int main()
{
    RCFPublisherWrapper<I_PubSubMessageHandler> server(50003);
    bool ok = server.start();
    if (ok)
    {
        std::cout << "Publish server start..." << std::endl;
    }
    else
    {
        std::cout << "Publish server start failed" << std::endl;
        return -1;
    }


    std::string topicName = "weather";
    ok = server.createPublisher(topicName);
    if (ok)
    {
        std::cout << "Create publisher success, topic name: " << topicName << std::endl;
    }
    else
    {
        std::cout << "Create publisher failed, topic name: " << topicName << std::endl;
        return -1;
    }

    std::string weatherDescription = "It is going to be a fine day";
    WeatherInfoMessage weatherInfo;
    weatherInfo.m_weatherDescription = weatherDescription;
    server.rcfPublishObject(topicName)->publish().pushWeather(weatherInfo);

    std::cin.get();

    std::cout << "Publish server stoped..." << std::endl;

    return 0;
}
