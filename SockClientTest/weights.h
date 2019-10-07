#include "include/rapidjson/document.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include <iostream>
using namespace rapidjson;


class Weights{
private:
    double pena_max_latg;  //最大横Gに対するコスト                        default: 2.5
    double pena_a_minpena_latg;      //横Gが制限を超えている場合のコスト             default: 60
    double pena_spd;       //速度が制限を超えている場合のコストP104        default: 30
    double pena_a_max;    //最大加速度が制限を超えている場合のコスト       defualt:  50
    double pena_a_min;    //最小加速度が制限を超えている場合のコスト       default: 50
    double pena_curv_rate;//曲率変化率が制限を超えている場合のコスト       default: 20
    double dynamic_obstacle_lethal_cost; //移動物にぶつかる場合のコスト   default: INF_COST
	double dynamic_obstacle_high_cost; //移動物近くを通るコスト	　　　　 default: 500;
 
 // not use right row
    double latg_max_soft;  //乗り心地を考えた横G制限値[m/s^2]             default: 0.3*9.8                    
    double curve_rate_limit; //曲率変化率の制限値　　　　　　　　　　　　　default: 20.0

public:
    Weights(){

    }
    Weights(const char json[]){
        Document d;
		
        d.Parse(json);
		std::cout << "In weights: " << json << std::endl;
		
		pena_max_latg = d["pena_max_latg"].GetDouble();
		pena_a_minpena_latg = d["pena_a_minpena_latg"].GetDouble();
		pena_spd = d["pena_spd"].GetDouble();
		pena_a_max = d["pena_a_max"].GetDouble();
		pena_a_min = d["pena_a_min"].GetDouble();
		pena_curv_rate = d["pena_curv_rate"].GetDouble();
		dynamic_obstacle_lethal_cost = d["dynamic_obstacle_lethal_cost"].GetDouble();
		dynamic_obstacle_high_cost = d["dynamic_obstacle_high_cost"].GetDouble();


        // 2. 利用 DOM 作出修改。
        //Value& s = d["stars"].GetDouble;
        //s.SetInt(s.GetInt() + 1);
    }

    const char* getJson(){
        Document doc;
		doc.SetObject(); //key-value 相当与map
		//doc.Settvalue();        //数组型 相当与vector
		Document::AllocatorType &allocator=doc.GetAllocator(); //获取分配器
		//2，给doc对象赋值
		doc.AddMember("pena_max_latg", pena_max_latg,allocator);
        doc.AddMember("pena_latg", pena_a_minpena_latg,allocator);
        doc.AddMember("pena_spd", pena_spd,allocator);
        doc.AddMember("pena_a_max", pena_a_max,allocator);
        doc.AddMember("pena_a_min", pena_a_min,allocator);
        doc.AddMember("pena_curv_rate", pena_curv_rate,allocator);
        doc.AddMember("dynamic_obstacle_lethal_cost", dynamic_obstacle_lethal_cost,allocator);
        doc.AddMember("dynamic_obstacle_high_cost", dynamic_obstacle_high_cost,allocator);


        StringBuffer buffer;
		//PrettyWriter<StringBuffer> writer(buffer);  //PrettyWriter是格式化的json，如果是Writer则是换行空格压缩后的json  
		Writer<StringBuffer> writer(buffer);	
		doc.Accept(writer); 
    
        return buffer.GetString();
    }
};