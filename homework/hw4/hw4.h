/*
   SR Kanna
   5/29/2014
   CS163
   HW4
   HW4.H

   Purpose of this program: This program works similar to a telephone directory where you look up a specific location and see what the summer activities are available. It allows the user to find activities and delete a certain activity.

   Purpose of file: The .h file is for the application program. It's a human readible file.
 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//The ADT is a BST Tree
struct summer
{
	char * name;			//dynamically allocated activity name
	char * location;		//dynamically allocated location
	char * description;		//dynamically allocated description
	int difficulty;			//scale of difficulty based on previous experiance
	char * gear;			//dynamically allocated whether or not gear is necessary
	void copy(summer &);		//copy function for a deep copy
};


struct node
{
	summer oregon;			//instance of activities
	node * right;			//right pointer
	node * left;			//left pointer
};


class table
{
	public:
		table();				//constructor
		~table();				//deconstructor
		int read_in(void);			//function which reads in from external data file
		int insert(summer &);			//wrapper function to insert into tree
		int display_all();			//wrapper function to display all items
		int retrieve(char * location);		//wrapper function to retrieve items
		int remove_specific(char * location);	//wrapper function to remove a specific location
		int remove_all();			//wrapper function to remove all

	private:
		node * root;							//root data
		int display_specific(node * root,summer & oregon);		//function to display specific data entry
		int insert(node *& root,summer & oregon);			//function to insert into BST
		int display_all(node * root);					///function to display everything of BST in order
		int retrieve(node * root,char * location);			//function to retrieve data based on location
		int remove_specific(node *& root,char * location);		//function to remove specific location
		int remove_all(node *& root);					//function to remove all data items
};
