/*
	SR Kanna
	5/29/2014
	CS163
	HW4
	HW4.CPP

	Purpose of File: This is the .cpp which contains the algorithms and functions to be implemented and called by my ADT.
*/


#include "hw4.h"
using namespace std;


//constructor
table::table()
{
	root = NULL;
}


//calling function to remove all - deallocating memory
table::~table()
{
	remove_all(root);
}


//function to read in from external data file
int table::read_in(void)
{
	summer temp_oregon;
	char temp[1000];
	ifstream file_in;
	file_in.open("activities.txt");
	if (!file_in)
		return 1;
	else
	{
		while(file_in && !file_in.eof())
		{
			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_oregon.name = new char[strlen(temp)+1];
			strcpy(temp_oregon.name,temp);

			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_oregon.description = new char[strlen(temp)+1];
			strcpy(temp_oregon.description,temp);

			file_in.get(temp,1000,';');
			file_in.ignore(100,';');
			temp_oregon.location = new char[strlen(temp)+1];
			strcpy(temp_oregon.location,temp);


			file_in >> temp_oregon.difficulty;
			file_in.ignore(100,';');

			file_in.get(temp,1000,'\n');
			file_in.ignore(100,'\n');
			temp_oregon.gear = new char[strlen(temp)+1];
			strcpy(temp_oregon.gear,temp);


			if(strlen(temp) >0)
				insert(temp_oregon);

			delete [] temp_oregon.name;
			delete [] temp_oregon.description;
			delete [] temp_oregon.location;
			delete [] temp_oregon.gear;

		}
	}
}


//copy function
void summer::copy(summer & oregon)
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


//wrapper function to insert
int table::insert(summer & oregon)
{
	return insert(root,oregon);

}


//function to insert into tree
int table::insert(node *& root,summer & oregon)
{
	if (!root)
	{
		root = new node;
		root->oregon.copy(oregon);
		root->right = NULL;
		root->left = NULL;
		return 0;
	}
	if (strcmp(root->oregon.location,oregon.location) < 0)
		return insert(root->left,oregon);
	else
		return insert(root->right,oregon);
}


//wrapper to display all
int table::display_all()
{
	return display_all(root);
}


//function to display al
int table::display_all(node * root)
{
	if (!root)	return 0;
	display_all(root->left);
	cout << root->oregon.name << '\t';
	cout << root->oregon.location << '\t';
	cout << root->oregon.description << '\t';
	cout << root->oregon.difficulty << '\t';
	cout << root->oregon.gear << '\n';
	display_all(root->right);
}


//wrapper function to retrieve
int table::retrieve(char * location)
{
	return retrieve(root,location);
}


//function to retrieve
int table::retrieve(node * root,char * location)
{
	if(!root) return 0;
	if(strcmp(root->oregon.location,location)== 0)
		display_specific(root,root->oregon);
	if(strcmp(root->oregon.location,location)<0)
		return retrieve(root->left,location);
	else 
		return retrieve(root->right,location);


}


//function to display a specific node's information
int table::display_specific(node * root,summer & oregon)
{
	if (!root)	return 0;
	cout << root->oregon.name << '\t';
	cout << root->oregon.location << '\t';
	cout << root->oregon.description << '\t';
	cout << root->oregon.difficulty << '\t';
	cout << root->oregon.gear << '\n';
}


//wrapper function to remove a specific node
int table::remove_specific(char * location)
{

	return remove_specific(root,location);

}



//function to remove a specific node
int table::remove_specific(node *& root,char * location)
{
	if (!root)	return 0;
	//have no children:
	if (((!root->left && !root->right)) && strcmp(root->oregon.location,location)==0)
	{
		delete [] root->oregon.name;
		delete [] root->oregon.location;
		delete [] root->oregon.description;
		delete [] root->oregon.gear;
		delete [] root;
		root = NULL;
		return 0;
	}
	//have only one child:
	else if (root->left == NULL && strcmp(root->oregon.location,location)==0)
	{
		node * temp = root->right;
		delete [] root->oregon.name;
		delete [] root->oregon.location;
		delete [] root->oregon.description;
		delete [] root->oregon.gear;
		delete [] root;
		root = temp;
		return 0;

	} 
	else if (root->right== NULL && strcmp(root->oregon.location,location)==0)
	{
		node * temp = root->left;
		delete [] root->oregon.name;
		delete [] root->oregon.location;
		delete [] root->oregon.description;
		delete [] root->oregon.gear;
		delete [] root;
		root = temp;
		return 0;
	}
	//have two children:
	else if((root->left != NULL && root->right != NULL) && strcmp(root->oregon.location,location)==0)
	{
		node * temp = root->right;
		if(!(temp->left))
		{
			delete [] root->oregon.name;
			root->oregon.name = temp->oregon.name;
			delete [] root->oregon.location;
			root->oregon.location = temp->oregon.location;
			delete [] root->oregon.description;
			root->oregon.description = temp->oregon.description;
			delete [] root->oregon.gear;
			root->oregon.gear = temp->oregon.gear;
			node * temp2 = temp->right;
			root->right = temp2;	
			delete [] temp;
		}
		else
		{
			node * previous = temp;
			temp = temp->left;
			while (temp->left != NULL)
			{
				previous = previous->left;
				temp = temp->left;
			}	
			delete [] root->oregon.name;
			root->oregon.name = temp->oregon.name;
			delete [] root->oregon.location;
			root->oregon.location = temp->oregon.location;
			delete [] root->oregon.description;
			root->oregon.description = temp->oregon.description;
			delete [] root->oregon.gear;
			root->oregon.gear = temp->oregon.gear;
			previous->left = temp->right;
			delete temp;
		}
		return 0;
	}
	if (strcmp(root->oregon.location,location)<0)
		return remove_specific(root->left,location);
	else
		return remove_specific(root->right,location);

}


//wrapper to remove all
int table::remove_all()
{
	return remove_all(root);

}


//function to remove all
int table::remove_all(node *& root)
{
	if (!root)	return 0;
	remove_all(root->left);
	remove_all(root->right);
	delete root->oregon.name;
	delete root->oregon.location;
	delete [] root->oregon.description;
	delete [] root->oregon.gear;
	delete [] root;
	root = NULL;
}

