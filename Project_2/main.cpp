/* Project 2 main
*
*	Do not submit this file
*
*/

// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif



/* Main functions
*
*	you may make any changes you want to main to test your functions.
*	We will be using our own to grade.
*
*	I'm using preprocessor directives to layout different mains to test
*	various functions.  I have 5 example mains.  You can insert or replace, 
*	these are here just to illustrate the technique. Cleaner than 
*	commenting/uncommenting blocks of code.
*
*/

// Choose which run to compile
#define RUN1 //RUN1 RUN2 RUN3 RUN4


#ifdef RUN0

// Make sure you understand the tools being used prior to building anything with them.  
// In this case, the functions to manipulate cstrings will be part of your tool set. 
// Might be a good idea to read the section and run some simple programs from the cstring
// section of the spec.

// It is also important to get in the habit of being able to think/implement/test incrementally.
// Break up your tasks into smaller componenets and test as much as possible.  You can think of
// this as a universal law of programming: "The number of bugs grows exponentially with amount of 
// code typed between testing." 

#include"studentinfo.h"
#include"wordlist.h"
#include<iostream>
using std::cout;
using std::endl;

#include<cstring>
using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;

int main() {
	
	//** Setup initial state 
	cout << StudentInfo::name() << endl;
	cout << StudentInfo::id() << endl;

	int max = 5, // Keep track of the max number words	
		num = 0; // Number of words we can currently store
	//Allocate rows, to point to words
	char ** testlist = new char*[max];
	// for each row, allocate space for words
	for (int i = 0; i < max; i++) {
		testlist[i] = new char[20];
	}
	
	// Initialize words
	strcpy(testlist[0], "harry");
	strcpy(testlist[1], "ron");
	strcpy(testlist[2], "hermione");
	num = 3;	// Must be consistent with intended state, 
				// e.g. there are three currently three words.

	cout << testlist[0][4];

	




	//*** Begin code for function
	 
	//STEP 1  of Algorithm
	//...

	//Test STEP 1
	//...

	//STEP 2 of Algorithm
	//...

	//Test STEP 2
	//...

	return 0;
}

#elif defined RUN1  //Test constructor 


#define MAKE_MEMBERS_PUBLIC // This constant will be checked in worlist.h

#include"wordlist.h"
#include<iostream>

#include<assert.h>
using std::cout;
using std::endl;

int main() {
	

	// WordList wordlist(5);
	// WordList existinglist(5);
	// existinglist = wordlist;

	// Assuming we made our member variables public:
	// cout << "Count: " << wordlist.n_words << endl; // Expect 0

	// cout << "Capacity: " << wordlist.capacity << endl; // Expect 5
	WordList *wl = new WordList(5);
// 	// strcpy(wl->words_list[0], "harry");
// 	// strcpy(wl->words_list[1], "ron");
// 	// strcpy(wl->words_list[2], "hermione");
wl->insert("hermione");
wl->insert("ron");
wl->insert("harry");
wl->print();
// // cout<<endl;

// cout << wl->words_list[2][0]<< endl;
// cout << wl->words_list[1]<< endl;
// cout << wl->words_list[0]<< endl;
	

	// wl->print();
// WordList serenity(10);
// serenity.insert("Wash");
// serenity.insert("Book");
// serenity.insert("River");
// serenity.insert("Simon");
// serenity.insert("Kaylee");
// serenity.insert("Jayne");
// serenity.insert("Wash");
// serenity.insert("Inara");
// serenity.insert("Mal");
// serenity.print();
// serenity.erase("Wash");
// // int ret = serenity.erase("Wash");
// // cout << ret<<endl; 
// cout << endl;
// serenity.print();

// WordList wl(4);
// wl.insert("Waldo");
// wl.insert("Is");
// wl.insert("Waldo");
// wl.print();
// int retval = wl.search("waldo");
// if (retval < 0)
// cout << "Not found" << endl;
// cout << retval << endl;

WordList wordlist1(0);
wordlist1.insert("mia");
wordlist1.insert("susannah"); // num 2, max 2 
WordList wordlist2(4);
wordlist2.insert("dean");
wordlist2.insert("holmes");
wordlist2.insert("odetta"); // num 3, max 4
int retval = wordlist2.prepend(&wordlist1);
wordlist2.print(); // print “susannah mia odetta holmes dean\n”
// Assuming member variables are public
cout << endl;
// cout << retval<< " "<< wordlist2.n_words << " " << wordlist2.capacity<<endl; 
// cout << "Count: " << wordlist1.n_words << endl; // Expect 0
// cout << "Capacity: " << wordlist1.capacity << endl; 
// wordlist1.print();


// WordList neverwhere(5);
// neverwhere.insert("Richard");
// neverwhere.insert("Door");
// neverwhere.insert("Carabas");
// neverwhere.insert("Islington");
// neverwhere.insert("Abbot");
// neverwhere.print();
// neverwhere.sort(true);
// cout << endl;
// neverwhere.print();

// 	for (int i = 0; i < wl->count(); i++) {
// 	cout << wl->get(i) << " ";


// } //pritns “harry ron Hermione”
	// WordList ben(5); 
	// WordList ann(4);
	// ann = ben;
	// return 0;
} 
#elif defined RUN2 


#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"


#include<assert.h>

// Same as above but using asserts instead of cout
//
// asserts are a way to check conditions, they will gracefully crash
// the program if the condition is not met.  
//
// This assumes you know what the end state after the function call
// should be.  Effective programmers have in mind test cases prior to 
// implmentation.  You should know what the end state should be after
// any function call.
int main() {
	WordList *wordlist = new WordList(5);

	// Assuming we made our member variables public:
	// If we failed to set our member variables correctly 
	// These assertions will fail
	assert(wordlist->n_words == 0);
	assert(wordlist->capacity == 5);
	

	return 0;
}
#elif defined RUN3

#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"
#include<iostream>
using std::cout;
using std::endl;

// Test insert: Both Constructor and insert must be
// implmented prior to running this code, otherwise
// it will crash.
int main() {
	WordList *wordlist = new WordList(5);
	wordlist->insert("harry");
	wordlist->insert("ron");
	wordlist->insert("hermione");

	// Assuming we made our member variables public:
	cout  << wordlist->words_list[0][2] << endl; // Expect 'r'

	cout  << wordlist->words_list[1] << endl; // Expect "ron"

	return 0;
}

#elif defined RUN4

#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"
#include<assert.h>
#include<cstring>

using std::strcmp;
// Test insert: same as RUN3 but with asserts. Both Constructor and insert 
// must be implmented prior to running this code, otherwise it will crash.
int main() {

	WordList *wordlist = new WordList(5);
	wordlist->insert("harry");
	wordlist->insert("ron");
	wordlist->insert("hermione");
	
	// Assuming we made our member variables public:
	assert(wordlist->words_list[0][2] == 'r' ); // Individual character, can use == 

	assert(strcmp(wordlist->words_list[1], "ron") == 0); // cstring, must use strcmp
	
	return 0;
}
#else

// Playing with memory tracer.  For this to work you have to uncomment
// #include"debugmem.h"  in wordlist.h to have the memory tracer included
// into the project.
//
// Assumes the Constructor, insert are correctly implemented.  Note if there is 
// undefined behavior in any of your code then all bets are off, your code 
// may "appear" correct, may crash, may generate nonesense, all are equally 
// incorrect.  
// 
#define MAKE_MEMBERS_PUBLIC
#include"debugmem.h"
#include"wordlist.h"

#include<iostream>
using std::cout;
using std::endl;
#include<assert.h>

int main() {

	WordList * existinglist = DEBUG_NEW WordList(5); // WordList can store 5 words

	//... Some WordList operations
	existinglist->insert("harry");
	existinglist->insert("ron");
	existinglist->insert("hermione");

	GETMEMORYREPORT();
	cout << "------------------------" << endl;
	if (true) {
		WordList newList(*existinglist); // Copy Constructor
		GETMEMORYREPORT();

	} // Should not result in memory leaks or undefined behavior 


	delete existinglist; 
	GETMEMORYREPORT();
	cout << "------------------------" << endl;
	return 0;
}

#endif