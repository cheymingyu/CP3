#pragma once
#include "Common.h"

typedef int Element;
typedef struct _UnsortedArrayList UnsortedArrayList;

UnsortedArrayList* UnsortedArrayList_new(int givenCapacity);
void UnsortedArrayList_delete(UnsortedArrayList* _this);

Boolean UnsortedArrayList_isEmpty(UnsortedArrayList* _this);
Boolean UnsortedArrayList_isFull(UnsortedArrayList* _this);

Boolean UnsortedArrayList_add(UnsortedArrayList* _this, Element anElement);
Element UnsortedArrayList_removeMax(UnsortedArrayList* _this);