#pragma once
#include<string>

class vampire {
public:
	void born() {};    //吸血鬼出生 属性初始化
	void move() {};    //吸血鬼移动
	void die() {};     //吸血鬼死亡
	
private:
	int lifePoint;     //吸血鬼生命值
	std::string name;  //吸血鬼名称


};