/*
   SR Kanna
   4/28/2014
   CS163
   HW2
   QUEUE.H

   PURPOSE of Assignment: This program is a triva game which engages the reader through a deck and a discard deck. If the user answers a question right, it goes into back into the deck of cards. But if they enter it wrong, it goes into the disard. A score of 5 wins the game.


   PURPOSE of file: the .h is for the application program. It's a human readible file.

 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

//The ADT is a CLL

struct question
{
	char * a_question;				//dynamically allocated question
	char * answer;					//dyn allocation answer for the trivial question
	void copy(question &);				//copy function to make sure not to overwrite information
};

struct q_node
{
	question trivial;				//instance of "Card"
	q_node * next;					//next pointer
};

class queue
{
	public:
		queue(void);
		~queue(void);
		int read_in(void);				//function to read in info from 
		int enqueue(question &);		//function to add to queue
		int dequeue(question &);		//function to remove data
		int display(void);				//function to display all of the data (testing purposes)
		int display_first(void);			//function to display the top card to user
		int is_match(char user_answer);		//function to evaluate if what the user entered matches what the answer is
		int peek(question &);			//function peeks at the top card
	private:
		q_node * ptr;				//rear pointer
};
