/*
   SR Kanna
   4/28/2014
   CS163
   HW2
   STACK.CPP

 */


#include "stack.h"
using namespace std;


//constructor
stack::stack()
{
	head = NULL;
	top_index = 0;
}


//deconstructor
stack::~stack()
{
	node * current = head;
	while (current != NULL)
	{
		delete head;
		current = current->next;
		head = head->next;
	}
}



//function to add to the stack
int stack::push(question & to_add)
{
	if (head == NULL)
	{
		head = new node;
		head->trivial = new question[MAX];
		head->trivial[top_index].copy(to_add);
		head->next = NULL;
		++top_index;

	}
	else if (top_index < MAX)
	{
		head->trivial[top_index].copy(to_add);
		++top_index;
	}
	else
	{
		top_index = 0;
		node * temp = new node;
		temp->trivial = new question[MAX];
		temp->trivial[top_index].copy(to_add);
		temp->next = head;
		head = temp;
		++top_index;

	}
}



//function to remove from the stack
int stack::pop(question & trivial)
{
	if (head == NULL) return 0;
	if (head->next == NULL && top_index == 0) return 1;
	if (head->next != NULL && top_index == 0)
	{
		node * temp = head->next;
		delete head;
		head = temp;
	}
	else
	{
		--top_index;
	}
}



//function to display all (testing)
int stack::display()
{
	if (head == NULL) return 0;
	else
	{
		node * one = head;
		for (int i = 0; i < top_index; ++i)
		{
			cout << one->trivial[i].a_question;
			cout << "? " << one->trivial[i].answer << endl;
		}

		node * current = head->next;
		while (current != NULL)
		{
			for (int i = 0; i < MAX; ++i)
			{
				cout << current->trivial[i].a_question;
				cout << "? " <<current->trivial[i].answer;
			}
			current = current->next;
		}
	}
}




//function to look at top card
int stack::peek(question & trivial)
{
	if (head == NULL) return 0;
	if (head != NULL && top_index == 0)
	{
		node * temp = head->next;
		temp->trivial[top_index-1].copy(trivial);
		return 1;
	}
	if (head != NULL && top_index > 0)
	{
		head->trivial[top_index-1].copy(trivial);
		return 1;
	}
}



//function to display top card
int stack::display_card(question & trivial)
{
	cout << trivial.a_question << " ";

}


//function to check if the cards match
int stack::is_match(char user_response,question & trivial)
{
	if (trivial.answer[0] == user_response)
		return 1;
	else return 0;
}
