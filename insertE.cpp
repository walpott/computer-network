#include "pch.h"
#include"picture.h"
#include <iostream>

void Graph::InsertE()//插入边
{
	cout << "添加边：请依次输入顶点1 顶点2  权值：";
	int temp;
	char temprouter1;
	char temprouter2;
	cin >> temprouter1;
	cin >> temprouter2;
	cin >> temp;
	int v1 = getVPos(temprouter1);
	int v2 = getVPos(temprouter2);
	cout << v1 << "  " << v2 << "  " << numV << endl;
	if ((v1 > -1 && v1 < numV) && (v2 > -1 && v2 < numV))//两个顶点是否都在
	{

		Edge[v1][v2] = Edge[v2][v1] = temp;
		//若为有向图，则去掉另一条边
		numE++;
		cout << "--------边添加成功-----------" << endl;
	}

}