// ͼ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "stdlib.h"
#include "conio.h"
#define vertexnum 100       //������������Ľ�����
#define QueueMax  100

using namespace std;
typedef struct  node        //����ͼ�εĶ���ṹ 
{
	int  vertex;             //ͼ�еĶ�����ϢΪ����
	struct  node  *next;
}Graph;
Graph head[vertexnum];      //�ڽӱ�ı�ͷ���
int Visited[vertexnum];     //������¼
int Front = -1;
int Rear = -1;
int Queue[QueueMax];
void initqueue()
{

	Front = Rear = -1;
}
int emptyqueue()
{
	if (Front >= Rear)       //��������
		return 1;
	else
		return 0;
}
int Enqueue(int Vertex)       //Ԫ�����
{
	if (Rear >= QueueMax)       //��������
		return 0;
	else
	{
		Rear++;               //����β��ָ�����
		Queue[Rear] = Vertex;   //��ֵ���������
		return 1;
	}
}
int Dequeue()                //Ԫ�س���
{
	if (Front >= Rear)          //�����ѿ�
		return -1;
	else
	{
		Front++;              //��ͷָ�����
		return Queue[Front];
	}
}

void BFS(int Vertex)//�����������
{
	int i, k;
	int Quene[QueueMax];
	int Front = -1;
	int Rear = -1;
	Graph *p; //*p,*q; 
	initqueue();
	Visited[Vertex] = 1;
	cout << head[Vertex].vertex << endl;
	Enqueue(head[Vertex].vertex);//������
	while (!(emptyqueue()))
	{
		k = Dequeue();//����
		p = head[k].next;
		while (p != NULL)
		{
			if (Visited[p->vertex] == 0)
			{
				Visited[p->vertex] = 1;
				cout << p->vertex << endl;
				Enqueue(p->vertex); //������
			}
			p = p->next;

		}

	}
}
void Create_l_Graph(int Vertex1, int Vertex2, int no)
{                      //���ڽ�������ͼ��
	Graph  *searchP;     //�������
	Graph  *New;         //�½������ 
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
{                   //��ʾ�˵�
	cout << "    ��ӭʹ��ͼ�Ĳ�����ʾ���\n";
	cout << "\t1������ͼ���ڽӱ�\n";
	cout << "\t2��ͼ�����\n";
	cout << "\t3��ͼ�Ĺ�����ȱ���\n";
	cout << "\t4���˳�����\n";
}

void print_l_graph(Graph *head)
{                     //����ڽ����������
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
	int source;           //ͼ��һ���ߵ���ʼ����
	int destination;      //ͼ��һ���ߵ���ֹ����
	int i, j;
	int vermax;           //����ͼ�����Ķ�����
	int edgemax;          //����ͼ�����ı���
	int choice;
	int no;

	while (1)
	{
		system("title ͼ����");
		system("color f0");
		showmenu();
		cout << "   ���������ѡ��" << endl;
		cin >> choice;
		fflush(stdin);//������̻�����
		switch (choice)
		{
		case 1:
			cout << "������ͼ���������ͼ-1������ͼ-0��:" << endl;
			cin >> no;
			cout << "������ͼ�е��ܶ������ͱ���:" << endl;
			cin >> vermax >> edgemax;
			for (i = 1;i <= vermax;i++)
			{
				head[i].vertex = i;
				head[i].next = NULL;
			}
			for (i = 1;i <= edgemax;i++)
			{
				cout << "�������" << i << "���ߵ���㣺" << endl;
				cin >> source;
				cout << "�������" << i << "���ߵ��յ㣺" << endl;
				cin >> destination;
				if (source == destination)
					cout << "��������\n";//��������ѭ��
				else                 //���ý����ڽ�����
					Create_l_Graph(source, destination, no);
			}
			cout << "ͼ�����ɹ����������������\n";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "ͼ���ڽӱ����£�\n";
			for (i = 1;i <= vermax;i++)
			{
				cout << "����" << i;
				print_l_graph(&head[i]);//��������ڽ���������
			}
			cout << "\n";
			system("pause");
			system("cls");
			break;
		case 3:
			for (i = 1;i <= vermax;i++)
				Visited[i] = 0;
			cout << "��������������:" << endl;;
			cin >> source;
			cout << "ͼ�Ĺ�����ȱ������Ϊ��\n";
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
			cout << "�������������������룡\n";
			system("pause");
			system("cls");
		}
	}
}
