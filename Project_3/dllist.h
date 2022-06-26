#ifndef CS20A_DLLIST_H
#define CS20A_DLLIST_H

#include<iostream>
#include<assert.h>
// Linked DLList object that maintains both head and tail pointers
// and the size of the list.  Note that you have to keep the head,
// tail and size consistent with the intended state of the DLList 
// otherwise very bad things happen. 
template<typename Item>
class DLList {
public:

	DLList();

	DLList(const DLList<Item>& other);

	DLList<Item>& operator=(const DLList<Item>& other);

	~DLList();

	void	print() const;
	bool	empty() const;

	void	push_front(const Item &item);
	void	push_rear(const Item &item);
	void	push_at(int idx, const Item &item);

	// Note that the user must first ensure the list is not empty
	// prior to calling these functions. 
	Item	front() const;
	Item	rear() const;
	Item	at(int idx) const;

	int		count() const;
	int		find(const Item &item) const;

	bool	pop_front();
	bool	pop_rear();
	bool	pop_at(int idx);
	int		pop_item(const Item &item);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our DLList.
	// Will be implemented along with list
	// member functions
	struct Node;

	// We'll have both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node*	head;
	Node*	tail;

	// Keep track of number of nodes in the list
	int		size;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual 
//  class yet, not until we actually instantiate the list) 
//  we need to keep the implementation together with 
//  the definition.  There are ways to simulate having 
//  separate "implementation/definition" with templates, 
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
struct DLList<Item>::Node {
	Node() :next(nullptr), prev(nullptr) {}
	Node(Item it, Node* p, Node* n) : item(it), next(n), prev(p) {}

	Item  item;
	Node* next;
	Node* prev;
};

/* DLList default constructor
//		Set head and tail pointer to point to nothing, size is zero
//		Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() :head(nullptr), tail(nullptr), size(0) {
	/*  DONE  */
}


/* Copy constructor  
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item>& other) {

	/*  TODO  */
	if(other.head == 0 && other.tail == 0){
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	else{
		size = other.size;
		head = other.head;
		Node * copy = head;
		if(head == nullptr){
		head = new Node(copy->item,nullptr,nullptr);
		tail = head;
		}
		else{
		while(copy != nullptr){

			copy = copy->next;
		}
		}
		
	}


	// # v1
	// if(other.head == 0 && other.tail == 0){
	// 	size = 0;
	// 	head = nullptr;
	// 	tail = nullptr;
	// }
	// else{
	// 	size = other.size;
	// 	head = other.head;
	// 	Node * copy = head;
	// 	Node * head = new Node(copy->item,copy->next,copy->prev);
	// 	while(copy != nullptr){
	// 		push_front(copy->item);
	// 		copy = copy->next;
	// 	}
	// 	tail = copy;
	// 	if(tail == nullptr){
	// 	std::cout << "true"<< std::endl;
	// 	}else{
	// 		std::cout << "false"<< std::endl;
	// 	}
		
	// }
}
/* Overloaded assignment operator 
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {

	/*  TODO  */
	if( this == &other){return *this;}

	delete head;


	if(other.head == 0 || other.tail == 0){
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	else{
		size = other.size;
		head = other.head;
		Node * copy = head;
		Node * head = new Node(copy->item,copy->next,copy->prev);
		while(copy != nullptr){
			push_front(copy->item);
			copy = copy->next;
		}
		tail = copy;

	}

	return *this;
}

/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {

	/*  TODO  */
	Node *p = head;
	while(p != nullptr){
		Node *n = p->next;
		delete p;
		p = n;
	}
	tail = nullptr;
	size = 0;



}

/* DLList print
*/		
template<typename Item>
void DLList<Item>::print() const {

	/*  TODO  */
	Node *p;
    p = head; // p points to 1st node
    while(p != nullptr){	
    std::cout << p->item;
    	p = p->next;
	if(p == nullptr){break;}
	std::cout<<" ";
    }
	

}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {

	/*  TODO  */
	// # v2
	// if(size == 0)
	// 	return true;
	// else
	// 	return false;

	// # v1
	Node *p = head;
	if(p == nullptr){
		// std::cout<<"empty"<<std::endl;
		return true;
	}
	// std::cout<<"there is node"<<std::endl;
	return false;


	// bool dummyReturnValue = false;
	// return dummyReturnValue;
}


/* DLList push_front
Adds item to a new Node at the Front of the list. Updates head,
tail, and size accordingly. Must appropriately handle 
cases in which the list is empty and if there are
nodes already in the list.
*/
template<typename Item>
void DLList<Item>::push_front(const Item &item) {

	/*  TODO  */
	if(empty()==true){
	Node *p = new Node;
	p->item = item;
	head = p;
	tail = p;
	size++;
	}
	else{
	Node *temp = new Node;
	temp->item = item;
	temp->next = head;
	head = temp;
	head->next->prev = temp; // add line #v2
	while(temp->next !=nullptr){
		temp = temp->next;
	}
	tail = temp;
	size++;
	}	

	// # v1
	// if(empty()==true){
	// Node *p = new Node;
	// p->item = item;
	// p->next = head;
	// head = p;
	// tail = p;
	// size++;
	// }
	// else{
	// Node *temp = new Node;
	// temp->item = item;
	// temp->next = head;
	// head = temp;
	// head->next->prev = temp; // add line #v2
	// while(temp->next !=nullptr){
	// 	temp = temp->next;
	// }
	// tail = temp;
	// size++;
	// }	
		// // std::cout<<"Size : "<<size << std::endl;
		// }


}

/* DLList push_rear
Adds item to a new Node at the Rear of the list. Updates head,
tail, and size accordingly. Must appropriately handle cases in which the list is empty and if there are
nodes already in the list.
*/
template<typename Item>
void DLList<Item>::push_rear(const Item &item) {

	/*  TODO  */
	if(head == nullptr){
		push_front(item);
		// std::cout << "After Rear Size: " << size << std::endl;
	}
	else{

		// #v2
		Node *n = new Node;
		n->item = item;
		tail->next = n;
		n->prev = tail;
		n->next = nullptr;
		tail = n;
		size++;
	
		// code #v1
		// Node *n = new Node;
		// n->item = item;
		// tail->next = n;
		// n->next = nullptr;
		// tail = n;
		// size++;
		// std::cout << "After Rear Size: " << size << std::endl;
	}

}

/* DLList push_at
Given an index, this function adds the item to a new Node at
the index. Updates head, tail, and size accordingly. 
If the index is less than or equal to zero add the
item to the front. If the index is greater than or equal to the size of the list,
then add it to the rear.
Otherwise add the item at the index indicated. 
Indices begin at zero.
*/
template<typename Item>
void DLList<Item>::push_at(int idx, const Item &item) {

	/*  TODO  */

	// # v2
	if(idx <= 0){
		push_front(item);
	}
	else if(idx >= size){
		push_rear(item);
	}
	else{
		int count = 0;
		Node *curr = head;
		while(count != (idx-1)){
			curr = curr->next;
			count++;
		}
		Node *temp = new Node;
		temp->item = item;
		temp->next = curr->next;
        curr->next = temp;
		temp->next->prev = temp;
		temp->prev = curr;
        size++;
	}
	// # v1
	// if(idx <= 0){
	// 	push_front(item);
	// }
	// if(idx >= size){
	// 	push_rear(item);
	// }
	// else{
	// 	int count = 0;
	// 	Node *curr = head;
	// 	while(count != (idx-1)){
	// 		curr = curr->next;
	// 		count++;
	// 	}
	// 	Node *temp = new Node;
		
	// 	temp->item = item;
	// 	temp->next = curr->next;
	// 	curr->next = temp;
	// 	temp->prev = curr;
	// 	curr->next->prev = temp;       
	// 	size++;
		
	// }
}

/*  DLList front
returns the item in the Node at the front of 
the list without modifying the list.
The function cannot be called if the list is empty. 
*/
template<typename Item>
Item DLList<Item>::front() const {

	// This should never be tripped, this is just here to let
	// you know that you messed up with your usage, this function
	// is never called on an empty list.
	assert(head != nullptr); 
	
	
	/*  TODO  */
	return head->item;

	// Item dummyReturnValue;
	// return dummyReturnValue;

}

/* DLList rear
returns the item in the Node at the rear of 
the list without modifying the list. 
The function cannot be called if the list is empty. 
*/
template<typename Item>
Item DLList<Item>::rear() const {

	// This should never be tripped, this is just here to let
	// you know that you messed up with your usage, this function
	// is never called on an empty list.
	assert(tail != nullptr);

	/*  TODO  */
	return tail->item;

	// Item dummyReturnValue;
	// return dummyReturnValue;
	
}

/* DLList at
returns the item in the Node in the index 
place of the list. Indices begin at zero.
*/
template<typename Item>
Item DLList<Item>::at(int idx) const {

	// Assert that index is correct before getting the Item
	assert(idx >= 0 && idx < size);

	/*  TODO  */
	if(idx == 0){
		return front();
	}
	if(idx == (size-1)){
		return rear();
	}
	if(idx > 0 && idx < size){
		int count = 0;
		Node *curr = head;
		while(count != idx){
			curr = curr->next;
			count++;
		}
		return curr->item;
	}


	// Item dummyReturnValue;
	// return dummyReturnValue;
}

/* DLList count
*/
template<typename Item>
int DLList<Item>::count() const {

	/*  TODO  */
	int count = 0;
	Node *p = head;
	while(p != nullptr){
		p = p->next;
		count++;
	}
	return count;

	// int dummyReturnValue = 9000;
	// return dummyReturnValue;
}

/* DLList find
*/
template<typename Item>
int DLList<Item>::find(const Item &item) const {

	/*  TODO  */
	int count = 0;
	Node *p = head;
	while(p != nullptr){
		if(p->item == item){
		return count;
		}
		p = p->next;
		count++;

	}
	return -1;



	// int dummyReturnValue = 8675309;
	// return dummyReturnValue;
}

/* DLList pop_front
*/		
template<typename Item>
bool DLList<Item>::pop_front() {

	/*  TODO  */
	if(head != nullptr){
		Node *KillMe = head;
		head = head->next;
		if(head != nullptr)
			head->prev = nullptr;
		delete KillMe;
		size--;
		
		if(size == 0){
			tail = nullptr;
		}

		return true;
	}
	else{
		return false;
	}


	// # v1
	// if(head != nullptr){
	// 	Node *KillMe = head;
	// 	head = KillMe->next;
	// 	head->next->prev = nullptr;
	// 	size--;
	// 	delete KillMe;
	// 	return true;
	// }
	// else{
	// 	return false;
	// }

	// bool dummyReturnValue = false;
	// return dummyReturnValue;
}
/* DLList pop_rear
*/	
template<typename Item>
bool DLList<Item>::pop_rear() {

	/*  TODO  */

	// # v3
	Node *temp = head;
	if (temp == nullptr) {              
        return false;
    }
	else if(size == 1){
	delete tail;
	size--;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else if(size >1){	
	delete tail;
	size--;
		while (temp->next != tail) {
        temp = temp->next;
   		 }

		temp->next = nullptr;
		tail = temp;
		return true;
	}
	else{
		return true;
	}


    


	// bool dummyReturnValue = false;
	// return dummyReturnValue;
}

/* DLList pop_at on index
*/
template<typename Item>
bool DLList<Item>::pop_at(int idx) {

	/*  TODO  */

	if(idx > size || idx < 0){
		return false;
	}
	else{
	if(idx == 0){
		pop_front();
		return true;
	}
	else if( idx >= (size-1)){
		pop_rear();
		return true;
	}
	else{
		Node *temp = head;
	for(int i=0; i<idx; i++){
		temp = temp->next;
	}
		Node *temp2 = temp->prev;
		temp2->next = temp->next;
		temp->next->prev = temp2;
		size--;
		delete temp;
		return true;


	}

}
	// bool dummyReturnValue = false;
	// return dummyReturnValue;

}

/* DLList pop_item on item
*/
template<typename Item>
int DLList<Item>::pop_item(const Item &item) {

	/*  TODO  */
	if(head == nullptr){
		return -2;
	}
	else{
		if(find(item) < 0){
			return -1;
		}
		else{
		
		// int idx = find(item);
		// Node *temp = head;
		// for(int i =0; i<idx; i++){
		// 	temp = temp->next;
		// }
		int idx = find(item);
		pop_at(find(item));
		return idx;

		}
	}

	// # v1
	// if(head == nullptr){
	// 	return -2;
	// }
	// else{
	// 	if(find(item) < 0){
	// 		return -1;
	// 	}
	// 	else{
	// 	return pop_at(find(item));
	// 	}
	// }

	// int dummyReturnValue = 42;
	// return dummyReturnValue;
}

#endif



























































































// _X_XMXXII