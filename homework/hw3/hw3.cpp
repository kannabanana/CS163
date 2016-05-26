/*
   SR Kanna
   5/12/2014
   CS163
   HW3
   HW3.CPP

   Purpose of file: This is the .cpp which contains the alogrithm and functions to be implemented and called by my ADT.

 */

#include "hw3.h"
using namespace std;


//constructor
table::table(int size)
{
	hash_table = new node *[size];
	for (int i =0; i<size;++i)
	{
		hash_table[i] = NULL;
	}
	hash_table_size = size;
}



//deconstroctor
table::~table(void)
{
	//how to delete all data
	//go through each index of the array and loop through and delete all nodes
	for (int i = 0; i < 5;++i)
	{
//		node * temp = hash_table[i];
		node * temp = *(hash_table + i);
		while (temp != NULL)
		{
		//	hash_table[i] = hash_table[i]->next;
			*(hash_table+i) = (*(hash_table+i))->next;
			delete [] temp->oregon.name;
			delete [] temp->oregon.location;
			delete [] temp->oregon.description;
			delete [] temp->oregon.gear;
			delete temp;
			temp = temp->next;
		}
	}
	delete [] hash_table;
}


//function to read in from external data file
int table::read_in(void)
{
	activities temp_activities;
	char temp[1000];
	ifstream file_in;
	file_in.open("activities.txt");
	if(!file_in)
		return 1;
	else
	{
		while(file_in && !file_in.eof())
		{
			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_activities.name = new char[strlen(temp)+1];
			strcpy(temp_activities.name,temp);

			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_activities.description = new char[strlen(temp)+1];
			strcpy(temp_activities.description,temp);

			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_activities.location = new char[strlen(temp)+1];
			strcpy(temp_activities.location,temp);

			file_in >> temp_activities.difficulty;
			file_in.ignore(100,';');

			file_in.get(temp,1000,'\n');
			file_in.ignore(100,'\n');
			temp_activities.gear = new char[strlen(temp)+1];
			strcpy(temp_activities.gear,temp);

			llow Baumannif(strlen(temp) > 0)
				insert(temp_activities.location,temp_activities);
			delete [] temp_activities.name;
			delete [] temp_activities.description;
			delete [] temp_activities.location;
			delete [] temp_activities.gear;
		}
	}
}



//copy function which performs deep copy
void activities::copy(activities & oregon)
{
	name = new char[strlen(oregon.name+1)];
	strcpy(name,oregon.name);

	location = new char[strlen(oregon.location+1)];
	strcpy(location,oregon.location);

	description = new char[strlen(oregon.description+1)];
	strcpy(description,oregon.description);

	difficulty = oregon.difficulty;

	gear = new char[strlen(oregon.gear+1)];
	strcpy(gear,oregon.gear);
}



//function to figure out which index the activity goes to
int table::hash_function(char * location)
{
	int num = 0;
	int len = strlen(location);
	for (int i=0; i<len; ++i)
	{
		num +=location[i];
	} 
	int answer = (num%hash_table_size);
	return answer;
}



//function to insert into array of LLL
int table::insert(char * key_value,activities & oregon)
{
	int index = hash_function(key_value);
	node * temp = new node;
 	temp -> oregon.copy(oregon);
	temp -> next = hash_table[index];
	hash_table[index] = temp;
}



//function to retrieve and check if there is the location
int table::retrieve(char * location_to_find)
{
	int index = hash_function(location_to_find);
	if  (hash_table[index] == NULL) return 0;
	else
	{
		node * current = hash_table[index];
		while (current != NULL)
		{
			if (strcmp(location_to_find,current->oregon.location)== 0)
				display(current->oregon);
			current = current->next;

		}
	}
}



//function to display a certain activity
int table::display(activities & oregon)
{
	cout << "Name: " << oregon.name << '\t';
	cout << "Location: " << oregon.location << '\t';
	cout << "Description: " << oregon.description << '\t';
	cout << "Difficulty: " << oregon.difficulty << '\t';
	cout << "Gear: " << oregon.gear << '\t';

}



//function to display all activities
int table::display_all(void)
{
	for (int i = 0; i < 5; ++i)
	{
		if (hash_table[i] != NULL)
		{
			node * temp = hash_table[i];
			while (temp != NULL)
			{
				cout << "Name: " << temp->oregon.name << '\t';
				cout << "Location: " << temp->oregon.location << '\t';
				cout << "Description: " << temp->oregon.description << '\t';
				cout << "Difficulty: " << temp->oregon.difficulty << '\t';
				cout << " Gear: " << temp->oregon.gear << endl;
				temp = temp->next;
			}
		}
	}
}



//function to remove a certain activity
int table::remove(char * location)
{
	int index = hash_function (location);
	if (hash_table[index] == NULL)
	{
		return 0;
	}
	if (hash_table[index] != NULL)
	{
		//		node * prev = hash_table[index];
		node * prev = NULL;
		node * temp = hash_table[index];
		while ((strcmp(temp->oregon.location,location) > 0) || (strcmp(temp->oregon.location,location) < 0))
		{
			prev = temp;
			temp = temp->next;
		}
		node * temp2 = hash_table[index];
		//specify that it's in the first location
		if (strcmp(temp->oregon.location,temp2->oregon.location)==0)
		{
			node * temp2 = temp->next;
			delete [] temp->oregon.name;
			delete [] temp->oregon.location;
			delete [] temp->oregon.description;
			delete [] temp->oregon.gear;
			delete temp;
			hash_table[index] = temp2;
		}
		else
		{	
			prev->next = temp->next;
			delete [] temp->oregon.name;
			delete [] temp->oregon.location;
			delete [] temp->oregon.description;
			delete [] temp->oregon.gear;
			delete temp;
			temp = NULL;
		}

		return 1;

	}
}
