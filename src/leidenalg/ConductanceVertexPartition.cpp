#include "ConductanceVertexPartition.h"

#ifdef DEBUG
#include <iostream>
using std::cerr;
using std::endl;
#endif

ConductanceVertexPartition::ConductanceVertexPartition(Graph* graph,
      vector<size_t> const& membership) :
        MutableVertexPartition(graph,
        membership)
{ }

ConductanceVertexPartition::ConductanceVertexPartition(Graph* graph) :
        MutableVertexPartition(graph)
{ }

ConductanceVertexPartition::~ConductanceVertexPartition()
{ }

ConductanceVertexPartition* ConductanceVertexPartition::create(Graph* graph)
{
  return new ConductanceVertexPartition(graph);
}

ConductanceVertexPartition* ConductanceVertexPartition::create(Graph* graph, vector<size_t> const& membership)
{
  return new ConductanceVertexPartition(graph, membership);
}

/*****************************************************************************
  Returns the difference in modularity if we move a node to a new community
*****************************************************************************/
double ConductanceVertexPartition::diff_move(size_t v, size_t new_comm)
{
  #ifdef DEBUG
    cerr << "double ConductanceVertexPartition::diff_move(" << v << ", " << new_comm << ")" << endl;
  #endif
  size_t old_comm = this->_membership[v];
  double diff = 0.0;
  double total_weight = this->graph->total_weight()*(2.0 - this->graph->is_directed());
  if (total_weight == 0.0)
    return 0.0;
  if (new_comm != old_comm)
  {
    #ifdef DEBUG
      cerr << "\t" << "old_comm: " << old_comm << endl;
    #endif
    // Number of boundary edges
    double cs_old = this->total_weight_to_comm(old_comm);
    double cs_new = this->total_weight_to_comm(new_comm);

    // Number of edges within comm
    double ms_old = this->total_weight_in_comm(old_comm);
    double ms_new = this->total_weight_in_comm(new_comm);

    // Calculate difference
    double diff_old = cs_old / ((2 * ms_old) + cs_old);
    #ifdef DEBUG
      cerr << "\t" << "diff_old: " << diff_old << endl;
    #endif
    double diff_new = cs_new / ((2 * ms_new) + cs_new);
    #ifdef DEBUG
      cerr << "\t" << "diff_new: " << diff_new << endl;
    #endif
    diff = diff_new - diff_old;
    #ifdef DEBUG
      cerr << "\t" << "diff: " << diff << endl;
    #endif
  }
  #ifdef DEBUG
    cerr << "exit double ConductanceVertexPartition::diff_move((" << v << ", " << new_comm << ")" << endl;
    cerr << "return " << diff << endl << endl;
  #endif
  return diff;
}


/*****************************************************************************
  Give the modularity of the partition.

  We here use the unscaled version of modularity, in other words, we don"t
  normalise by the number of edges.
******************************************************************************/
double ConductanceVertexPartition::quality()
{
  #ifdef DEBUG
    cerr << "double ConductanceVertexPartition::quality()" << endl;
  #endif
  // Not yet implemented
  return 0;
}
