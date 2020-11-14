#include"CSeqQueue.h"

int main()
{
          CSeqQueue queue;
          InitCSeqQueue(&queue);         //≥ı ºªØ

          for (int i = 0; i < 5; ++i)
          {
                    if (!EnQueue(&queue, i))
                    {
                              printf("enqueue error!!\n");
                    }
          }

          DestroyCSeqQueue(&queue);                //¥›ªŸ
          return 0;
}