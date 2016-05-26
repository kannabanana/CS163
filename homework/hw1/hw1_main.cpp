/*
   SR Kanna
   4/14/2014
   CS163
   HW1
   HW1_MAIN.CPP

Purpose of file:This is hw1_main.cpp file which contains the "user" interface and calls all the functions

INPUT:
	Data is gathered through the user_input function which is called in main. The user inputs student information into a struct which then loads the information into the ADT.

OUTPUT:
	The main will carry the user through a test bed, which will eventually display the finished student roster, organized by last name and by proficiency demo score. It will also show the students who have passed the course.

 */


#include "hw1.h"
using namespace std;

int main()
{
	char temp[500];			//temp used for dynamically allocated
	char response;			//for user response
	int num;			//for possible errors
	char * last_name;		//for user last name
	int choice;			//to input user's choice -which grade to update
	int update;			//to input user's new grade
	info cs162;			//declaring an instance

	do {
		'\n';
		'\n';

		cout << "Welcome to Karla's 162 class. Please enter a student's info. ";
		student data;
		user_input(data);			//gets user's data and puts into struct

		num = cs162.insert(data);			//inserts into LLL
		
		cout << "Displaying Student information by last name: " << endl << endl;
		num = cs162.display_all();			//displays first LLL

		cout << "Would you like to update a student's information? Y/N? ";
		cin >> response;  cin.ignore(100,'\n');
		if ('Y' == toupper(response))
		{
			cout << "Please enter the student's last name you wish to update. Please make an exact match to entered data: ";
			cin.get(temp,200,'\n');	cin.ignore(100,'\n');

			char * last_name = new char[strlen(temp)+1];
			strcpy(last_name,temp);

			cout << "Which score would you like to update? 1 composite grade. 2 lab attendance. 3 for proficiency demo. ";
			cin >> choice; cin.ignore(100,'\n');
			cout << "What would you like the new score to be? ";
			cin >> update; cin.ignore(100,'\n');

			num = cs162.update(last_name,choice,update);
		}

		cout << endl << endl;
		cout << "Display proficiency demo scores: " << endl;
		num = cs162.display_prof(data);

		cout << endl << endl;
		cout << "Evaluating students performance: " << endl;
		num = cs162.evaluate(data);

		cout << "Do you want to continue adding students? Y/N.";
		cin >> response; cin.ignore(100,'\n');

	}
	while ('Y' == toupper(response));

	return 0;
}
