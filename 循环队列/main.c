#include"CSeqQueue.h"

int main()
{
          CSeqQueue queue;
          InitCSeqQueue(&queue);         //初始化

          for (int i = 0; i <= 10; ++i)
          {
                    if (!EnQueue(&queue, i))
                    {
                              printf("enqueue error!!\n");
                    }
          }
          DisplayCSeqQueue(&queue);                 //显示
          ElemType data;
          DeQueue(&queue, &data);

          EnQueue(&queue, 999);
          DisplayCSeqQueue(&queue);               //显示

          DestroyCSeqQueue(&queue);                //摧毁
          return 0;
}