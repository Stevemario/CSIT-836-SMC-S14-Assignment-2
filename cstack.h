//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 2
//This program will prompt the user to enter a string, then it checks if the string is a valid G++ expression, and reports that it either is or isn't a valid G++ expression.
#ifndef CSTACK_H
#define CSTACK_H
class CStack {
	private:
		/* Index of the last element of array that holds
		a value of the stack */
		int top;
		/* Holds values being placed on the stack */
		char data[20];
	public:
		CStack();
		/* Assigns the parameter (a character) to the index one
		greater than the existing top index of the array and
		increments the top variable to the new index. */
		void Push(char);
		 /* Decrements the top variable.
		 Does not return the top value.*/
		void Pop();
		/* Returns the value in the top index of array. */
		char Top();
		/* Returns False (zero) if there is at least one item
		of the stack in array, True (non-zero) if not. */
		bool IsEmpty();
		/* Returns True (non-zero) if all elements of the array
		contain items of the stack, False (zero) if not. */
		bool IsFull();
};
#endif