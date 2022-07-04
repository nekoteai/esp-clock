#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
#include "WiFiClientSecure.h"
#include "ArduinoJson.h"
#include "ESPconfig.h"

DynamicJsonDocument doc(512);

//	getDayWeather 爬取数据&JSON解析
// 存储在char类型中
void getDayWeather(char *zone,short int *temper,char *DayWeather,char *windir,short int *windpower,short int *humidity,String citycode)
{

	String weatherurl = "https://restapi.amap.com/v3/weather/weatherInfo?city="+ citycode +"&key=5839af2a087c22675224036d3d765d2a&base&JSON" ; 
	HTTPClient http; //申请http类
	http.begin(weatherurl); //HTTP begin，入口
	int httpCode = http.GET();//访问网页
	if (httpCode > 0)//检查成功与否
	{
		//Serial.printf("HTTP Get Code: %d\r\n", httpCode);

		if (httpCode == HTTP_CODE_OK) // 收到正确的内容
		{
			//接收源码
			//Serial.println(weatherData);//打印源码
      //{"status":"1","count":"1","info":"OK","infocode":"10000","lives":[{"province":"广东","city":"深圳市","adcode":"440300","weather":"小雨","temperature":"28","winddirection":"北","windpower":"5","humidity":"86","reporttime":"2022-07-03 11:00:48"}]}
			deserializeJson(doc, http.getString()); //开始使用Json解析，使用ArduinoJson_6.x版本，github：https://github.com/bblanchon/ArduinoJson
			
			
		    *temper = doc["lives"][0]["temperature"].as<short int>();
			strcpy(zone,doc["lives"][0]["city"]);
			strcpy(DayWeather,doc["lives"][0]["weather"]);
			strcpy(windir,doc["lives"][0]["winddirection"]);
			*windpower = doc["lives"][0]["windpower"].as<short>();
			*humidity = doc["lives"][0]["humidity"].as<short>();
			
/*

			if(DayWeather=="晴")
			{
				Serial.printf("当光茫洒向开阔之地,我不能直视白色bridge\r\n",DayWeather);
			}
				else if(DayWeather=="阴")
				{
					Serial.printf("*看来今天应该不会下雨呢\r\n",DayWeather);
				}
				else if(DayWeather=="小雨")
				{
					Serial.printf("没带伞跑个两步应该没什么问题\r\n",DayWeather);
				}
				else if(DayWeather=="中雨")
				{
					Serial.printf("哼？想跑？吔我饱和打击啦\r\n",DayWeather);
				}
				else if(DayWeather=="大雨")
				{
					Serial.printf("这下成落汤鸡了\r\n",DayWeather);
				}
				else if(DayWeather=="暴雨")
				{
					Serial.printf("谁说白天不懂夜的黑,起床看了下时间,原来是中午12点\r\n",DayWeather);
				}
				else if(DayWeather=="特大暴雨")
				{
					Serial.printf("这天气都不放假？噢~原来是大学生啊\r\n",DayWeather);
				}
				else if(DayWeather=="阵雨")
				{
					Serial.printf("太阳觉得太热了,于是它开始流汗\r\n",DayWeather);
				}
				else if(DayWeather=="热带风暴")
				{
					Serial.printf("走,出门兜风,吃不了兜着走的兜\r\n",DayWeather);
				}
				else
				{
					Serial.printf("不算好天气，但是好心情",DayWeather);
				}*/
    
		}

	}
	else
	{
		Serial.printf("HTTP Get Error: %s\n", http.errorToString(httpCode).c_str());
	}

	http.end();
}