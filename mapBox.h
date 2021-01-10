#pragma once

class mapBox {
public:
	mapBox()
	{
		x = 0; y = 0;
		isGem = 0;//默认无宝石
	}
	mapBox(int X,int Y)
	{
		x = X;
		y = Y;
	}
	void setPos(int X, int Y)
	{
		x = X;
		y = Y;
	}

	void setType(int type) { bosType = type; }

	int getX() { return x; }
	int getY() { return y; }
	//源
	void makeVampire() {}; //产生吸血鬼
	
	//基地
	void boom() {}; //基地爆炸
private:
	int x, y;      //自身坐标
	int bosType;   //方格类型 1：路； 2：草； 4:源
				   //       3：石头(障碍物)；5:基地
	bool isGem;     //此格是否有宝石
	
	/*    源    */
	int sourceVampireAmount; //若是源 产生的吸血鬼最大数量
	int madeVampireAmount;   //已产生的吸血鬼数量
	/*    源    */


};