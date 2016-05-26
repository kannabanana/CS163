/*
   SR Kanna
   5/12/2014
   CS163
   HW3
   MAIN.CPP

   Purpose of the file: This is the main.cpp file which contains the user interface and calls the functions

INPUT:
Data is gathered through an external data file which is called in main. The user has the opportunity to specify a location to see details for or remove.

OUTPUT:
The main will carray the user through a test bed, which will eventually display all activities, a specific location and finally if they choose to the resulting activities if the removed a location.
 */

#include "hw3.h"
using namespace std;


table summer;		//class instance
char temp[1000];	//temporary array for dynamically allocating memory
char answer = 'a';	//to see if the user wants to remove

int main ()
{
	summer.read_in();		//function to read in from external file
	cout << endl << endl;
	cout << "Welcome to the summer activity searcher! " << endl;
	cout << "This is the list of possible activities to do: " << endl;
	summer.display_all();		//function to display all activities

	cout << "Enter a possible location: ";
	cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
	char * location = new char[strlen(temp+1)];
	strcpy(location,temp);
	summer.retrieve(location);		//function to retrieve a certain data's info and will display that info
	cout << endl;
	cout << "Would you like to delete a certain location's activities? Y/N. ";
	cin >> answer;	cin.ignore(100,'\n');
	if ('Y' == toupper(answer))
	{
		cout << "Please enter the location: ";
		cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
		char * location2 = new char[strlen(temp+1)];
		strcpy(location2,temp);
		summer.remove(location2);		//function to remove a certain activity
		summer.display_all();			//final display
	}	
	return 0;
}
