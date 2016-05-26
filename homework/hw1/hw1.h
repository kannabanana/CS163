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
