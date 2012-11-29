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
//int* bestTour;
//double BestTourDistance;
//std::pair<std::vector<NodeID>, EdgeWeight> solution;


// might be helpful to review
// http://www.adaptivebox.net/CILib/code/tspcodes_link.html
// nope, way over my head

/**
GraphAlgs::GraphAlgs() {

}	// end Graph constructor 
?? do I need a constructor for this ~> prolly not
*/


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G); 


// ?? what about Dykstras shorest path algorithm ??
	/**Dijkstra's idea: from c++: p443, but it's not really compatible w/ tour
		3 vectors:
		int distance [MAX_DISTANCE_SIZE];
		int path [MAX_PATH_SIZE];
		vector<bool> included(MAX_INCLUDED_PATH);
		

/**
*tour ()
*@param int* arr
*@param int n
*@param int StartingPlace
* returns void
*/
/** 
	void tour(int* arr, int n, int StartingPlace) {
		
	//strategy
	// we take in a pointer to an array, n is the length of the array,
	// StartingPlace is the place it we start counting from in the array

		//set a default distance 
		double distance = 0.0;					// set to 0
		double bestDistance = 0.0;				// save our best distance so far

		// create vectors to hold distances
		?? we talked about <NodeID> in class, so I'm assuming that's our vec type
		std::vector<NodeID> curTourVec;			// contains the current tour, we'll add the weight
		std::vector<NodeID> bestTourVec;		// save a vector of best tour route


	 	// our base case to end recusion
		if (n-StartingPlace == 1) {				// base case

		// weights are put on the stack, or put them in my vector tour
		??	curTourVec = ordered list of route
		// sum these values of this permutation, see if it's smaller than bestSeen
		?? distance = sum of tour values
		// loop thru list and add weights for sum
		?? where do we get the weights from ==> NodeID somehow ??

		//check our distance values					
			if (distance < bestDistance){	// on 1st iter: dist WILL NOT be less than bestDistance (at 0)
				 bestDistance = distance;	// save new bestDistance
			     bestTourVec = curTourVec;	// keep that last path;
					 ?? return;
			
			} else {						// (run thru list and put weights on stack)
				
			for (int i = StartingPlace; i <= n; i++){
						
				??pass by value or reference ??
				swap (StartingPlace, i);			//swap poistion so that all columns to the right of i are 
													// called in this algo and are checked.
				
				tour (arr, n, StartingPlace +1);	// do the recursive call and move Staritng Place up one column
				
				swap (i, StartingPlace);			// be sure and swap our elements back so that the new,
													// updated starting place will be recursivly called correctly
	
			}	//end for
		}		// end if
	}			// end tour

*/



/**
* swap()
* @param int Starting Place
* @param int i
* swaps the values of i and StartingPlace)
* return void

?? can I just use the standard c++ swap() 

void swap (int* StartingPlace, int* i) {	// use pointers, see pg 442
		int* temp;
		temp = StartingPlace;
		StartingPlace = i;
		i = StartingPlace;

 } // end swap
*/



/**
* this may not actually do anything, not sure what I'm thinking
TSP(Graph* G) {
	return solution;
}
*/

