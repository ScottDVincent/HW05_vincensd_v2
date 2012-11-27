/*****
 * File		: ListGraph.cpp	
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
#include "ListGraph.h"

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


/**
//http://opendatastructures.org/versions/edition-0.1e/ods-java/12_2_AdjacencyLists_Graph_a.html
//default list graph: have to create a vector of lists, index = node of (adj vertex & edge weight)t
*/



/**
* argument constructor
*/
ListGraph::ListGraph(int numNodes){
	
	//initalize private vars
	num_edges = 0;

	//strategy
	//Preconditions:
	// create a list var
	// loop through numNodes and add to list
	
} // end ListGraph constructor


/**
// destructor: to clean up list
*/
ListGraph::~ListGraph(){

	//strategy
		for(int i = 0; i < edgeList.size(); i++){
		edgeList.pop_back();					// remove items from list
	}	
} // end list destroctor


/**
* addEdge()
* @param: NodeID u
* @param: NodeID v
* @param: EdgeWeight weight
* Adds a weighted edge between nodes u and v with the given weight
* @return: void
*/ 
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

	// strategy
	// //Preconditions:check and see if points are valid matrix points
	// check and see if  points are duplicates (tho I guess we could overwrite them if they are)
	// if so, then bail out
	// if not add the edge 
	// increment edge counter


	
}  // end addEdge


//////////////// IDENTIFIERS //////////////////////	

/**
* weight()
* @param: NodeID u
* @param: NodeID v
* Returns the weight of the edge between two nodes
* http://www.cplusplus.com/reference/list/list/
* @return: Edgeweight
*/
/** */
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	
	//strategy
	//Preconditions: check to see if points are in matrix,
	if(u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size()){	// if our nodes are valid
	
		// if so then somehow iterate through list, see book, and 
		// and return an EDGEweight:  double EdgeWeight;
	// else
	return 0;
	}

} 




/**
*getAdj
*@param: NodeID u
* Returns a list of NodeID/EdgeWeight pairs adjacent to the edge
* @return: 
*/
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	// strategy
	// Preconditions: u is a legal label.
	// not sure yet
	// one thought, adj are those which are in the same list, return the list at u (the index)
}



/**
* degree
* @param NodeID u
* Returns number of nodes neighboring node u
* @return: unsigned
*/	
unsigned ListGraph::degree(NodeID u) const{
	// strategy
	if(u >= 0 && u < edgeList.size()){		//check bounds to see if u is in list
		return getAdj(u).size();			// call getAdj
	}
}

/**
* size()
* Returns number of nodes in the graph
* edgeList is our private var list, use it's size()
* @return: unsigned
*/
unsigned ListGraph::size() const{
	return edgeList.size();
}

/**
* numEdges()
* Return number of edges in the graph
* @return: unsigned
*/
unsigned ListGraph::numEdges() const{
	return num_edges;
}