#include "SeqList.h"

void TestSeqList1(void)
{
  SL sl;
  SeqListInit(&sl);
  SeqListPushBack(&sl, 1);
  SeqListPushBack(&sl, 2);
  SeqListPushBack(&sl, 3);
  SeqListPushBack(&sl, 4);
  SeqListPushBack(&sl, 5);
  SeqListPopBack(&sl);
  SeqListPrint(&sl);
  SeqListDestory(&sl);
}

int main()
{
  TestSeqList1();
  system("pause");
  return 0;
}