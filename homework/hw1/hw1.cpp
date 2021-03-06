/*
   SR Kanna
   4/14/2014
   CS163
   HW1
   HW1.H

Purpose of program: This program assists in the grading process by taking in a students information, such as their first and last name and results in a specific class and and outputs whether they pass or not. It can take in multiple students, list them alphabetically and by order of performance.


Purpose of file: the .h file is for the application program. It's a human readible file. 

*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct student
{
	char * last_name;			//dynamically allocated
	char * first_name;			//dyn allocated
	int  prof_demo;				//for prof demo scores
	int composite_grade;			//used to calculate composite grade
	int lab_attendance;			//for lab attendance records
};



struct node
{
	node * next;				//to traverse
	student * data;				//so the data does not overwrite

};


void copy(student &, student &);		//this copies the previous information "a deep copy"
void user_input(student & data);		//user input function outside the class



class info
{
	public:
		info();					//constructor
		~info();				//deconstructor
		int insert(student &);			//read info from struct into LLL, takes student struct
		int prof_insert(student *);		//inserts into prof demo LLL, takes student pointer as argument
		int update(char last_name[],int choice,int update);	//updates info, uses last name to identify student, choice to tell which grade and update for the new info
		int display_all();			//display each student's info
		int display_prof(student &);		//display prof demo scores, takes student struct as arg
		int evaluate(student &);		//evalutes which students pass, takes in struct as arg

	private:
		node * head;				//for first LLL
		node * phead;				//for second LLL

};
                                                                                                                                                                                                                                                                        hw1_main.cpp                                                                                        0000600 0013410 0000454 00000004514 12323415164 012432  0                                                                                                    ustar   kannasr                         them                                                                                                                                                                                                                   /*
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
