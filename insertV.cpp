#include "pch.h"
#include"picture.h"
#include <iostream>

void Graph::InsertV()//插入点
{
	cout << "输入点：(依次输入路由器名，四段IP地址)";
	int temp;
	cin >> temp;
	if (numV == maxV)
		cout << "---------点数已经最大，插入点失败------------";
	else
	{
		Vdge[numV].router = temp;
		for (int i = 0; i < 4; i++)
			cin >> Vdge[numV].ip[i];
		numV++;
		cout << "--------------插入成功--------" << endl;
	}
}