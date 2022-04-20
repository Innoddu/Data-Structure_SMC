/* WordList source file
*
*
*	This file will contain the function definitions you will implement.
*	The function signitures may NOT be changed.  You may create your own
*	helper functions and include them in this file.
*
*	In addition to the specific instructions for each function, no function
*	should cause any memory leaks or alias words_list in any way that would result
*	in undefined behavior. 
*
*	Topics: Multilevel Pointers, Dynamic Allocation, Classes
*
*/
// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif

// Do not include any other libraries
#include"wordlist.h"
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;

/* Function: Wordlist Constructor  
*/
WordList::WordList(const int cap):words_list(nullptr), n_words(0),capacity(cap){

	// TODO:
	if(capacity < 1){
		words_list = nullptr;
		capacity = 0;
	}
	else{
		words_list = new char*[capacity];
		for(int i =0; i<capacity; i++){
		words_list[i] = new char[20];
		}
	}	


}

/* Function: Wordlist Copy Constructor
*/
WordList::WordList(const WordList &src){

	// TODO:
	n_words = src.n_words;
	capacity = src.capacity;
	if(capacity < 1){
		words_list = nullptr;
	}
	words_list = new char*[capacity];
	for(int i = 0; i < capacity; i++){
		words_list[i] = new char[20];
	}

	for (int i = 0; i < n_words; i++) {
        strcpy(words_list[i], src.words_list[i]);
    }
	


}


/* Function: Wordlist Destructor
*/
WordList::~WordList() {

	// TODO:
	for(int i=0; i < n_words; i++){
		delete [] words_list[i];
	}
		delete [] words_list;

}

/* Function: printList
*/
int	WordList::print() const {

	// TODO:
	if(words_list == nullptr){
		return -2;
	}
	int count = 0;


	// #1
	// for(int i=0; i < n_words; i++){
	// 	cout << words_list[i];
	// 	cout << " ";
	// 	count++;
	// }

	// #2
	for(int i = n_words-1; i >= 0; i--){
		
		cout << words_list[i] << " ";
		count++;
	}

	return count;

}


/* Function: get
*/
char* WordList::get(const int index) const {

	// TODO:
    if (index >= n_words || index < 0) {
        return nullptr;
    }
	return words_list[index];	

	// char* dummyreturnval = nullptr;
	// return dummyreturnval;

}


/* Function: count
*/
int	WordList::count() const {

	// TODO:
 	return n_words;
	// int dummyreturnval = -9000;
	// return dummyreturnval;
}


/* Function: insert
*/
int	WordList::insert(const char word[]) {

	// TODO:
	if(word[0] == '\0'){
			return -1;
	}

	if(capacity <= n_words){
	// cout << "Count: " << n_words << endl; // Expect 0
	// cout << "Capacity: " << capacity << endl; 
	int temp = count();
	temp++;
	char ** templist = new char*[temp];
	for (int i = 0; i < temp; i++) {
		templist[i] = new char[20];
	}
		//Then copy over the words from the original list and then the new words
		for(int i = 0; i< n_words; i++){
   			 strcpy(templist[i], words_list[i]);
		}
	
		for(int i = 0; i < capacity; i++){
			delete [] words_list[i];
		}
			delete [] words_list;
		
		capacity = temp;
		
		words_list = templist;
		
	}
	
	strcpy(words_list[n_words],word);
	n_words++;
	return 1;
	
	if(words_list == nullptr){
		return -2;
	}
	
}


/* Funtion: erase
*/
int	WordList::erase(const char word[]) {

	// TODO:
	int count = 0;

	if(words_list == nullptr){
		return -2;
	}
		for(int i = 0; i < n_words; i++){
			if(strcmp(words_list[i],word) == 0){
                for(int j = i; j < n_words-1; j++){
					
                    strcpy(words_list[j],words_list[j+1]);
					
               }
           		 n_words--; count++;
			}		
		}
		// n_words--;
		
return count;


}


/* Funtion: prepend
Specification: Prepends the contents of *src to the WordList. 
If WordList does not have enough space
prepend should dynamically allocate enough space to
prepend the contents of *src to WordList,
returns number of words prepended. 
If *src is nullptr or empty prepend does nothing and returns 0. If
this WordList::words_list is nullptr everything above still applies 
except returns -2.
*/
int	WordList::prepend(const WordList* src) {

	// TODO:
	if(src == nullptr){
		return 0;
	}
	int check = 0;
	if(capacity <= n_words + src->n_words){
		int temp = count();
		temp++;
		char ** templist = new char*[temp];
		for (int i = 0; i < temp; i++) {
			templist[i] = new char[20];
		}
		//Then copy over the words from the original list and then the new words
		for(int i = 0; i< n_words; i++){
   			 strcpy(templist[i], words_list[i]);
		}
	
		for(int i = 0; i < capacity; i++){
			delete [] words_list[i];
		}
			delete [] words_list;
		
		capacity = temp;
		
		words_list = templist;
		
	}
		for(int i = 0; i<src->count(); i++){
		insert(src->get(i));	
		check++;
		}
	
	return check;

	if(words_list == nullptr){
		return -2;
	}

}


/* Funtion: search
*/
int WordList::search(const char word[]) const {

	// TODO:
	if(words_list == nullptr){
		return -2;
	}

	for(int i = 0; i < n_words; i++){
		if(strcmp(words_list[i],word) == 0){
			return i;
		}else{
			return -1;
		}

	}
	return -1;
}


/* Funtion: sort
Specification: If WordList is nullptr return -2.
 If there is only one word in the words_list return 1.
Otherwise, sort sorts the words in WordList in ascending order 
if asc is true and descending order 
if asc is false, returns 0. 
You may not use any built-in sorting function provided by your environment,
Implement your own sorting algorithm.
*/
int	WordList::sort(bool asc) {

	// TODO:
	if(words_list == nullptr){
		return -2;
	}
	if(n_words == 1){
		return 1;
	}
	int count = 0;
	char** temp = new char*[capacity];
	for(int i=0; i<capacity; i++){
		temp[i] = new char[20];
	}
	cout << endl;
	if(asc == true){
		for(int j=0; j<(n_words*5); j++){
			for(int i=n_words-1; i>0; i--){
				if(strcmp(words_list[i],words_list[i-1]) > 0){
				temp[i] = words_list[i];
				words_list[i] = words_list[i-1];
				words_list[i-1] = temp[i];
				}
			}
		}
	}else{
		return 0;
	}
	// if(asc == true){
	// 	for(int j=0; j<(n_words*5); j++){
	// 		for(int i=0; i<n_words-1; i++){
	// 			if(strcmp(words_list[i],words_list[i+1]) > 0){
	// 			temp[i] = words_list[i];
	// 			words_list[i] = words_list[i+1];
	// 			words_list[i+1] = temp[i];
	// 			}
	// 		}
	// 	}
	// }else{
	// 	return 0;
	// }
	// int dummyreturnval = -9000;
	// return dummyreturnval;
	return 0;
}


/* Funtion: Assignment Operator  
*/
WordList& WordList::operator=(const WordList &src) {

	// TODO:
	if( &src == this){return *this;}

	for(int i=0; i<capacity; i++){
		delete [] words_list[i];
	}
		delete [] words_list;
	
	n_words = src.n_words;
	capacity = src.capacity;
	words_list = new char*[capacity];
	for(int i = 0; i<capacity; i++){
		words_list[i] = new char[20];
	}

	for (int i = 0; i < n_words; i++) {
        strcpy(words_list[i], src.words_list[i]);
    }
	return *this;

}

















