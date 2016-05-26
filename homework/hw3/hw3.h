/*
   SR Kanna
   5/12/2014
   CS163
   HW3
   HW3.H

   Purpose of program: This program works similar to a telephone directory where you look up a specific location and see the what summer activities are available. It allows the user to find activities and delete a certain activity.

   Purpose of file: the .h file is for the application program. It's a human readable file.
 */
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//The ADT is a Array of Linked Lists
struct activities
{
	char * name;				//dyn allocated for activity name 
	char * location;			//dyn allocated for acitvity location
	char * description;			//dyn allocated for activity description
	int difficulty;				//scale of difficulty based on previous experiance etc
	char * gear;				//dyn allocated for whether gear is required or not
	void copy(activities &);		//copy function for deep copy
};



struct node
{
	activities oregon;			//instance of activities
	node * next;				//next pointer
};



class table
{
	public:
		table(int size = 5);			//constructor-takes size of array
		~table(void);				//destructor
		int read_in(void);			//function to get info from external file
		int hash_function(char * location);	//function to sort and place into array of lll
		int insert(char * key_value,activities & oregon);	//function to add nodes
		int retrieve(char * location);		//function to retrieve the data of a specific location
		int display(activities &);		//function to display the data of a specific location
		int display_all(void);			//function to display all data options
		int remove(char * location);		//function to remove an activity based on location

	private:
		node ** hash_table;			//head pointer (arrays index contains head pointer **)
		int hash_table_size;			//size of table
};
