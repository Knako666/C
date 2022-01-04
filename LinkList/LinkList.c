#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0;

typedef int ElemType;

typedef int Status;

typedef struct node{
	ElemType data;	//数据域
	struct node *next; //指针域
}Node, *LinkList;


//函数功能：创建链表(有头结点)
//参数L:链表头指针
LinkList CreatLinkList() {	//头插法
	LinkList L = NULL;
	Node *s;
	ElemType e;
	//创建头结点
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	printf("请输入：\n");
	scanf("%d", &e);
	while (9999 != e){
		s = (Node*)malloc(sizeof(Node));
		s->data = e;
		s->next = L->next;
		L->next = s;
		scanf("%d", &e);
	}
	return L;
}

//函数功能：创建链表(无头结点)
//参数L:链表头指针
LinkList CreatLinkList_NoHead() {	//头插法
	LinkList L = NULL;
	Node *s,*p;
	ElemType e = 0;
	printf("请输入：\n");
	scanf("%d", &e);
	while (9999 != e) {
		s = (Node*)malloc(sizeof(Node));
		s->data = e;
		if (NULL == L)
			L = p = s;
		else
			p->next = s;
		p = s;
		scanf("%d", &e);
	}
	p->next = NULL;
	return L;
}

//函数功能：计算链表表长(带头结点)
//参数L:链表头指针
Status Length(LinkList L) {
	if (!L)
		return FALSE;
	Node *p = L->next;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

//函数功能：删除带头结点链表中值为x的元素（默认不唯一）
//参数L：链表头指针
//参数x：寻找被删除元素的值为x
Status Del_x2(LinkList L, ElemType x) {
	if (!L)
		return FALSE;
	Node *p = L->next, *pre = L, *q;	//从p开始逐一遍历，pre为p的前驱，q用于记录与x相等的元素
	while (p)
	{
		if (x == p->data) {
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return TRUE;
}

//函数功能：删除是s，t区间内的所有元素
//参数L：链表头指针
//参数s：下界
//参数t：上界
Status Del_st(LinkList L, ElemType s, ElemType t) {
	if (!L)
		return FALSE;
	Node *pre = L, *p = L->next, *q;
	while (p)
	{
		if (p->data > s && p->data < t) {
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return TRUE;
}

//函数功能:删除单链表（带头结点）中的最小值结点
//参数L:链表头指针
Status Del_min(LinkList L) {
	if (!L)
		return FALSE;
	Node *pre = L, *p = pre->next;
	Node *minpre = pre, *min = p;
	while (p)
	{
		if (p->data < min->data) {
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = min->next;	//删除最小结点
	free(min);
	return TRUE;
}

//
//void Del_x(LinkList L, ElemType x) {		//递归删除不带头结点的单链表中所有值为x的结点
//	Node *p;	//p指向待删除结点
//	if (NULL == L)	//递归出口
//		return;
//	if (x == L->data) {
//		p = L;
//		L = L->next;
//		free(p);
//		Del_x(L, x);	//递归调用
//	}
//	else
//	{
//		Del_x(L->next, x);
//	}
//}
//
//函数功能：输出有头结点的链表
//参数L：链表头指针
Status PrintLinkList(LinkList L) {	
	if(!L)
		return FALSE
	Node *p = L->next;	//从头结点后第一个元素开始输出
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return TRUE;
}

//函数功能：使链表元素递增排序（带头结点）
//参数L：链表头指针
Status Sort(LinkList L) {
	if (!L)
		return FALSE;
	Node *p = L->next, *pre;
	Node *r = p->next;
	p->next = NULL;
	p = r;
	while (p) {
		r = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data){
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	return TRUE;

}

//函数功能：反转链表(带头结点)
//参数L:链表的头指针
Status Reverse(LinkList L) {
	if (!L)
		return FALSE;
	Node *p, *q, *r;
	p = L->next;
	q = r = NULL;
	while (p)
	{
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	L->next = r;
	return TRUE;
}

//函数功能：递归反转输出链表(带头结点)
//参数L：链表的头指针
Status Re_Print(LinkList L) {
	if (!L)
		return FALSE;
	if (L->next) {
		Re_Print(L->next);
	}
	printf("%d ", L->next->data);
	return TRUE;
}

int main() {
	/*
	ElemType e = 30;
	LinkList a =CreatLinkList_NoHead();
	PrintLinkList(a);
	Del_x(a, e);
	PrintLinkList(a);
	
	ElemType x = 15;
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	Del_x2(a, x);
	PrintLinkList(a);
	
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	Reverse(a);
	PrintLinkList(a);
	
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	Re_Print(a);
	
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	Del_min(a);
	PrintLinkList(a);
	
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	Sort(a);
	PrintLinkList(a);

	LinkList a = CreatLinkList();
	ElemType s = 10, t = 15;
	PrintLinkList(a);
	Del_st(a, s, t);
	PrintLinkList(a);.
	*/
	LinkList a = CreatLinkList();
	PrintLinkList(a);
	printf("长度：%d", Length(a));
	return 0;
}
