#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

#define ElemType int
#define MAXSIZE 10             //初始最大大小
#define INC_SIZE 5            //容量扩展增量          

#define ERRCODE 0x7FF                   //错误代码

typedef struct CSeqQueue
{
          ElemType* base;
          int front;         //队头指针
          int rare; 		  //队尾指针
}CSeqQueue;

/*顺序队列的初始化摧毁与清除功能*/
void InitCSeqQueue(CSeqQueue* Q);           //顺序队列的初始化
void ClearCSeqQueue(CSeqQueue* Q);           //顺序队列的清除
void DestroyCSeqQueue(CSeqQueue* Q);           //顺序队列的摧毁

/*顺序队列的显示输出*/
void DisplayCSeqQueue(CSeqQueue* Q);           //顺序队列的输出

/*判空以及判满操作*/
BOOL IsQueueEmpty(CSeqQueue Q);              //顺序队列的判空
BOOL IsQueueFull(CSeqQueue Q);              //顺序队列的判满

/*入队以及出队操作*/
BOOL EnQueue(CSeqQueue* Q, ElemType x);            //顺序队列的入队操作
BOOL DeQueue(CSeqQueue* Q, ElemType* e);             //顺序队列的出队操作

/*其他功能*/
ElemType GetHead(CSeqQueue Q);              //顺序队列获取队头的值
int length(CSeqQueue Q);                 //顺序队列长度
