#pragma warning(disable:4996)
#define MAXINT 9999
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
typedef struct{
	int weight;//adj是顶点之间的关系，在无权图中用0,1表示是否相邻，有权图表示之间的权重关系
	char* info;//这条边的其他附带信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	char vexs[MAX_VERTEX_NUM];//保存顶点信息
	AdjMatrix arcs;
	int vertexnum;//顶点数目
	int arcnum;  //边的数目；
}Mgraph;

//visited 访问过的节点
typedef struct{
	int length;
	int i, j;//i,j表示记录前一个已经访问临时最小值，如果后面有比这个更小的值就更新他。
	char vexs[MAX_VERTEX_NUM];
}Visited;

int Locate(Mgraph graph, char V) {
	for (int i = 0; i < graph.vertexnum; i++) {
		if (V == graph.vexs[i]) {
			return i;
		}
	}
}
Init(Mgraph *graph) {
	for (int i = 0; i < (*graph).vertexnum; i++) {
		for (int j = 0; j < (*graph).vertexnum; j++) {
			(*graph).arcs[i][j].weight = MAXINT;
			(*graph).arcs[i][j].info = NULL;
			if (i == j) {
				(*graph).arcs[i][j].weight = 0;
			}
		}
	}
}
Print(Mgraph graph) {
	for (int i = 0; i < graph.vertexnum; i++) {
		for (int j = 0; j < graph.vertexnum; j++) {
			printf("%d  " ,graph.arcs[i][j].weight);
		}
		printf("\n");
	}
}
Create(Mgraph *graph) {
	printf("输入顶点数目： ");
	scanf("%d", &(*graph).vertexnum);
	printf("输入边的数目： ");
	scanf("%d", &(*graph).arcnum);
	char tmp;
	scanf("%c", &tmp);
	//输入顶点的信息abcde...
	printf("输入顶点信息： ");
	for (int i = 0; i < (*graph).vertexnum; i++) scanf("%c", &((*graph).vexs[i]));
	//初始化边的信息
	Init(graph);
	//输入边的信息
	for (int k = 0; k < (*graph).arcnum; k++) {
		char V1, V2; int weight;
		printf("一条边和他们直接的权重： ");
		char tmp;
		scanf("%c", &tmp);
		scanf("%c", &V1);	scanf("%c", &V2); scanf("%d", &weight);
		int i = Locate((*graph), V1); int j = Locate((*graph), V2);
		(*graph).arcs[i][j].weight = weight;
		(*graph).arcs[j][i].weight = weight;
	}
}

//删去字符数组中的第一个元素
DeleteFirstChar(Visited* nonvisited,char m) {
	for (int i = 0; i < (*nonvisited).length; i++) {
		if ((*nonvisited).vexs[i] == m) 
			(*nonvisited).vexs[i] = '\0';
		}
}

FindNext(Visited* visited,Visited* nonvisited,Mgraph graph) {
	int min_weight = MAXINT; char min_i; char min_j;
	for (int i = 0; i < (*visited).length; i++) {
		for (int j = 0; j < graph.vertexnum; j++) {

			if ((*nonvisited).vexs[j] != '\0') {
				if (graph.arcs[i][j].weight < min_weight) {
					min_weight = graph.arcs[i][j].weight;
					min_i = (*visited).vexs[i];
					min_j = (*nonvisited).vexs[j];
				}
			}

		}
	}
	DeleteFirstChar(nonvisited, min_j);
	(*visited).vexs[(*visited).length] = min_j;
	(*visited).length++;
	printf("(%c--->%c)",min_i,min_j);
}

//Prim算法
Prim(Mgraph graph) {
	Visited nonvisited;
	//length1开始计数
	nonvisited.length = 1;
	for (int i = 0; i < graph.vertexnum; i++) {
		nonvisited.vexs[i] = graph.vexs[i];
		nonvisited.length++;
	}
	nonvisited.vexs[0] = '\0';
	Visited visited;
	visited.i = visited.j = 0; visited.length = 0; 
	visited.vexs[visited.length] = graph.vexs[0]; visited.length++;
	for (; visited.length < graph.vertexnum;)
		FindNext(&visited,&nonvisited,graph);
}

int main(void) {
	Mgraph graph;
	Create(&graph);
	Print(graph);
	Prim(graph);
}






