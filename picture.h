#ifndef PICTURE_H
#define PICTURE_H

using namespace std;

struct V//��ṹ
{
	int router;//·������
	int ip[4];//ip��ַ��10���Ʊ�ʾ
};

class Graph
{
	int maxV;//���ڵ���
	int numV;//��ǰ�ڵ���
	int numE;//��ǰ����
	V*Vdge;//�����
	int**Edge;//�ڽӾ���
	

public:
	Graph();
	void InsertV();//����㣨·������
	void InsertE();//�����
	void removeE();//ɾ����
	char removeV();//ɾ����
	void createbyfile();//�ļ�����

	int getVPos(int vertex); //��������vertex��ͼ�е�λ��
	void getrouter(int v,int*table);//����·�ɱ�ip��ַ������table��
	int getnumV();//���ؽڵ���
	int getcost(int m, int n);//���ر�ֵ

	friend class Router;
	void outEdge();
	void outV();

	
};



#endif

