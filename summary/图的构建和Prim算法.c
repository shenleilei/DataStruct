#pragma warning(disable:4996)
#define MAXINT 9999
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
typedef struct{
	int weight;//adj�Ƕ���֮��Ĺ�ϵ������Ȩͼ����0,1��ʾ�Ƿ����ڣ���Ȩͼ��ʾ֮���Ȩ�ع�ϵ
	char* info;//�����ߵ�����������Ϣ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	char vexs[MAX_VERTEX_NUM];//���涥����Ϣ
	AdjMatrix arcs;
	int vertexnum;//������Ŀ
	int arcnum;  //�ߵ���Ŀ��
}Mgraph;

//visited ���ʹ��Ľڵ�
typedef struct{
	int length;
	int i, j;//i,j��ʾ��¼ǰһ���Ѿ�������ʱ��Сֵ����������б������С��ֵ�͸�������
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
	printf("���붥����Ŀ�� ");
	scanf("%d", &(*graph).vertexnum);
	printf("����ߵ���Ŀ�� ");
	scanf("%d", &(*graph).arcnum);
	char tmp;
	scanf("%c", &tmp);
	//���붥�����Ϣabcde...
	printf("���붥����Ϣ�� ");
	for (int i = 0; i < (*graph).vertexnum; i++) scanf("%c", &((*graph).vexs[i]));
	//��ʼ���ߵ���Ϣ
	Init(graph);
	//����ߵ���Ϣ
	for (int k = 0; k < (*graph).arcnum; k++) {
		char V1, V2; int weight;
		printf("һ���ߺ�����ֱ�ӵ�Ȩ�أ� ");
		char tmp;
		scanf("%c", &tmp);
		scanf("%c", &V1);	scanf("%c", &V2); scanf("%d", &weight);
		int i = Locate((*graph), V1); int j = Locate((*graph), V2);
		(*graph).arcs[i][j].weight = weight;
		(*graph).arcs[j][i].weight = weight;
	}
}

//ɾȥ�ַ������еĵ�һ��Ԫ��
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

//Prim�㷨
Prim(Mgraph graph) {
	Visited nonvisited;
	//length1��ʼ����
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






