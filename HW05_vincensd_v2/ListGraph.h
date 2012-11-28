// listGraph.h


#include "Graph.h"

//c++ includes
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>

//using
using namespace std;

#pragma once

typedef std::list<NWPair> EList;			//http://www.cplusplus.com/reference/list/list/

class ListGraph : public Graph {
 public:
  ListGraph(int numNodes);					//input = number of verticies
  ~ListGraph();

  // Modifiers
  virtual void addEdge(NodeID u, NodeID v, EdgeWeight weight);
  
  // Inspectors
  // http://duramecho.com/ComputerInformation/WhyHowCppConst.html
  // http://www.cprogramming.com/tutorial/const_correctness.html

  virtual EdgeWeight weight(NodeID u, NodeID v) const;
  virtual std::list<NWPair> getAdj(NodeID u) const;
  virtual unsigned degree(NodeID u) const;
  virtual unsigned size() const;
  virtual unsigned numEdges() const;

 private:
  ListGraph() {;}

  std::vector<EList> edgeList;				//http://www.cplusplus.com/reference/vector/vector/
											// a vector, in which each item is an EList,
											// which in turn is a std::List,
											// which holds a NWPair (can use first, second) on it.
											// That's deep!
											// gonna have to use NWPair to add (node,weight) in addEdge
  int num_edges;
};
