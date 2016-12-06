// 图.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "conio.h"
#define vertexnum 100       //定义最大可输入的结点个数
#define QueueMax  100

using namespace std;
typedef struct  node        //定义图形的顶点结构 
{
	int  vertex;             //图中的顶点信息为数字
	struct  node  *next;
}Graph;
Graph head[vertexnum];      //邻接表的表头结点
int Visited[vertexnum];     //遍历记录
int Front = -1;
int Rear = -1;
int Queue[QueueMax];
void initqueue()
{

	Front = Rear = -1;
}
int emptyqueue()
{
	if (Front >= Rear)       //队列已满
		return 1;
	else
		return 0;
}
int Enqueue(int Vertex)       //元素入队
{
	if (Rear >= QueueMax)       //队列已满
		return 0;
	else
	{
		Rear++;               //队列尾端指针后移
		Queue[Rear] = Vertex;   //将值存入队列中
		return 1;
	}
}
int Dequeue()                //元素出队
{
	if (Front >= Rear)          //队列已空
		return -1;
	else
	{
		Front++;              //队头指针后移
		return Queue[Front];
	}
}

void BFS(int Vertex)//广度优先搜索
{
	int i, k;
	int Quene[QueueMax];
	int Front = -1;
	int Rear = -1;
	Graph *p; //*p,*q; 
	initqueue();
	Visited[Vertex] = 1;
	cout << head[Vertex].vertex << endl;
	Enqueue(head[Vertex].vertex);//进队列
	while (!(emptyqueue()))
	{
		k = Dequeue();//出队
		p = head[k].next;
		while (p != NULL)
		{
			if (Visited[p->vertex] == 0)
			{
				Visited[p->vertex] = 1;
				cout << p->vertex << endl;
				Enqueue(p->vertex); //进队列
			}
			p = p->next;

		}

	}
}
void Create_l_Graph(int Vertex1, int Vertex2, int no)
{                      //以邻接链表建立图形
	Graph  *searchP;     //结点声明
	Graph  *New;         //新结点声明 
	New = (Graph *)malloc(sizeof(struct node));
	if (New != NULL)
	{
		New->vertex = Vertex2;
		New->next = NULL;
		searchP = &(head[Vertex1]);
		while (searchP->next != NULL)
			searchP = searchP->next;
		searchP->next = New;
		if (no == 0)
		{
			New = (Graph *)malloc(sizeof(struct node));
			New->vertex = Vertex1;
			New->next = NULL;
			searchP = &(head[Vertex2]);
			while (searchP->next != NULL)
				searchP = searchP->next;
			searchP->next = New;
		}
	}
}
void showmenu()
{                   //显示菜单
	cout << "    欢迎使用图的操作演示软件\n";
	cout << "\t1、创建图的邻接表\n";
	cout << "\t2、图的输出\n";
	cout << "\t3、图的广度优先遍历\n";
	cout << "\t4、退出程序\n";
}

void print_l_graph(Graph *head)
{                     //输出邻接链表的数据
	Graph  *searchP;
	searchP = head->next;
	while (searchP != NULL)
	{
		cout << searchP->vertex;
		searchP = searchP->next;
	}
	cout << endl;

}

void main()
{
	int source;           //图中一条边的起始顶点
	int destination;      //图中一条边的终止顶点
	int i, j;
	int vermax;           //定义图中最大的顶点数
	int edgemax;          //定义图中最大的边数
	int choice;
	int no;

	while (1)
	{
		system("title 图程序");
		system("color f0");
		showmenu();
		cout << "   请输入你的选择：" << endl;
		cin >> choice;
		fflush(stdin);//清除键盘缓冲区
		switch (choice)
		{
		case 1:
			cout << "请输入图的类别（有向图-1，无向图-0）:" << endl;
			cin >> no;
			cout << "请输入图中的总顶点数和边数:" << endl;
			cin >> vermax >> edgemax;
			for (i = 1;i <= vermax;i++)
			{
				head[i].vertex = i;
				head[i].next = NULL;
			}
			for (i = 1;i <= edgemax;i++)
			{
				cout << "请输入第" << i << "条边的起点：" << endl;
				cin >> source;
				cout << "请输入第" << i << "条边的终点：" << endl;
				cin >> destination;
				if (source == destination)
					cout << "输入有误！\n";//出错：自身循环
				else                 //调用建立邻接链表
					Create_l_Graph(source, destination, no);
			}
			cout << "图创建成功，按任意键继续…\n";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "图的邻接表如下：\n";
			for (i = 1;i <= vermax;i++)
			{
				cout << "顶点" << i;
				print_l_graph(&head[i]);//调用输出邻接链表数据
			}
			cout << "\n";
			system("pause");
			system("cls");
			break;
		case 3:
			for (i = 1;i <= vermax;i++)
				Visited[i] = 0;
			cout << "请输入遍历的起点:" << endl;;
			cin >> source;
			cout << "图的广度优先遍历结果为：\n";
			BFS(source);
			for (i = 1;i <= vermax;i++)
			{
				if (Visited[i] == 0)
					BFS(i);
			}

			cout << "END\n";
			system("pause");
			system("cls");
			break;
		case 4:return;
		default:
			cout << "你的输入有误，请从新输入！\n";
			system("pause");
			system("cls");
		}
	}
}
