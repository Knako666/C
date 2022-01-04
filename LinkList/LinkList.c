#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0;

typedef int ElemType;

typedef int Status;

typedef struct node{
	ElemType data;	//������
	struct node *next; //ָ����
}Node, *LinkList;


//�������ܣ���������(��ͷ���)
//����L:����ͷָ��
LinkList CreatLinkList() {	//ͷ�巨
	LinkList L = NULL;
	Node *s;
	ElemType e;
	//����ͷ���
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	printf("�����룺\n");
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

//�������ܣ���������(��ͷ���)
//����L:����ͷָ��
LinkList CreatLinkList_NoHead() {	//ͷ�巨
	LinkList L = NULL;
	Node *s,*p;
	ElemType e = 0;
	printf("�����룺\n");
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

//�������ܣ����������(��ͷ���)
//����L:����ͷָ��
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

//�������ܣ�ɾ����ͷ���������ֵΪx��Ԫ�أ�Ĭ�ϲ�Ψһ��
//����L������ͷָ��
//����x��Ѱ�ұ�ɾ��Ԫ�ص�ֵΪx
Status Del_x2(LinkList L, ElemType x) {
	if (!L)
		return FALSE;
	Node *p = L->next, *pre = L, *q;	//��p��ʼ��һ������preΪp��ǰ����q���ڼ�¼��x��ȵ�Ԫ��
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

//�������ܣ�ɾ����s��t�����ڵ�����Ԫ��
//����L������ͷָ��
//����s���½�
//����t���Ͻ�
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

//��������:ɾ����������ͷ��㣩�е���Сֵ���
//����L:����ͷָ��
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
	minpre->next = min->next;	//ɾ����С���
	free(min);
	return TRUE;
}

//
//void Del_x(LinkList L, ElemType x) {		//�ݹ�ɾ������ͷ���ĵ�����������ֵΪx�Ľ��
//	Node *p;	//pָ���ɾ�����
//	if (NULL == L)	//�ݹ����
//		return;
//	if (x == L->data) {
//		p = L;
//		L = L->next;
//		free(p);
//		Del_x(L, x);	//�ݹ����
//	}
//	else
//	{
//		Del_x(L->next, x);
//	}
//}
//
//�������ܣ������ͷ��������
//����L������ͷָ��
Status PrintLinkList(LinkList L) {	
	if(!L)
		return FALSE
	Node *p = L->next;	//��ͷ�����һ��Ԫ�ؿ�ʼ���
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return TRUE;
}

//�������ܣ�ʹ����Ԫ�ص������򣨴�ͷ��㣩
//����L������ͷָ��
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

//�������ܣ���ת����(��ͷ���)
//����L:�����ͷָ��
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

//�������ܣ��ݹ鷴ת�������(��ͷ���)
//����L�������ͷָ��
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
	printf("���ȣ�%d", Length(a));
	return 0;
}
