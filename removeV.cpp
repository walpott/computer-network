#include "pch.h"
#include"picture.h"
#include <iostream>

char Graph::removeV()//在图中删去顶点v以及所有与它相关联的边
{
	cout << "输入顶点删除";
	char temp;
	cin >> temp;
	int v = getVPos(temp);

	if (v < 0 || v >= numV)
		cout << "---------------v不在图中，不删除-----------------" << endl; //v不在图中，不删除
	else if (numV == 1)
		cout << "--------------只剩一个顶点，不删除---------------" << endl;
	else
	{
		int i, j;
		Vdge[v] = Vdge[numV - 1];//顶点表中删除该结点，用最后一个顶点填补第v个顶点
		for (i = 0; i < numV; i++) //减去与v相关联边数
			if (Edge[i][v] > 0 && Edge[i][v] < 999)
				numE--;
		for (i = 0; i < numV; i++) //用最后一列填补第v列
			Edge[i][v] = Edge[i][numV - 1];

		for (j = 0; j < numV; j++) //用最后一行填补第v行
			Edge[v][j] = Edge[numV - 1][j];
		numV--; //顶点数减1
		cout << "----------成功删除点----------" << endl;
	}
	return temp;
}