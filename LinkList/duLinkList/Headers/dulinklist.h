#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* left, * right;//�ֱ�Ϊ��ָ������ָ�룻
} DuLNode, * DuLinkedList;
typedef enum Status {
    error,
    success,
} Status;

//����������
Status InitList_DuL(DuLinkedList* L);//����������
void DestroyList_DuL(DuLinkedList* L);//�������
Status InsertLeftList_DuL(DuLNode* p, DuLNode* q);//���������
Status InsertRightList_DuL(DuLNode* p, DuLNode* q);//�Ҳ�������
Status DeleteList_DuL(DuLNode* p, ElemType* e);//ɾ�������е�ָ������
void TraverseList_DuL(DuLinkedList L);//��������
Status Reverselist_DuL(DuLinkedList L);
void show(void);
int judge_int(void);
