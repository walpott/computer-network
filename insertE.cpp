#include "pch.h"
#include"picture.h"
#include <iostream>

void Graph::InsertE()//�����
{
	cout << "��ӱߣ����������붥��1 ����2  Ȩֵ��";
	int temp;
	char temprouter1;
	char temprouter2;
	cin >> temprouter1;
	cin >> temprouter2;
	cin >> temp;
	int v1 = getVPos(temprouter1);
	int v2 = getVPos(temprouter2);
	cout << v1 << "  " << v2 << "  " << numV << endl;
	if ((v1 > -1 && v1 < numV) && (v2 > -1 && v2 < numV))//���������Ƿ���
	{

		Edge[v1][v2] = Edge[v2][v1] = temp;
		//��Ϊ����ͼ����ȥ����һ����
		numE++;
		cout << "--------����ӳɹ�-----------" << endl;
	}

}