#include "pch.h"
#include"picture.h"
#include <iostream>

char Graph::removeV()//��ͼ��ɾȥ����v�Լ���������������ı�
{
	cout << "���붥��ɾ��";
	char temp;
	cin >> temp;
	int v = getVPos(temp);

	if (v < 0 || v >= numV)
		cout << "---------------v����ͼ�У���ɾ��-----------------" << endl; //v����ͼ�У���ɾ��
	else if (numV == 1)
		cout << "--------------ֻʣһ�����㣬��ɾ��---------------" << endl;
	else
	{
		int i, j;
		Vdge[v] = Vdge[numV - 1];//�������ɾ���ý�㣬�����һ���������v������
		for (i = 0; i < numV; i++) //��ȥ��v���������
			if (Edge[i][v] > 0 && Edge[i][v] < 999)
				numE--;
		for (i = 0; i < numV; i++) //�����һ�����v��
			Edge[i][v] = Edge[i][numV - 1];

		for (j = 0; j < numV; j++) //�����һ�����v��
			Edge[v][j] = Edge[numV - 1][j];
		numV--; //��������1
		cout << "----------�ɹ�ɾ����----------" << endl;
	}
	return temp;
}