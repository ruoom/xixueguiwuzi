#pragma once
#include<string>

class vampire {
public:
	void born() {};    //��Ѫ����� ���Գ�ʼ��
	void move() {};    //��Ѫ���ƶ�
	void die() {};     //��Ѫ������
	
private:
	int lifePoint;     //��Ѫ������ֵ
	std::string name;  //��Ѫ������


};