#include "gameElement.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>


void gameInit()
{
	//FILE* fp;
	//fopen_s(&fp, "1.txt", "w");
	FILE* fp;
	int err = 0;
	err = fopen_s(&fp, "Default.ini", "r");
	if (!err)
	{
		map* Map = new map(fp);   //��ʼ����ͼ	
	}
	else
	{
		map* Map = new map(NULL);
	}
	//fprintf(fp,"��6�е�2�� x=%d,y=%d",Map->box(2,6).getX(), 
	//	Map->box(2, 6).getY());
	//fclose(fp);
	config a;
	a.wIni();
}