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
//return solution;

// might be helpful to review
// http://www.adaptivebox.net/CILib/code/tspcodes_link.html

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G); //TSP is var name for the pair

//Graph::Graph() {
//}	// end Graph constructor ?? do I need a constructor for this ~> prolly not

		
/**
*tour ()
*@param int* arr
*@param int n
*@param int StartingPlace
* returns void
*/

// ?? what about Dykstras shorest path algorithm ??
/** 
	void tour(int* arr, int n, int StartingPlace) {
		

		/**Dijkstra's idea: from c++: p443, but it's not really compatible w/ tour
		3 vectors
		int distance [MAX_DISTANCE_SIZE];
		int path[MAX_PATH_SIZE];
		vector<bool> included(MAX_INCLUDED_PATH);
		

		int distance;								// set to 0
		int  bestDistance;							// set to something arbitrary
		// vector to hold our 

			if (n-StartingPlace == 1) {				// base case

				//BestVec<> =						// keep that last path;	
			
					if (distance < bestDistance){
						 bestDistance == distance;// save new bestDistance
						 return;
					} else { // (check to see something){
						for ( int i = StartingPlace; i <= n; i++){
						swap (StartingPlace, i);			//swap poistion so that all columns to the right of i are called in this algo and are checked.
						tour (arr, n, StartingPlace +1);	// do the recursive call and move Staritng Place up one column
						swap (StartingPlace, i);			// be sure and swap our elements back so that the new, updated starting place will be recursilly call correctly
						} //end for


	} // end tour

	*/

/**
* swap()
* @param int Starting Place
* @param int i
* swaps the values of i and StartingPlace)
* return void


void swap (int StartingPlace, int i){
		int temp;
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

