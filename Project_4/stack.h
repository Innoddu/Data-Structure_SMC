#ifndef STACK_H_
#define STACK_H_

#include"dllist.h"

// Stack ADT using linked list as primary data structure.
// 
template<typename Item>
class Stack {
public:

	Stack();

	// Basic stack operations
	void	push(Item item);
	void	pop();
	Item	peek() const; 

	// Check to see if there is anything on the stack
	bool	empty() const;

	// Use to see what is in the stack for debugging
	void	print() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif

	DLList<Item> m_list;
};

// Stack Implementation
//

// Stack() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Item>
Stack<Item>::Stack():m_list() {}


template<typename Item>
void Stack<Item>::push(Item item) {
	
	/* TODO */
	m_list.push_front(item);

}


template<typename Item>
void Stack<Item>::pop() {
	
	/* TODO */
	m_list.pop_front();

}


template<typename Item>
bool Stack<Item>::empty() const {
	
	/* TODO */
	return m_list.empty();
	// bool RETURN_VALUE_REQUIRED_TO_COMPILE = false;
	// return RETURN_VALUE_REQUIRED_TO_COMPILE;
}


template<typename Item>
Item Stack<Item>::peek() const {
	
	/* TODO */
	return m_list.front();
	// Item RETURN_VALUE_REQUIRED_TO_COMPILE;
	// return RETURN_VALUE_REQUIRED_TO_COMPILE;
}


template<typename Item>
void Stack<Item>::print() const {
	
	/* TODO */
	m_list.print();

}




























#endif//STACK_H__X_XMMXX