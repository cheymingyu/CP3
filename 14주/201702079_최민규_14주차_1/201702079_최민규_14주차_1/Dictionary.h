#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Traverse.h"

typedef struct _Dictionary Dictionary;

Dictionary* Dictionary_new(void);
void		Dictionary_delete(Dictionary* _this);

Boolean Dictionary_isEmpty(Dictionary* _this);
Boolean Dictionary_isFull(Dictionary* _this);
int		Dictionary_size(Dictionary* _this);

Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey);
Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey);
Boolean Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* _anObject);
Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey);
Boolean Dictionary_repalceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject);
void	Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse);