#include "pch.h"
#include"picture.h"
#include <iostream>

void Graph::InsertV()//�����
{
	cout << "����㣺(��������·���������Ķ�IP��ַ)";
	int temp;
	cin >> temp;
	if (numV == maxV)
		cout << "---------�����Ѿ���󣬲����ʧ��------------";
	else
	{
		Vdge[numV].router = temp;
		for (int i = 0; i < 4; i++)
			cin >> Vdge[numV].ip[i];
		numV++;
		cout << "--------------����ɹ�--------" << endl;
	}
}