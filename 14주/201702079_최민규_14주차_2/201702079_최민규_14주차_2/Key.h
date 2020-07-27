#pragma once
#include "Common.h"

typedef struct _Key Key;
typedef int		KeyValue;

Key* Key_new(void);
Key* Key_newWith(KeyValue givenValue);
void Key_delete(Key* _this);

void Key_setValue(Key* _this, KeyValue newValue);
KeyValue Key_value(Key* _this);

int Key_compareTo(Key* _this, Key* otherKey);