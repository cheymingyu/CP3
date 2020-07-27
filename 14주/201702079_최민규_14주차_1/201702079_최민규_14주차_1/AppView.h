#pragma once

char AppView_in_nextInputChar();
char AppView_in_removeKeyAndObject();
char AppView_in_searchKeyAndObject();

void AppView_out_addedKeyAndObjectInDictionary(char aChar, int aNum);
void AppView_out_replaceObject(char aChar, int aNum);

void AppView_out_remove(char aChar, int aNum);
void AppView_out_noElementInDictionary();
void AppView_out_dictionarySize(int dictionarySize);
void AppView_out_keyExistInDictionary(char aChar, int aNum);
void AppView_out_keyDoesNotExistInDictionary();
void AppView_out_ignoredChar();
void AppView_out_showBinaryTree();

void AppView_out_newLine();
void AppView_out_blank();
void AppView_out_showDictionaryElement(char aChar);

void AppView_out_startProgram();
void AppView_out_endProgram();