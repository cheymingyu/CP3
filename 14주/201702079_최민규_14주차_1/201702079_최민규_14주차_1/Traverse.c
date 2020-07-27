#include "Traverse.h"
#include "AppView.h"

struct _Traverse
{
	int a;
};

Traverse*	Traverse_new(void) {
	Traverse* _this = NewObject(Traverse);
	return _this;
}
void Traverse_delete(Traverse* _this) {
	free(_this);
}

void Traverse_visit(Traverse* _this, Key* aKey, Object* anObject, int depth) {
	if (depth == 1) {

	}
	for (int i = 1; i < depth; i++) {
		AppView_out_blank();
	}
	char keyValue = Key_value(aKey);
	AppView_out_showDictionaryElement(keyValue);
}