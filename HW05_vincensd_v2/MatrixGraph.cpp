/*****
 * File		: MatrixGraph.cpp	
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
#include "MatrixGraph.h"

/**
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
*/


/**
* argument constructor
*/
MatrixGraph::MatrixGraph(unsigned num_nodes) {
	//initalize private vars
	num_edges = 0;

	// strategy
	// have to create a vector of vectors, vertice by vertice w/ inital edgeWeight = 0
	// do a double nested loop to create 2xVector
	//? what holds our weight values tho ? maybe another list or vector?
	// hmmm... vector of vectors for matrix and a vector which holds weights? that's what the book shows, oh man, that's confusing!

	//row: u
	for (int i=0; i < num_nodes; i++){
		 //an EdgeWeight is the variable
				 
		 //column: v
		 for(int j = 0; j < num_nodes; j++){
		     // put in weight of 0
			 //doesn't work M[i].assign(weight);			// try different vector method
			 M.at(j).push_back(0);

	 }  // end v
	}   // end u

} // end Matrix Graph constructor

//http://opendatastructures.org/versions/edition-0.1e/ods-java/12_1_AdjacencyMatrix_Repres.html	
//http://thecodecracker.com/c-programming/addition-and-deletion-of-nodes-and-edges-in-a-graph/
	
/**
*destructor to clean up Vector M
*/
MatrixGraph::~MatrixGraph(){
	for(int i = 0; i < M.size(); i++){
		M.at(i).pop_back();				//remove EdgeWeights from matrix: Delete last element
	}
}

	 
/**
* addEdge()
* @param: NodeID u
* @param: NodeID v
* @param: EdgeWeight weight
* Adds a weighted edge between nodes u and v with the given weight
* @return: void
*/
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	//Preconditions:
	// test to see if this is an actual location, if u&v are unique and if the weight we are passing in != 0
	if(u >= 0 && u < M.size() && v >= 0 && v < M.size() && u!= v && M.at(u).at(v) == 0 && M.at(v).at(u) == 0 && weight > 0){ 
	
		// need to test for duplicates ?? it would just overwrite it if true... hmm..

		// add weights to cells ~ seems like this would work, or something like it
		//double vector syntax: two vector.at().at()
		//http://www.cplusplus.com/forum/general/49608/
		//http://stackoverflow.com/questions/2207009/reference-to-element-in-2d-vector-c
		M.at(u).at(v) = weight;  // add weight to cell u/v
		M.at(v).at(u) = weight;	 // add weight to cell v/u
		num_edges++;			 // increse count of num_edges
	}
}



//////////////// IDENTIFIERS //////////////////////	

/**
* weight()
* @param: NodeID u
* @param: NodeID v
*Returns the weight of the edge between two nodes
* @return: EdgeWeight
*/
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{

	// strategy
	//Preconditions: check if u & v are valid
	if(u >= 0 && u < M.size() && v >= 0 && v < M.size()){	// check to see if u,v are in the matrix 
		return M.at(u).at(v);								// if so return weight of at[u] at[v]
	}
	else
		return 0;											// else return 0		
					
}

/**
*getAdj
*@param: NodeID u
* NWPair = <NodeID, EdgeWeight>
* Returns a list of NodeID/EdgeWeight pairs adjacent to the edge
* @return std::list<NWPair>
*/
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
		
	//strategy
	//Preconditions: check and see if u is a valid node in matrix
	// I think create a pair var to hold adj Nodes -- that's what I'm returning

	// hmmm... have to loop thru areas around u to see what's adj
	// should I do a nested loop like convo filter (3x3)?
	// well, if an adj has a value (!=0) then put node/weight into new pair var


}
   
/**
* degree
* @param NodeID u
* Returns number of nodes neighboring node u
* @return unsigned
*/	
unsigned MatrixGraph::degree(NodeID u) const {
	
	//Preconditions: check and see if u is in matrix
	if(u >= 0 && u < M.size()){
		//return something related to getAdj, some unsigned value
	}
  }


/**
* size()
* Returns number of nodes in the graph
* ? not sure if size() will give the correct size, it may be size()*size()
* @return: unsigned
*/
unsigned MatrixGraph::size() const{
	return M.size();
	}


/**
* numEdges()
* Returns the number of edges in the graph
* @return: unsigned
*/
unsigned MatrixGraph::numEdges() const {
	return num_edges;
}


