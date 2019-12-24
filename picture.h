#ifndef PICTURE_H
#define PICTURE_H

using namespace std;

struct V//点结构
{
	int router;//路由器名
	int ip[4];//ip地址，10进制表示
};

class Graph
{
	int maxV;//最大节点数
	int numV;//当前节点数
	int numE;//当前边数
	V*Vdge;//顶点表
	int**Edge;//邻接矩阵
	

public:
	Graph();
	void InsertV();//插入点（路由器）
	void InsertE();//插入边
	void removeE();//删除边
	char removeV();//删除点
	void createbyfile();//文件输入

	int getVPos(int vertex); //给出顶点vertex在图中的位置
	void getrouter(int v,int*table);//返回路由表ip地址到数组table中
	int getnumV();//返回节点数
	int getcost(int m, int n);//返回边值

	friend class Router;
	void outEdge();
	void outV();

	
};



#endif

