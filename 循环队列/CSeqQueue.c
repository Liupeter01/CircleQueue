#include"CSeqQueue.h"

void InitCSeqQueue(CSeqQueue* Q)           //ѭ�����еĳ�ʼ��
{
		  Q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		  assert(Q->base != NULL);
		  Q->front = Q->rare = 0;		//��ͷ��βָ��
}

void ClearCSeqQueue(CSeqQueue* Q)          //ѭ�����е����
{
		  Q->front = Q->rare = 0;		//��ͷ��βָ��
}

void DestroyCSeqQueue(CSeqQueue* Q)        //ѭ�����еĴݻ�
{
		  free(Q->base);
		  Q->base = NULL;
		  Q->front = Q->rare = 0;
}

void DisplayCSeqQueue(CSeqQueue* Q)         //ѭ�����е����
{
		  for (int i = Q->front; i != Q->rare; )
		  {
					printf("%d   ", Q->base[i]);
					i = (i + 1) % MAXSIZE;
		  }
		  printf("\n");
}

BOOL IsQueueEmpty(CSeqQueue Q)             //ѭ�����е��п�
{
		  return Q.front == Q.rare;
}

BOOL IsQueueFull(CSeqQueue Q)              //˳����е�����
{
		  return (Q.rare + 1) % MAXSIZE == Q.front;
}

BOOL EnQueue(CSeqQueue* Q, ElemType x)            //ѭ�����е���Ӳ���
{
		  if (!IsQueueFull(*Q))
		  {
					Q->base[Q->rare] = x;
					Q->rare = (Q->rare + 1) % MAXSIZE;
					return TRUE;
		  }
		  else
		  {
					printf("�����������ܼ������");
					return FALSE;
		  }
}

BOOL DeQueue(CSeqQueue* Q, ElemType* e)             //ѭ�����еĳ��Ӳ���
{
		  if (!IsQueueEmpty(*Q))
		  {
					*e = Q->base[(Q->front)];
					Q->front = (Q->front + 1) % MAXSIZE;
					return TRUE;
		  }
		  else
		  {
					printf("����Ϊ�գ����ܳ���");
					return FALSE;
		  }
}

ElemType GetHead(CSeqQueue Q)          // ѭ�����л�ȡ��ͷ��ֵ
{
		  return  ((!IsQueueEmpty(Q)) ? Q.base[Q.front] : ERRCODE);
}

int length(CSeqQueue Q)             //ѭ�����г���
{
		  return (Q.rare - Q.front + 1) % MAXSIZE;
}