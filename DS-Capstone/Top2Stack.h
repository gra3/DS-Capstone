#pragma once
#include "Node.h"

template <typename T>
class Top2Stack
{
public:
	Top2Stack();
	~Top2Stack(void);
	unsigned int size();
	void push(T dataIn);
	T pop();
	bool empty();
	T* top();
	T* secondTop();

private:
	unsigned int count;
	Node<T>* topNode;
	Node<T>* secondTopNode;
};

///Constructor for Stack class
template <typename T>
Top2Stack<T>::Top2Stack()
{
	count = 0;
	topNode = nullptr;
}

///Destructor for Stack class
template <typename T>
Top2Stack<T>::~Top2Stack()
{
	delete topNode;
}

///Returns the number of nodes in the Stack
template <typename T>
unsigned int Top2Stack<T>::size()
{
	return count;
}

///Puts a new Node on top of the Stack
template <typename T>
void Top2Stack<T>::push(T dataIn)
{
		Node<T> * newNode = new Node<T>;
		newNode->data = dataIn;
		newNode->next = topNode;
		if(count >0) secondTopNode = topNode;
		topNode = newNode;
		count++;
}

///Removes the top node of the Stack and returns its value
template <typename T>
T Top2Stack<T>::pop()
{
	if(empty())
	{
		cout << "Stack Error: cannot pop an element from an empty stack\n";
	}
	else
	{
		T data = topNode->data;
		Node<T>* tempNode = topNode;
		topNode = topNode->next;
		delete tempNode;
		count--;
		return data;
	}
}

///Returns true if the stack is empty, otherwise false
template <typename T>
bool Top2Stack<T>::empty()
{
	if(count==0) return true;
	return false;
}

///Returns the top element of the stack
template <typename T>
T* Top2Stack<T>::top()
{
	if(empty()) throw runtime_error("Stack is empty.");
	return &topNode->data;
}

///Returns the second to top element of the stack
template <typename T>
T* Top2Stack<T>::secondTop()
{
	if(empty()) throw runtime_error("Stack is empty.");
	return &secondTopNode->data;
}