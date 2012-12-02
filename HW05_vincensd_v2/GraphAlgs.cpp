/*****
 * File		: GraphAlgs.cpp	
 * Author   : Scott Vincent
 * Date     : 2012-28-10
 * Purpose  : This program will perform several duties required for HW05.
 * Sources  : 


  * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.
 *
 */

//my includes
#include "GraphAlgs.h"

//c++ includes
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

//using
using namespace std;


//MEMBER VARIABLES
double bestDistance;									// our EdgeWeight, type is double in Graph.h
int* orderArr;											// our array we will be using throughout tour()
std::vector<NodeID> bestTourVec;						// save a vector of best tour route
std::pair<std::vector<NodeID>, EdgeWeight> solution;	// return var


// might be helpful to review
// http://www.adaptivebox.net/CILib/code/tspcodes_link.html
// nope, way over my head

// ?? what about Dykstras shorest path algorithm ??
/**Dijkstra's idea: from c++: p443, but it's not really compatible w/ tour
		3 vectors:
		int distance [MAX_DISTANCE_SIZE];
		int path [MAX_PATH_SIZE];
		vector<bool> included(MAX_INCLUDED_PATH);
*/


/**
*TSP()
*@param (Graph* G)
*@return: std::pair<std::vector<NodeID>, EdgeWeight>
* returns a pair (vector with bestTour in NodeID order ,and, the distance of that tour (as EdgeWeight))
*/
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
		
	//initialize tour vars
		bestDistance = 0.0;						
		bestTourVec.resize(G->size());
		orderArr = new int[G->size()]; 
		

	/**strategy
	*/
	//loop through and send each row of the graph to tour = wrong
	// just make an array of the Graph size()
	
		for(int i=0; i < G->size(); i++) {
			 orderArr[i];
			}

		
//call tour: (int* arr, int n, int StartingPlace, Graph* g)
		tour((orderArr),  G->size(), 0, G);

	//} //end for
 
		// update our return var
		//std::pair<std::vector<NodeID>, EdgeWeight> solution;
		solution.first = (bestTourVec);
		solution.second = (bestDistance);
		return solution;

} // end TSP





/**
*tour ()
*@param int* arr
*@param int n
*@param int StartingPlace
* returns void
	// we take in a pointer to an array, the array is the size() of graph
	// all er are doing is changing the place of elements in the array 
	// n is the size() of the graph,
	// StartingPlace is the place it we start counting from in the array
	// G is a pointer to the Graph 
*/

/** */
void tour(int* arr, int n, int StartingPlace, Graph* G) {
		
	//strategy
		//set a default distance 
		double distance = 0.0;					// set to 0
		
		// create vectors to hold distances
		std::vector<NodeID> curTourVec;			// contains the current tour, we'll add the weight
		
		// our base case to end recusion
		if (n-StartingPlace == 1) {				// base case

	
		// 1st
		// weights are put on the stack, or put them in my vector tour?
		// sum these values of this permutation, see if it's smaller than bestSeen
		//?? where do we get the weights from ==> NodeID somehow ?? = no, graph weight->(u,v)
		//?? distance = sum of tour weights
		// loop thru list and add weights for sum

		for (int i = 0; i < (n-1); i++){ 	
			distance +=  G->weight(arr[i], arr[i+1]);  // edgeWeight between u & v
			}
			distance += G->weight(arr[0], arr[n-1]); 	//add end back to beginning as well
			// or, distance += get_tour_length(G, arr);
		

		// 2nd
		// add node order to curTourVec
		// !key! node order is arr, arr is the thing being constantly updated by tour, that was my missing link in undesrtanding the recursive flow
		
		curTourVec.resize(0);				// clear our curTourVec in prep for adding the current tour

		for (int i = 0; i < (n); i++){
			curTourVec.push_back(arr[i]);	// write current tour
			}
		
	
		// 3rd
		//check our distance values					
			if (distance < bestDistance){	// on 1st iter: dist WILL NOT be less than bestDistance (at 0)
				 bestDistance = distance;	// save new bestDistance
				 bestTourVec = curTourVec;	// keep that last path tour ; // use assignment operator 
			}

		// 4th
		// next tour is run


		// 5th
		// when do we break out of our tour ?? 
				//?? return ?? => dont need it, we will fall out and return to TSP when all loops are complete
			
			} else {								// (run thru list and put weights on stack)
				
			for (int i = StartingPlace; i <= n; i++){
						
				//??pass by value or reference ??
				swap (StartingPlace, i);			// swap poistion so that all columns to the right of i are 
													// called in this algo and are checked.
				
				tour (arr, n, StartingPlace +1, G);	// do the recursive call and move Starting Place up one column
				
				swap (i, StartingPlace);			// be sure and swap our elements back so that the new,
													// updated starting place will be recursivly called correctly
	
			}	//end for
		}		// end if
	}			// end tour



/**
* get_tour_length()
* @param Graph* G
* @param int arr
*
* @return EdgeWeight
*/
EdgeWeight get_tour_length(Graph* G, int arr){

	return 0;

}


/**
* swap()
* @param int Starting Place
* @param int i
* swaps the values of i and StartingPlace)
* return void
*/
//?? can I just use the standard c++ swap() 

void swap (int* StartingPlace, int* i) {	// use pointers, see pg 442
		int* temp;
		temp = StartingPlace;
		StartingPlace = i;
		i = StartingPlace;

 } // end swap
