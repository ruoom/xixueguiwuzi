#pragma once


class archer {
public:
	void born() {};      //������ �������Գ�ʼ��
	void shoot() {};     //�������
	void die() {};       //��������
private:
	int moveGroundStep;  //����ÿ�ο���·�ĸ���
	int moveGrassStep;   //����ÿ�ο��߲�ƺ����
	int arrowAmount;     //�����ֵĹ�������
	int arrowDistance;   //�������
	int arrowProDistance;//��ʯ��ǿ��Ĺ������

};