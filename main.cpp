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
	cout << "��ӭ����·�ɱ����ɳ���" << endl;
	cout << "����¼������������Ϣ��" << endl;
	cout << "1���ļ�����" << endl;
	cout << "2���ֶ�����" << endl;
	cin >> check;
	if (check == 1)
		G.createbyfile();
	else
		if (check == 2)
		{
			while (1)//����ڵ�
			{
				char ch;
				cout << "������������µ�·�����𣿣�y��n��" << endl;
				cin >> ch;
				if (ch == 'n')
					break;
				G.InsertV();
				cin.get();
				system("cls");
			}
			int m = G.getnumV();
			for (int i = 0; i < m*(m - 1) / 2; i++)//�����
			{
				char ch;
				cout << "������������µı��𣿣�y��n��" << endl;
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
	cout << "�����һ��·���������֣�ϵͳ�����ݸ���������һ��·�ɱ�" << endl;
	cin >> ch;
	char c = ch;
	if (!R.Dijkstra(G, ch))
	{
		cout << "û�в鵽��·������" << endl;
		system("pause");
		system("cls");
		goto next;
	}
	R.tablecreate(G,ch);
	system("cls");
	while (1)
	{
		cout << "�����������������ֽ�����Ӧ�Ĳ�����\n1������·����\n2����ӱ�\n3����ӵ�\n";
		cout << "4��ɾ����\n5��ɾ����\n6���������ͼ\n7�����·�ɱ�\n������������������˳���\n";
		cin >> check;
		if (check == 1)
		{
			cout << "����·������" << endl;
			cin >> c;
			if (!R.Dijkstra(G, ch))
			{
				cout << "û�в鵽��·������" << endl;
				system("pause");
				system("cls");
				continue;
			}
			R.tablecreate(G, c);
			cout << "���ĳɹ���(��������˳�)" << endl;
			system("pause");
			system("cls");
		}
		else
			if (check == 2)
			{
				G.InsertE();
				R.Dijkstra(G, ch);
				R.tablecreate(G, ch);
				cout << "���ĳɹ���(��������˳�)" << endl;
				system("pause");
				system("cls");
			}
			else
				if (check == 3)
				{
					G.InsertV();
					R.Dijkstra(G, ch);
					R.tablecreate(G, ch);
					cout << "���ĳɹ���(��������˳�)" << endl;
					system("pause");
					system("cls");
				}
				else
					if (check == 4)
					{
						G.removeE();
						R.Dijkstra(G, ch);
						R.tablecreate(G, ch);
						cout << "���ĳɹ���(��������˳�)" << endl;
						system("pause");
						system("cls");
					}
					else
						if (check == 5)
						{
							if (G.removeV() == ch)
							{
								cout << "ɾ�������Լ���·������" << endl;
								goto next;
							}
							R.Dijkstra(G, ch);
							R.tablecreate(G, ch);
							cout << "���ĳɹ���(��������˳�)" << endl;
							system("pause");
							system("cls");
						}
						else
							if (check == 6)
							{
								G.outV();
								G.outEdge();
								cout << "��������˳�" << endl;
								system("pause");
								system("cls");
							}
							else
								if (check == 7)
								{
									int v = G.getVPos(c);
									R.show(v);
									cout << "��������˳�" << endl;
									system("pause");
									system("cls");
								}
								else
									break;
	}
	return 0;
}