#include"CSeqQueue.h"

int main()
{
          CSeqQueue queue;
          InitCSeqQueue(&queue);         //��ʼ��

          for (int i = 0; i <= 10; ++i)
          {
                    if (!EnQueue(&queue, i))
                    {
                              printf("enqueue error!!\n");
                    }
          }
          DisplayCSeqQueue(&queue);                 //��ʾ
          ElemType data;
          DeQueue(&queue, &data);

          EnQueue(&queue, 999);
          DisplayCSeqQueue(&queue);               //��ʾ

          DestroyCSeqQueue(&queue);                //�ݻ�
          return 0;
}