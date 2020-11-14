#include"CSeqQueue.h"

void InitCSeqQueue(CSeqQueue* Q)           //循环队列的初始化
{
		  Q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		  assert(Q->base != NULL);
		  Q->front = Q->rare = 0;		//队头队尾指针
}

void ClearCSeqQueue(CSeqQueue* Q)          //循环队列的清除
{
		  Q->front = Q->rare = 0;		//队头队尾指针
}

void DestroyCSeqQueue(CSeqQueue* Q)        //循环队列的摧毁
{
		  free(Q->base);
		  Q->base = NULL;
		  Q->front = Q->rare = 0;
}

void DisplayCSeqQueue(CSeqQueue* Q)         //循环队列的输出
{
		  for (int i = Q->front; i != Q->rare; )
		  {
					printf("%d   ", Q->base[i]);
					i = (i + 1) % MAXSIZE;
		  }
		  printf("\n");
}

BOOL IsQueueEmpty(CSeqQueue Q)             //循环队列的判空
{
		  return Q.front == Q.rare;
}

BOOL IsQueueFull(CSeqQueue Q)              //顺序队列的判满
{
		  return (Q.rare + 1) % MAXSIZE == Q.front;
}

BOOL EnQueue(CSeqQueue* Q, ElemType x)            //循环队列的入队操作
{
		  if (!IsQueueFull(*Q))
		  {
					Q->base[Q->rare] = x;
					Q->rare = (Q->rare + 1) % MAXSIZE;
					return TRUE;
		  }
		  else
		  {
					printf("队列已满不能继续入队");
					return FALSE;
		  }
}

BOOL DeQueue(CSeqQueue* Q, ElemType* e)             //循环队列的出队操作
{
		  if (!IsQueueEmpty(*Q))
		  {
					*e = Q->base[(Q->front)];
					Q->front = (Q->front + 1) % MAXSIZE;
					return TRUE;
		  }
		  else
		  {
					printf("队列为空，不能出队");
					return FALSE;
		  }
}

ElemType GetHead(CSeqQueue Q)          // 循环队列获取队头的值
{
		  return  ((!IsQueueEmpty(Q)) ? Q.base[Q.front] : ERRCODE);
}

int length(CSeqQueue Q)             //循环队列长度
{
		  return (Q.rare - Q.front + 1) % MAXSIZE;
}