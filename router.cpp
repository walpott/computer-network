﻿
#include "pch.h"
#include"router.h"
#include <iostream>

const int maxsize = 20;
const int maxValue = 999;

using namespace std;

Router::Router()
{
	tablesize = 0;
	path = new int[maxsize];
	dist = new  int[maxsize];
	table = new router[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		path[i] = -1;
		dist[i] = -1;
	}
}



void Router::tablecreate(Graph& G,char ch)
{
	cout << "何治霖" << endl;
	tablesize = 0;
	int v = G.getVPos(ch);
	for (int i = 0; i < G.getnumV(); i++)//依次键表
	{
		tablesize++;
		int u = i;//临时变量，用于读取和判定
		if (i != v)//如果目的地址不是本身
		{
			G.getrouter(i,table[i].address);
			while (1)
			{
				if (path[u] == -1)//如果要到u点的上一跳是v
				{
					G.getrouter(u, table[i].next);
					break;
				}
				else
					u = path[u];//变为上一跳
			}
		}
		else
		{
			table[v].address[0] = G.Vdge[v].ip[0];
			table[v].next[0] = G.Vdge[v].ip[0];
		}
	}
}

void Router::show(int v)
{
	int c = tablesize;
	cout << "地址\t\t下一跳" << endl;
	for (int i = 0; i < c; i++)
	{
		if (dist[i] != 999)
		{
			cout << table[i].address[0] << ".0.0.0" << "\t\t";
			cout << table[i].next[0] << ".0.0.0" << endl;
		}
	}
	cout<<"默认\t\t"<<table[v].address[0]<< ".0.0.0" << endl;
}