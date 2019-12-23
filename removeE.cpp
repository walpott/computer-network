#include "pch.h"
#include"picture.h"
#include <iostream>

void Graph::removeE()//删除两个点间的边
{
	cout << "依此输入边的两个顶点：";
	char v11, v22;
	cin >> v11 >> v22;
	int v1, v2;
	v1 = getVPos(v11);
	v2 = getVPos(v22);
	if (v1 > -1 && v1 < numV && v2 > -1 && v2 < numV)
	{
		Edge[v1][v2] = Edge[v2][v1] = 999;
		numE--;
		cout << "----------------成功删除边----------------" << endl;
	}
	else
		cout << "---------------删除边失败--------------" << endl;
}