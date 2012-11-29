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


/**
//http://opendatastructures.org/versions/edition-0.1e/ods-java/12_2_AdjacencyLists_Graph_a.html
//somewhat helpful for strategy, not for code
*/


/**
* argument constructor
* default list graph: have to create a vector of lists, index = node of (adj vertex & edge weight)
*/
ListGraph::ListGraph(int numNodes){
	
	//initalize private vars
	num_edges = 0;

	//Preconditions:
	if (numNodes > 0 ){
	// loop through numNodes and add our Elist
		for(int i = 0; i < numNodes; i++){
			edgeList.push_back(EList(NULL));	// make the Elist item, which is a list remember, null
		}
	} // end if
	
} // end ListGraph constructor


/**
// destructor: to clean up list
*/
ListGraph::~ListGraph(){
	// ceratinly don't want to call 'delete', would cause memory err since we didn't create it
}   // end list destructor


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
	// check for duplicates in List, because they would add to the tail, unlike Matrix (which gets overwritten)
	bool duplicate = false;
	//Preconditions:check and see if points are valid matrix points
	if(u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size() && u!= v && weight > 0){
	
		// check and see if  points are duplicates (tho I guess we could overwrite them if they are)
		// wait, no, it would just add additionally to the list so test for duplicates!
		// can overwrite in the Matrix however
		// have to iterate thru edgeList
		EList::const_iterator iter;
		for(iter = edgeList.at(u).begin(); iter !=edgeList.at(u).end(); iter++){
			NWPair tPair = (*iter);							// it's it is not a pointer, an overloaded method which pretends to be derefferencing
			if (tPair.first == v &&  tPair.second == weight){	
				duplicate = true;							// if so, then bail out					
			 } // end if
			}  // end for

	if (!duplicate){	
		// if not a duplicate: add weight
		edgeList.at(u).push_back(NWPair(v,weight)); // have to add weight to u's list
		edgeList.at(v).push_back(NWPair(u,weight)); // have to add weight to v's list 
		num_edges++;								// increase num_edges
	}
  }
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
	
	//Preconditions: check to see if points are in matrix,
	if(u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size()){	// if our nodes are valid
		
		// if so then somehow iterate through list, ==> from class notes 
		// and return an EdgeWeight:  double EdgeWeight;
		
		EList::const_iterator iter;
		for(iter = edgeList.at(u).begin(); iter !=edgeList.at(u).end(); iter++){
			NWPair tPair = (*iter);							// it's it is not a pointer, an overloaded method which pretends to be derefferencing
			if (tPair.first == v) {							// if the first of the pair, NODEid = v
				return tPair.second;						// return weight
			 }
			}	
		return 0;
	} // end if

}	  // end weight



/**
*getAdj
*@param: NodeID u
* Returns a list of NodeID/EdgeWeight pairs adjacent to the edge
* @return: 
*/
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	
	// Preconditions: u is a legal label.
	if (u >= 0 && u < edgeList.size() ){
		// one thought, adj are those which are in the same list, return the list at u (the index),  
		// yep, thats the idea from class but BO says this way is easier to debug
		std::list<NWPair> ret = edgeList.at(u);
		return ret;
	}
}



/**
* degree
* @param NodeID u
* Returns number of nodes neighboring node u
* @return: unsigned
*/	
unsigned ListGraph::degree(NodeID u) const{
	
	//precondition
	if(u >= 0 && u < edgeList.size()){		//check bounds to see if u is in list
		return getAdj(u).size();			// call getAdj, to access the list at u.
											// it's size() is the number of items in the adjList
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