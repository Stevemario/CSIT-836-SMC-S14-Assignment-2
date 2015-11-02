//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 2
//This program will prompt the user to enter a string, then it checks if the string is a valid G++ expression, and reports that it either is or isn't a valid G++ expression.
#include "cstack.h"
CStack::CStack() {
	top = -1;
	//0 is the first character slot and that is not filled.
}
void CStack::Push(char chData) {
	data[top + 1] = chData;
	top++;
}
void CStack::Pop() {
	top--;
}
char CStack::Top() {
	return data[top];
}
bool CStack::IsEmpty() {
	bool bIsEmpty = true;
	if(0 <= top)
		bIsEmpty = false;
	return bIsEmpty;
}
bool CStack::IsFull() {
	bool bIsFull = false;
	if(20 <= top - 1)
		bIsFull = true;
	return bIsFull;
}