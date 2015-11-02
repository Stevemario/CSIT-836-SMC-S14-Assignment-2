//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 2
//This program will prompt the user to enter a string, then it checks if the string is a valid G++ expression, and reports that it either is or isn't a valid G++ expression.
#include "cstack.h"
#include <string>
#include <iostream>
bool isValidExpression(CStack&, std::string);
int main(void) {
	CStack stack1; //creates an instance of a stack (stack1) using class constructor
	std::string expression;

	std::cout<< "Enter an expression: ";
	getline(std::cin, expression);
	if(isValidExpression(stack1, expression))
		std::cout << "\nIt's a valid expression";
	else
		std::cout << "\nIt's NOT a valid expression";
	return 0;
}
bool isValidExpression(CStack& stackA, std::string strExp) {
	bool bIsValidExpression = true;
	int n_sizeExpression = strExp.size();
	char chMatching;  //Saves me from needing to copy paste code.
	bool bSet_chMatching = false; //ditto
	for(int i = 0; i < n_sizeExpression && bIsValidExpression; i++) {
		switch(strExp[i]) {
			case '{':
			case '[':
			case '(': {
				if(stackA.IsFull())
					bIsValidExpression = false;
				else
					stackA.Push(strExp[i]);
				break;
			}
			case '}': {
				if(!bSet_chMatching) {
					chMatching = '{';
					bSet_chMatching = true;
				}
				//NO BREAK INTENDED
			}
			case ']': {
				if(!bSet_chMatching) {
					chMatching = '[';
					bSet_chMatching = true;
				}
				//NO BREAK INTENDED
			}
			case ')': {
				if(stackA.IsEmpty()) {
					bIsValidExpression = false;
				} else {
					if(!bSet_chMatching) {
						chMatching = '(';
						bSet_chMatching = true;
					}
					if(stackA.Top() == chMatching)
						stackA.Pop();
					else
						bIsValidExpression = false;
					bSet_chMatching = false; //Needed for loop
				}
				break;
			}
		}
	}
	if(bIsValidExpression)
		if(!stackA.IsEmpty())
			bIsValidExpression = false;
	return bIsValidExpression;
}