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
* argument constructor
//http://opendatastructures.org/versions/edition-0.1e/ods-java/12_1_AdjacencyMatrix_Repres.html	
// interesting, idea of List being in a Matric, might be handy with std::list<NWPair>
*/
MatrixGraph::MatrixGraph(unsigned num_nodes) {
	//initalize private vars
	num_edges = 0;

	// strategy
	// have to create a vector of vectors, vertice by vertice w/ inital edgeWeight = 0
	// do a double nested loop to create 2xVector
	
	//? what holds our weight values tho ? maybe another list or vector?
	// hmmm... vector of vectors for matrix and a vector which holds weights? that's what the book shows, oh man, that's confusing!
	// http://stackoverflow.com/questions/4320085/vector-of-vector-initialization
	// http://stackoverflow.com/questions/6491251/multi-dimensional-vector-initialization?rq=1


	//row: u
	M.resize(num_nodes);						//resize row
	for (int i=0; i < num_nodes; i++){
		 //an EdgeWeight is the variable
		 //column: v
		 M.resize(num_nodes);					// resize column (debugger shows it does what I think it will)
		 for(int j = 0; j < num_nodes; j++){
			 
			 //http://www.cplusplus.com/forum/general/69543/
		     // put in a default weight of 0
			 // doesn't work: M[i].assign(weight);			// try different vector method
			  M.at(i).push_back(0);							// add default of '0' (actually puts in 0.0) 

	 }  // end v
	}   // end u

} // end Matrix Graph constructor



	
/**
*destructor to clean up Vector M
*/
MatrixGraph::~MatrixGraph(){
	// didn't really need it
	// ceratinly don't want to just call 'delete', would cause memory err since we didn't create it
	// "if you didn't build it, don't break it"

}

	 
/**
* addEdge()
* @param: NodeID u
* @param: NodeID v
* @param: EdgeWeight weight
* Adds a weighted edge between nodes u and v with the given weight
//http://thecodecracker.com/c-programming/addition-and-deletion-of-nodes-and-edges-in-a-graph/
* @return: void
*/
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	// need to test for duplicates ?? it would just overwrite it if true... only in List

	//Preconditions:
	// test to see if this is an actual location, if u&v are unique and if the weight we are passing in != 0
	if(u >= 0 && u < M.size() && v >= 0 && v < M.size() && u!= v && M.at(u).at(v) == 0 && M.at(v).at(u) == 0 && weight > 0){ 
	
		// add weights to cells ~ seems like this would work, or something like it
		// vector-in-vector syntax:  vector_name.at().at(), I should be thankful it's not a 3d matrix
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
		return M.at(u).at(v);								// if so, return weight of at[u] at[v]
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
	if(u >= 0 && u < M.size()){								// U has to be between 0 and the end of the list
	
	// I think create a pair var to hold adj Nodes -- that's what I'm returning
	// should it be new? should it have a pointer? => yep, else won't compile
	//std::list<NWPair>* nei = new std::list<NWPair>; // a list of the neighbors
	// Wait, just use EList, since it's already declared?
	std::list<NWPair> EList;

	// hmmm... have to loop thru areas around u to see what's adj
	// should I do a nested loop like convo filter (3x3)? ==> no, I think we just want the list of v's associated with the u which is passed it
	// use const_iterator in here? ==> maybe, try a for loop 1st, 
	// is going to go across this row and add each item to
	for (int i=0; i < M.at(u).size(); i++){				// loop thru the u row

		// add a new NWPair (call it 'aNode') to nei list 
		// 'new' isn't right, don't create a new object // just create a new var
		NWPair aNode (i, M.at(u).at(i));				// declare pair 'aNode' (node we're at, the EdgeWeight at that cell)
		
		// well, if an adj has a value (i.e. a weight !=0) then put (node/weight) into new list
		if(aNode.second != 0) 
			//nei -> push_back(aNode);					// put current pair in back of neighbors list
			EList.push_back(aNode);
	} // end for

	// and return nei list
	//return *nei;
	 return EList;
		
	} // end if
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
		//return 0;					// stub compile code
		return getAdj(u).size();	// return something related to getAdj, some unsigned value, prolly the size of the list
	}
  }


/**
* size()
* Returns number of nodes in the graph
* ? not sure if size() will give the correct size, it may be size()*size()
* yes, the total size is s()*s() but...
* no, in that if I do s()*s() then test 8 fails
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


