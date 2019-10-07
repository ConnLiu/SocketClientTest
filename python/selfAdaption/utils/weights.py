"""
    double pena_max_latg;  //最大横Gに対するコスト                        default: 2.5
    double pena_latg;      //横Gが制限を超えている場合のコスト             default: 60
    double pena_spd;       //速度が制限を超えている場合のコストP104        default: 30
    double pena_a_max;    //最大加速度が制限を超えている場合のコスト       defualt:  50
    double pena_a_min;    //最小加速度が制限を超えている場合のコスト       default: 50
    double pena_curv_rate;//曲率変化率が制限を超えている場合のコスト       default: 20
    double dynamic_obstacle_lethal_cost; //移動物にぶつかる場合のコスト   default: INF_COST
	double dynamic_obstacle_high_cost; //移動物近くを通るコスト	　　　　 default: 500;
 
    double latg_max_soft;  //乗り心地を考えた横G制限値[m/s^2]             default: 0.3*9.8                    
    double curve_rate_limit; //曲率変化率の制限値　　　　　　　　　　　　　default: 20.0

"""
import json

class Weights:

    def __init__(self, value):
        self.pena_max_latg = value
        self.pena_latg = value
        self.pena_spd = value
        self.pena_a_max = value
        self.pena_a_min = value
        self.pena_curv_rate = value
        self.dynamic_obstacle_lethal_cost = value
        self.dynamic_obstacle_high_cost = value
    def getAllStruct(self):
        return (self.pena_max_latg, self.pena_latg,
        self.pena_spd, self.pena_a_max,
        self.pena_a_min,self.pena_curv_rate,
        self.dynamic_obstacle_lethal_cost,
        self.dynamic_obstacle_high_cost)
    def getJson(self):
        return json.dumps(self.__dict__)

