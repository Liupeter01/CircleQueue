#include"CSeqQueue.h"

void InitCSeqQueue(CSeqQueue* Q)           //˳����еĳ�ʼ��
{
		  Q->base = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
		  assert(Q->base != NULL);
		  Q->front = Q->rare = 0;		//��ͷ��βָ��
}

void ClearCSeqQueue(CSeqQueue* Q)          //˳����е����
{
		  Q->front = Q->rare = 0;		//��ͷ��βָ��
}

void DestroyCSeqQueue(CSeqQueue* Q)        //˳����еĴݻ�
{
		  free(Q->base);
		  Q->base = NULL;
		  Q->front = Q->rare = 0;
}

void DisplayCSeqQueue(CSeqQueue* Q)         //˳����е����
{
		  for (int i = Q->front; i < Q->rare; ++i)
		  {
					printf("%d   ", Q->base[i]);
		  }
}

BOOL IsQueueEmpty(CSeqQueue Q)             //˳����е��п�
{
		  return (Q.rare + 1) % MAXSIZE == Q.front;
}

BOOL IsQueueFull(CSeqQueue Q)              //˳����е�����
{
		  return (Q.rare + 1) % MAXSIZE == Q.front;
}

BOOL EnQueue(CSeqQueue* Q, ElemType x)            //˳����е���Ӳ���
{
		  if (!IsQueueFull(*Q))
		  {
					Q->base[Q->rare++] = x;
					return TRUE;
		  }
		  else
		  {
					printf("�����������ܼ������");
					return FALSE;
		  }
}

BOOL DeQueue(CSeqQueue* Q, ElemType* e)             //˳����еĳ��Ӳ���
{
		  if (!IsQueueEmpty(*Q))
		  {
					*e = Q->base[(Q->front++)];
					return TRUE;
		  }
		  else
		  {
					printf("����Ϊ�գ����ܳ���");
					return FALSE;
		  }
}

ElemType GetHead(CSeqQueue Q)          //˳����л�ȡ��ͷ��ֵ
{
		  return  ((!IsQueueEmpty(Q)) ? Q.base[Q.front] : ERRCODE);
}

int length(CSeqQueue Q)             //˳����г���
{
		  return (Q.rare - Q.front);
}