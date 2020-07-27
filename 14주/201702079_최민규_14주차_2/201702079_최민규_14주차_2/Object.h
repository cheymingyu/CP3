#pragma once
#include "Common.h"

typedef struct _Object Object;
typedef int		ObjectValue;

Object* Object_new(void);
Object* Object_newWith(ObjectValue givenValue);
void	Object_delete(Object* _this);

void Object_setValue(Object* _this, ObjectValue newValue);
ObjectValue Object_value(Object* _this);