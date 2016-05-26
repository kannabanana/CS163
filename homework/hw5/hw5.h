/*
   SR Kanna
   CS163
   HW5
   CS163
   HW5
   HW5.H

   Purpose of porgram: This program assists in finding various routes from Beaverton to Portland. It does not take in user information because it comes from the external data file. It sorts them by intersections and street names.


   Purpose of file: the .h file is for the application program. It's a human readible file.

 */
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;


struct vertex
{
	int name;				//name of intersection
	struct edge * head;			//pointer to edge list
};


struct edge
{
	vertex * adjacent;			//what the vertex points to next
	edge * next;				//what the next pointer in the edge list is
	int vertex1;				//first intersection which road connects to
	int vertex2;				//section vertex which the road connects to
	char * road_name;			//dynamically allocated road name
};


class graph
{

	public:
		graph(int size=6);					//constructor of size 6
		~graph(void);						//deconstructor
		void read_in_vertex(void);				//read in info from external data file (vertex) into adjacency list
		void read_in_edges(void); 				//read in from external data file into linked list
		int insert_vertex(int name);				//insert from external data file to 
		int find_location(int key_value);			//function figure out the location of the vertex by giving the index
		int insert_edge(int first,int to_attach,char * road_name);	//function to connect edge and name it from one vertex to another

		void display_adjacency(void);				//function to display adjacent edges
		void display_adjacency_assist(edge * head);		//recursive function to display adjacent edges
		void wrapper_depth(void);				//wrapper function fo depth first display
		int depth_first(vertex * current);			//function to display path from first index to last	

	private:
		vertex * adjacency_list;
		int list_size;
};
