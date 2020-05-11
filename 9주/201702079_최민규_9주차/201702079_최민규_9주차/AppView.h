#pragma once

char AppView_in_charDirectlyFromKeyboard();

void AppView_out_stackIsFullAgainstPush(char anElementForPush);
void AppView_out_pushedElement(char anElement);
void AppView_out_stackIsEmptyAgainstPop1();
void AppView_out_poppedElementByPop1(char anElement);
void AppView_out_beginPops(int numberOfElements);
void AppView_out_endPops();
void AppView_out_stackIsEmptyAgainstPop();
void AppView_out_topElement(char anElement);
void AppView_out_noTopElement();
void AppView_out_bottomOfStack();
void AppView_out_element(char anElement);
void AppView_out_topOfStack();
void AppView_out_newLine();
void AppView_out_stackSize(int stackSize);
void AppView_out_ignoredChar();
void AppView_out_endInput();
void AppView_out_poppedElementByEndInput(char anElement);
void AppView_out_numberOFInputChars(int numberOfChars);
void AppView_out_numberOfNormallyProcessedChars(int numberOfChars);
void AppView_out_numberOfIgnoredChars(int numberOfChars);
void AppView_out_numberOfPushedChars(int numberOfChars);
void AppView_out_startProgram();
void AppView_out_endProgram();