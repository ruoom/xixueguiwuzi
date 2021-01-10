#pragma once
#include "mapBox.h"
//#include "gameElement.h"
#include <vector>
#include "tools.h"

class map {
public:
	map(FILE* fp)//���������ļ�
	{
		if (!fp)
		{
			//map
			mapLong = 16;
			mapHigh = 16;
			sourcePos.push_back(point(2, 2));
			//grassPos.push_back{ (point(1, 1)),(point(2, 1)) };
			homePos.push_back(point(10, 10));
			MapBox = new mapBox * [mapLong];
			for (int j = 0; j < mapLong; ++j)
			{
				MapBox[j] = new mapBox[mapHigh];
				for (int i = 0; i < mapHigh; ++i)
					MapBox[j][i].setPos(j, i);
			}

			MapBox[(*sourcePos.begin()).x]
				[(*sourcePos.begin()).y].setType(4);

			//vampire


		}






	}; //��ʼ����ͼ

	mapBox box(int x,int y)
	{
		return MapBox[x][y];
	}

	int Long()
	{
		return mapLong;
	}
	int High()
	{
		return mapHigh;
	}

private:
	int mapLong;    //��ͼ����
	int mapHigh;    //��ͼ�߶�
	std::vector<point> sourcePos;
	std::vector<point> grassPos;
	std::vector<point> homePos;
	mapBox** MapBox; //����

};