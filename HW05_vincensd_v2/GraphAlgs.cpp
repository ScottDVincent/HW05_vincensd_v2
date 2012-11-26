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
//float BestTourDistance;
//std::pair<std::vector<NodeID>, EdgeWeight> solution;
//return solution;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G); //TSP is var name for the pair

//Graph::Graph() {
//}	// end Graph constructor ?? do I need a constructor for this

		

// put in Tour() code here
/**
	void tour(int* arr, int n, int StartingPlace) {
		int  bestDistance;						// set to something arbitrary

			if (n-StartingPlace == 1) {			// base case

				//BestVec<> =						// keep that last path;	
			
					if (distance < bestDistance){
						 bestDistance = distance;// save new bestDistance
						 return;
					} else if (check to see something){
						for ( i = StartingPlace, i <= n; i++){
						swap (StartingPlace, i);		 //swap poistion so that all columns to the right of i are called in this algo and are checked.
						tour (arr, n ,StartingPlace +1); // do the recursive call and move Staritng Place up one column
						swap (StartingPlace, i);		// be sure and swap our elements back so that the new, updated starting place will be recursilly call correctly
						} //end for


	} // end tour
*/

/**
void swap (int StartingPlace, int i){
		int temp;
		temp = StartingPlace;
		StartingPlace = i;
		i = StartingPlace;

 } // end swap


/**
* this may not actually do anything

TSP(Graph* G) {
	return solution;
}
*/

