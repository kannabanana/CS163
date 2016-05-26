/*
   SR Kanna
   4/28/2014
   CS163
   HW2
   HW2.CPP

   This is a .h file which contains function prototypes and my ADT
 */

#include "queue.h"
using namespace std;

//data is a LLL of array
struct node
{
	question * trivial;		//pointer to card ("instance of the struct trivial")
	node * next;			//next pointer
};

const int MAX = 5;			//constant which decides how big my array is


//my ADT is a flexible array
class stack
{
	public:
		stack();					//constructor
		~stack();					//deconstructor
		int push(question &);				//function to add cards into flexible array
		int pop(question &);				//function to move cards out of flexible arrays
		int display();					//function to display all (testing purposes)
		int display_card(question & trivial);		//function display the top card
		int peek(question &);				//function to peek at top card
		int is_match(char response,question &);		//function to see if what the user enters is same as answer

	private: 
		node * head;					//first node
		int top_index;					//where data is added in array
};
