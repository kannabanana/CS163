/*
SR Kanna
4/28/2014
CS163
HW2
MAIN.CPP

PURPOSE OF FILE:

INPUT:
	Data is gathered though the external file and is_match function which gathers the user's guess. The user also gets to decide whether they want to interact with the deck/discard pile.

OUTPUT:
	The is_match function will then determine whether the answer was correct and output a error message (based on the return value). The output messages are whether they got the correct answer, updated score and a new question.

*/


#include "stack.h"

using namespace std;

int main()
{
	int count = 0;			//how many questions 
	int score = 0;			//how many right answers
	int error;			//error messages
	char response;			//user answer to question
	int deck_choice;		//whether the user wants to use the deck,discard or peek
	queue deck;			//instance of class deck
	stack discard;			//instance of class discard
	question trivial;		//instance of struct trivial

	cout << "Welcome to the Ultimate Harry Potter Trivia Game. Get ready to loose. " << endl << endl;
	cout << "Only 5 correct answers make you a winner. " << endl;

	deck.read_in();


	deck.display_first();
	cout << "Enter your guess. T/F: ";
	cin >> response;	cin.ignore(100,'\n');
	response = toupper(response);				//whether user enters lower or uppercase
	error = deck.is_match(response);
	if (error == 0)
	{
		cout << "Wrong. ";
		deck.peek(trivial);
		deck.dequeue(trivial);
		discard.push(trivial);
	}
	if (error == 1)
	{
		cout << "Correct! ";
		++score;
		deck.peek(trivial);
		deck.dequeue(trivial);
		deck.enqueue(trivial);
	}
	if (error == 2)
		cout << "I'm sorry there are no more cards in the deck. ";

	while (count < 6 && score < 5)				//number of questions and high score
	{	
		cout << "Would you like to get a question from the discard or deck of cards? Enter 1 for deck. 2 for discard. 3 to peek at the dicard deck. ";
		cin >> deck_choice;	cin.ignore(100,'\n');
		if (deck_choice == 1)
		{
			deck.display_first();
			cout << "Enter your guess. T/F: ";
			cin >> response;	cin.ignore(100,'\n');
			response = toupper(response);
			error = deck.is_match(response);
			if (error == 0)
			{
				cout << "Wrong. ";
				deck.peek(trivial);
				deck.dequeue(trivial);
				discard.push(trivial);
			}
			if (error == 1)
			{
				cout << "Correct! ";
				++score;
				deck.peek(trivial);
				deck.dequeue(trivial);
				deck.enqueue(trivial);
			}
			if(error == 2)
				cout << "I'm sorry there are no more cards in the deck. ";
		++count;
		}

		if (deck_choice == 2)
		{
			int num = discard.peek(trivial);				//for error messages
			if (num == 0)
				cout << "There are no cards in the discard deck. ";
			if (num == 1)
			{	discard.display_card(trivial);
				cout << "Enter your guess. T/F: ";
				cin >> response;	cin.ignore(100,'\n');
				response = toupper(response);
				error = discard.is_match(response,trivial);
				if (error == 0)
					cout << "Wrong. ";
				if (error == 1)
				{
					cout << "Correct!";
					++score;
				}
			} }

		if (deck_choice == 3)
		{
			int num = discard.peek(trivial);				//for error messages
			if (num == 0)
				cout << "There are no cards in the discard deck. ";
			if (num == 1)
				discard.display_card(trivial);

		}
		cout << endl << endl;
		cout << "Your score is: " << score << endl;
		if (score == 5)
			cout << "WINNER! Did you cheat? " << endl;
	}
	return 0;
}
