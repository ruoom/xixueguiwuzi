#pragma once

class mapBox {
public:
	mapBox()
	{
		x = 0; y = 0;
		isGem = 0;//Ĭ���ޱ�ʯ
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
	//Դ
	void makeVampire() {}; //������Ѫ��
	
	//����
	void boom() {}; //���ر�ը
private:
	int x, y;      //��������
	int bosType;   //�������� 1��·�� 2���ݣ� 4:Դ
				   //       3��ʯͷ(�ϰ���)��5:����
	bool isGem;     //�˸��Ƿ��б�ʯ
	
	/*    Դ    */
	int sourceVampireAmount; //����Դ ��������Ѫ���������
	int madeVampireAmount;   //�Ѳ�������Ѫ������
	/*    Դ    */


};