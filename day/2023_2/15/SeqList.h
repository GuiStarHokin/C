#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>


typedef int SLDataType;

typedef struct SeqList
{
  SLDataType *a;
  int size;
  int capacity;
}SL;

extern void SeqListInit(SL *sl);
extern void SeqListPushBack(SL *sl, SLDataType x);
extern void SeqListPopBack(SL *sl);
extern void SeqListPushFront(SL *sl, SLDataType x);
extern void SeqListPopFront(SL *sl, SLDataType x);
extern void SeqListPrint(const SL *sl);
extern void SeqListDestory(SL *sl);




#endif