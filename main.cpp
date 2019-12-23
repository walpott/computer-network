#include "pch.h"
#include "picture.h"
#include "router.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

int main()
{
	int check;
	char ch;
	Graph G;
	Router R;
	cout << "欢迎来到路由表生成程序！" << endl;
	cout << "请先录入网络拓扑信息：" << endl;
	cout << "1、文件生成" << endl;
	cout << "2、手动生成" << endl;
	cin >> check;
	if (check == 1)
		G.createbyfile();
	else
		if (check == 2)
		{
			while (1)//插入节点
			{
				char ch;
				cout << "请问你想插入新的路由器吗？（y或n）" << endl;
				cin >> ch;
				if (ch == 'n')
					break;
				G.InsertV();
				cin.get();
				system("cls");
			}
			int m = G.getnumV();
			for (int i = 0; i < m*(m - 1) / 2; i++)//插入边
			{
				char ch;
				cout << "请问你想插入新的边吗？（y或n）" << endl;
				cin >> ch;
				if (ch == 'n')
					break;
				G.InsertE();
				cin.get();
				system("cls");
			}
		}
		else
			return -1;
	next:
	cout << "请给出一个路由器的名字，系统将根据该名字生成一个路由表：" << endl;
	cin >> ch;
	char c = ch;
	if (!R.Dijkstra(G, ch))
	{
		cout << "没有查到该路由器！" << endl;
		system("pause");
		system("cls");
		goto next;
	}
	R.tablecreate(G,ch);
	system("cls");
	while (1)
	{
		cout << "接下来可以输入数字进行相应的操作：\n1、更换路由器\n2、添加边\n3、添加点\n";
		cout << "4、删除边\n5、删除点\n6、输出拓扑图\n7、输出路由表\n（按其他任意键可以退出）\n";
		cin >> check;
		if (check == 1)
		{
			cout << "输入路由器：" << endl;
			cin >> c;
			if (!R.Dijkstra(G, ch))
			{
				cout << "没有查到该路由器！" << endl;
				system("pause");
				system("cls");
				continue;
			}
			R.tablecreate(G, c);
			cout << "更改成功！(按任意键退出)" << endl;
			system("pause");
			system("cls");
		}
		else
			if (check == 2)
			{
				G.InsertE();
				R.Dijkstra(G, ch);
				R.tablecreate(G, ch);
				cout << "更改成功！(按任意键退出)" << endl;
				system("pause");
				system("cls");
			}
			else
				if (check == 3)
				{
					G.InsertV();
					R.Dijkstra(G, ch);
					R.tablecreate(G, ch);
					cout << "更改成功！(按任意键退出)" << endl;
					system("pause");
					system("cls");
				}
				else
					if (check == 4)
					{
						G.removeE();
						R.Dijkstra(G, ch);
						R.tablecreate(G, ch);
						cout << "更改成功！(按任意键退出)" << endl;
						system("pause");
						system("cls");
					}
					else
						if (check == 5)
						{
							if (G.removeV() == ch)
							{
								cout << "删除的是自己的路由器，" << endl;
								goto next;
							}
							R.Dijkstra(G, ch);
							R.tablecreate(G, ch);
							cout << "更改成功！(按任意键退出)" << endl;
							system("pause");
							system("cls");
						}
						else
							if (check == 6)
							{
								G.outV();
								G.outEdge();
								cout << "按任意键退出" << endl;
								system("pause");
								system("cls");
							}
							else
								if (check == 7)
								{
									int v = G.getVPos(c);
									R.show(v);
									cout << "按任意键退出" << endl;
									system("pause");
									system("cls");
								}
								else
									break;
	}
	return 0;
}