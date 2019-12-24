#ifndef ROUTER_H_
#define ROUTER_H_

#include "picture.h"

typedef struct router
{
	int address[4];
	int next[4];
	router()
	{
		for (int i = 0; i < 4; i++)
		{
			address[i] = 0;
			next[i] = 0;
		}
	}
}router;


class Router
{
public:
	Router();
	bool Dijkstra(Graph& G, int ch);
	void tablecreate(Graph& G, char ch);
	void show(int v);
private:
	int tablesize;
	int* path;
	int* dist;
	router* table;
};

#endif