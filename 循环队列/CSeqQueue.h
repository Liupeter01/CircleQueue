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

/*ѭ�����еĳ�ʼ���ݻ����������*/
void InitCSeqQueue(CSeqQueue* Q);           //ѭ�����еĳ�ʼ��
void ClearCSeqQueue(CSeqQueue* Q);           //ѭ�����е����
void DestroyCSeqQueue(CSeqQueue* Q);           //ѭ�����еĴݻ�

/*ѭ�����е���ʾ���*/
void DisplayCSeqQueue(CSeqQueue* Q);           //ѭ�����е����

/*�п��Լ���������*/
BOOL IsQueueEmpty(CSeqQueue Q);              //ѭ�����е��п�
BOOL IsQueueFull(CSeqQueue Q);              //ѭ�����е�����

/*����Լ����Ӳ���*/
BOOL EnQueue(CSeqQueue* Q, ElemType x);            //ѭ�����е���Ӳ���
BOOL DeQueue(CSeqQueue* Q, ElemType* e);             //ѭ�����еĳ��Ӳ���

/*��������*/
ElemType GetHead(CSeqQueue Q);              //ѭ�����л�ȡ��ͷ��ֵ
int length(CSeqQueue Q);                 //ѭ�����г���
