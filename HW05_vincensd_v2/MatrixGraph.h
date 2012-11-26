// MatrixGraph.h

#include <vector>
#include "Graph.h"
//c++ includes
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <string>

//using
using namespace std;

#pragma once

typedef std::list<NWPair> EList;


class MatrixGraph : public Graph {
 public:
  MatrixGraph(unsigned num_nodes);  // input = number of verticies: u * v
  ~MatrixGraph();					// destructor

  // Modifiers
  virtual void addEdge(NodeID u, NodeID v, EdgeWeight weight);
  // u: row, v: column
  
  // Inspectors
  // http://duramecho.com/ComputerInformation/WhyHowCppConst.html
  // http://www.cprogramming.com/tutorial/const_correctness.html

  virtual EdgeWeight weight(NodeID u, NodeID v) const;
  virtual std::list<NWPair> getAdj(NodeID u) const;
  virtual unsigned degree(NodeID u) const;
  virtual unsigned size() const;
  virtual unsigned numEdges() const;
 
 private:
 MatrixGraph() {;}

  std::vector<std::vector<EdgeWeight> > M;  // M(atrix) = vector of vectors
  int num_edges;
};