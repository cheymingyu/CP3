#pragma once

char AppView_in_nextInputChar();

void AppView_out_queueIsFull(char anElementForPush);
void AppView_out_addedElementInQueue(char anElement);
void AppView_out_noElementInQueue();
void AppView_out_removedElementFromQueue(char anElement);
void AppView_out_removedElementFromQueueByRemoveN(char anElement);
void AppView_out_queueIsEmptyAgainstRemove();
void AppView_out_frontElement(char anElement);
void AppView_out_noFrontElement();
void AppView_out_labelRear();
void AppView_out_elementInQueue(char anElement);
void AppView_out_labelFront();
void AppView_out_newLine();
void AppView_out_queueSize(int stackSize);
void AppView_out_ignoredChar();
void AppView_out_removedElementByEndInput(char anElement);
void AppView_out_numberOFInputChars(int numberOfChars);
void AppView_out_numberOfNormallyProcessedChars(int numberOfChars);
void AppView_out_numberOfIgnoredChars(int numberOfChars);
void AppView_out_numberOfAddedChars(int numberOfChars);
void AppView_out_startProgram();
void AppView_out_endProgram();