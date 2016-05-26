/*
   SR Kanna
   6/12/2014
   CS163
   HW5
   MAIN.CPP

   Purpose of file: This is the main.cpp file which containes the user interface and calls all the functions


Input: There is no data gathered from the user, since the route displays the connection from Beaverton to Portland. But the depth first function could potentially be modified to take in take in a vertex. 

Output: It will display the adjacent roads for them and the closest and fastest route from Beaverton to Portland.
 */
#include "hw5.h"
using namespace std;

int main()
{
	//VARIABLES:
	graph travel;

	cout << "Welcome to the Quick Search from Beaverton to Portland! " << endl << endl << endl;

	travel.read_in_vertex();
	travel.read_in_edges();
	travel.display_adjacency();
	cout << "This is the fastest and most consistent route from Beaverton to Portland: " << endl;
	travel.wrapper_depth();
	cout << endl << endl;
	return 0;
}
