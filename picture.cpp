#include "pch.h"
#include"picture.h"
#include <iostream>
#include <fstream>

Graph::Graph()//最多10个顶点
{
	maxV = 15;
	numV = 0;
	Vdge = new V[15];
	Edge = new int*[15];
	for (int i = 0; i < maxV; i++)
	{
		Vdge[i].router = '#';
		Edge[i] = new int[maxV];
	}
	for (int i = 0; i < maxV; i++) //邻接矩阵初始化
		for (int j = 0; j < maxV; j++)
			Edge[i][j] = (i == j) ? 0 : 999;
}



void Graph::outEdge()//输出邻接矩阵
{
	for (int i = 0; i < numV; i++)
	{
		for (int j = 0; j < numV; j++)
			cout << Edge[i][j] << "\t";
		cout << "" << endl;
	}
}

void Graph::outV()//输出顶点数组
{
	for (int i = 0; i < numV; i++)
		cout << Vdge[i].router<<"  "<<Vdge[i].ip[0] << Vdge[i].ip[1] << Vdge[i].ip[2] << Vdge[i].ip[3] << endl;
}

int Graph::getnumV()//图里的点数
{
	return numV;
}

int Graph::getcost(int m, int n)//两点间的权值
{
	return Edge[m][n];
}

int Graph::getVPos(int vertex)//给出顶点vertex在图中的位置
{
	for (int i = 0; i < numV; i++)
		if (Vdge[i].router == vertex) return i;
	return -1;
}
void Graph::getrouter(int v,int*name)
{
	for (int i = 0; i < 4; i++)
		name[i] = Vdge[v].ip[i];
}

void Graph::createbyfile()
{
	ifstream fin1("Node.txt");
	ifstream fin2("edge.txt");

	int i = 0;
	do
	{
		fin1 >> Vdge[i].router;
		for (int j = 0; j < 4; j++)
			fin1 >> Vdge[i].ip[j];
		i++;
		numV++;
	} while (fin1.get() != EOF);
	i = 0;
	do
	{
		int p, q;
		fin2 >> p >> q;	
		int a = getVPos(p); 
		int b = getVPos(q);
		fin2 >> Edge[a][b];
		Edge[b][a] = Edge[a][b];
		numE++;
	} while (fin2.get() != EOF);
	fin1.close();
	fin1.clear();
	fin2.close();
	fin2.clear();
}