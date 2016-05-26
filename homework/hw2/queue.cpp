/*
   SR Kanna
   4/28/2014
   CS163
   HW2
   QUEUE.CPP

   This is queue.cpp which contains all the algorithms and functions to be implemented and called by my circular linked list ADT

 */


#include "queue.h"
using namespace std;

//constructor
queue::queue()
{
	ptr = NULL;	//circular?
}



//deconstructor
queue::~queue()
{
	if (ptr != NULL)
	{
		q_node * current = ptr->next;
		ptr-> next = NULL;
		while (current != NULL)
		{
			ptr = current->next;
			delete current;
			current = ptr;
		}
	}
}



//function to load information from external data file into temp struct
int queue::read_in()
{
	question temp_question;
	char temp[400];
	ifstream file_in;
	file_in.open("trivial.txt");
	if(!file_in)
		return 1;
	else
	{
		while(!file_in.eof())
		{
			file_in.get(temp,400,'?');
			file_in.ignore(100,'?');
			temp_question.a_question = new char[strlen(temp)+1];
			strcpy(temp_question.a_question,temp);	

			file_in.get(temp,400,'\n');
			file_in.ignore(100,'\n');
			temp_question.answer = new char[strlen(temp)+1];
			strcpy(temp_question.answer,temp);

			if(strlen(temp) > 0)
				enqueue(temp_question);
			delete []temp_question.a_question;
			delete [] temp_question.answer;
		}
	}
}



//function to add to the queue
int queue::enqueue(question & trivial)
{
	if (ptr == NULL)
	{
		//add a q_node;
		ptr = new q_node;
		ptr -> trivial.copy(trivial);
		ptr -> next = ptr;
		return 1;
	}

	else
	{
		//add a new q_node;
		q_node * temp, *current;
		current = ptr->next;
		temp = new q_node;
		temp -> trivial.copy(trivial);

		temp->next = ptr;
		while(current-> next != ptr)
		{
			current = current->next;
		}
		current->next = temp;
		ptr = temp;
		return 1;
	}
}



//function to copy information
void question::copy(question & trivial)
{
	a_question = new char[strlen(trivial.a_question)+1];
	strcpy(a_question,trivial.a_question);

	answer = new char[strlen(trivial.answer)+1];
	strcpy(answer,trivial.answer);
}



//function to remove from the queue
int queue::dequeue(question & trivial)
{
	if (ptr == NULL) return 0;
	else
	{
		q_node * temp, *current;
		current = ptr->next;
		temp = ptr;
		while(current->next != ptr)
		{
			temp = current;
			current = current->next;
		}
		temp->next = ptr;
		trivial.copy(current->trivial);
		if (current == ptr){
			ptr = NULL;
		}
		delete current;
		return 1;
	}
}



//function to display the entire queue
int queue::display()
{
	if (ptr == NULL) return 0;
	else
	{
		q_node * current = ptr->next;
		do
		{
			cout << current->trivial.a_question << " ";
			cout << current->trivial.answer << " ";

			current = current->next;
		}
		while (current != ptr->next);
	}
}



//function which displays the top card
int queue::display_first()
{
	if (ptr == NULL) return 0;
	else
	{
		//display the front
		q_node * current = ptr->next;
		while(current->next != ptr)
		{
			current = current->next;
		}
		cout << current-> trivial.a_question << " ";
	}
}



//function to see if answers match
int queue::is_match(char response)
{
	if (ptr == NULL) return 2;
	else
	{
		//traverse to the front and check if the answer is the same as the user entered match
		q_node * current = ptr->next;
		while(current->next != ptr)
		{
			current = current->next;
		}
		if (current->trivial.answer[0] == response)
			return 1;
		else return 0; 
	}
}



//function to see the top card
int queue::peek(question & trivial)
{
	if (ptr == NULL) return 0;
	else
	{		
		q_node * current = ptr->next;
		current->trivial.copy(trivial);
		return 1;
	}
}
