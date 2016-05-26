/*
   SR Kanna
   6/12/2014
   CS163
   HW5
   HW5.CPP

   This is the .cpp file which containes the algorithm and functions to be implemented and called by my ADT

 */
#include "hw5.h"
using namespace std;


//constructor
graph::graph(int size)
{
	adjacency_list = new vertex[size];
	for(int i = 0;i < size;++i)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].name = 0;
	}
	list_size = size;
}


//deconstructor
graph::~graph(void)
{
	for (int i = 0; i < list_size;++i)
	{
		edge * temp = adjacency_list[i].head;
		while (temp != NULL)
		{
			adjacency_list[i].head = adjacency_list[i].head->next;
			delete [] temp->road_name;
			delete temp;
			temp = adjacency_list[i].head;
		}
		adjacency_list[i].head = NULL;
	}

	delete [] adjacency_list;
}


//function to read in from external data file (vertex)
void graph::read_in_vertex(void)
{
	vertex temp_vertex;
	ifstream file_in;
	file_in.open("vertex.txt");
	if(!file_in)
		return;
	else
	{
		while(!file_in.eof())
		{
			file_in >> temp_vertex.name;
			file_in.ignore(100,'\n');
			insert_vertex(temp_vertex.name);
		}
	}
}


//function to read in from external data file (edges)
void graph::read_in_edges(void)
{
	edge edge_temp;
	char temp [1000];
	ifstream file_in;
	file_in.open("edges.txt");
	if(!file_in)
		return;
	else
	{
		while(!file_in.eof())	
		{
			file_in >> edge_temp.vertex1;
			file_in.ignore(100,';');

			file_in >> edge_temp.vertex2;
			file_in.ignore(100,';');

			file_in.get(temp,1000,'\n');
			file_in.ignore(100,'\n');
			edge_temp.road_name = new char[strlen(temp)+1];
			strcpy(edge_temp.road_name,temp);

			if (strlen(temp) > 0)
			{
				insert_edge(edge_temp.vertex1,edge_temp.vertex2,edge_temp.road_name);
			}
			delete [] edge_temp.road_name;
		}

	}
}



//function to insert vertexes in adjacency list
int graph::insert_vertex(int real_name)
{
	for(int i = 0; i<list_size; ++i)
	{
		if(adjacency_list[i].name == 0)
		{
			adjacency_list[i].name = real_name;
			//	new char[strlen(intersection)+1];
			//	strcpy(adjacency_list[i].entry,intersection);
			return 1;
		}
	}
	return 0;
}



//function to find index based on value
int graph::find_location(int key_value)
{
	for(int i = 0;i < list_size;++i)
	{
		if(adjacency_list[i].name != 0)
		{
			if(adjacency_list[i].name == key_value)
			{
				return i;
			}
		}
	}
	return -1;
}



//function to insert edges
int graph::insert_edge(int current,int to_attach,char * edge_name)
{
	int first = find_location(current);
	int second = find_location(to_attach);
	if(first >= 0 && second >= 0)
	{
		edge * temp = new edge;
		temp->road_name = new char[strlen(edge_name)+1];
		strcpy(temp->road_name,edge_name);
		temp->adjacent = &adjacency_list[second];
		edge * hold = adjacency_list[first].head;
		adjacency_list[first].head = temp;
		temp->next = hold;

		//name the edge?
		return 1;
	}
	return 0;
}



//function to display edges next to adjacency list
//display next to a paticular index
//go through each index and display each name of the adjacent one it's pointing to
void graph::display_adjacency(void)
{
	for (int i = 0; i < list_size;++i)
	{
		if(adjacency_list[i].name != 0)
			cout << "Vertex " << adjacency_list[i].name << " is connected to: ";
		display_adjacency_assist(adjacency_list[i].head);
		cout << endl << endl;
	}
}


//assistining function to display edges next to
void graph::display_adjacency_assist(edge * head)
{
	if (!head)
		return;
	cout << head->adjacent->name << '\t';
	return display_adjacency_assist(head->next);

}


//function to display route from beaverton to portland
void graph::wrapper_depth()
{
	vertex * temp = &adjacency_list[0];
	depth_first(temp);
}



//function to display route from beaverton to portland
int graph::depth_first(vertex * current)
{
	if (!current)
		return 0;
	edge * temp = current->head;
	cout << "The Vertex is: " << current->name << endl;
	if (current->name == 6)
		return 1;

	while (temp)
	{
		cout << "The road name is: " << temp-> road_name << endl;
		if(depth_first(temp->adjacent) == 1)
			return 1;
		temp = temp->next;
	}
	return 0;
}
