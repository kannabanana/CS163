/*
SR Kanna
5/29/2014
CS163
HW4
MAIN.CPP

Purpose of file: This is the main.cpp file which contains the user interface and calls the functions


INPUT:
Data is gathered through an external data file which is called in main. The user has the opportunity to specify a location to see details for or remove.

OUTPUT:
The main will carry the user through a test bed, which will eventually display all activities, a specific location and display the remaining results after removing the result of their choice, before removing all.
*/

#include "hw4.h"
using namespace std;

int main ()
{
	table BST;		//class instance
	char array[1000];	//temporary array for dynamically allocating memory

	cout << "Welcome to the DISCOVER OREGON activities guide." << endl << endl;
	BST.read_in();		//function to read in from external data file
	BST.display_all();	//function to display all

	cout << endl << endl;
	cout << "Please enter a location to find activities from and remove: ";
	cin.get(array,1000,'\n');	cin.ignore(100,'\n');

	char * location = new char[strlen(array)+1];
	strcpy(location,array);

	BST.retrieve(location);		//function to retrieve a specific location
	BST.remove_specific(location);	//function to remove the specific location
	cout << endl << endl;
	BST.display_all();		//function to display all again
	BST.remove_all();		//function to remove all
	BST.display_all();		//function to display all-prove remove all works
	return 0;
}
