#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

#define ElemType int
#define MAXSIZE 10             //��ʼ����С
#define INC_SIZE 5            //������չ����          

#define ERRCODE 0x7FF                   //�������

typedef struct CSeqQueue
{
          ElemType* base;
          int front;         //��ͷָ��
          int rare; 		  //��βָ��
}CSeqQueue;

/*˳����еĳ�ʼ���ݻ����������*/
void InitCSeqQueue(CSeqQueue* Q);           //˳����еĳ�ʼ��
void ClearCSeqQueue(CSeqQueue* Q);           //˳����е����
void DestroyCSeqQueue(CSeqQueue* Q);           //˳����еĴݻ�

/*˳����е���ʾ���*/
void DisplayCSeqQueue(CSeqQueue* Q);           //˳����е����

/*�п��Լ���������*/
BOOL IsQueueEmpty(CSeqQueue Q);              //˳����е��п�
BOOL IsQueueFull(CSeqQueue Q);              //˳����е�����

/*����Լ����Ӳ���*/
BOOL EnQueue(CSeqQueue* Q, ElemType x);            //˳����е���Ӳ���
BOOL DeQueue(CSeqQueue* Q, ElemType* e);             //˳����еĳ��Ӳ���

/*��������*/
ElemType GetHead(CSeqQueue Q);              //˳����л�ȡ��ͷ��ֵ
int length(CSeqQueue Q);                 //˳����г���
