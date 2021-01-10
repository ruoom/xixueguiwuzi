#pragma once


class archer {
public:
	void born() {};      //弓箭手 各项属性初始化
	void shoot() {};     //射箭动作
	void die() {};       //死亡动作
private:
	int moveGroundStep;  //射手每次可走路的格数
	int moveGrassStep;   //射手每次可走草坪格数
	int arrowAmount;     //弓箭手的弓箭数量
	int arrowDistance;   //弓箭射程
	int arrowProDistance;//宝石增强后的弓箭射程

};