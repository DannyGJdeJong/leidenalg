#ifndef CONDUCTANCEVERTEXPARTITION_H
#define CONDUCTANCEVERTEXPARTITION_H

#include <MutableVertexPartition.h>

class ConductanceVertexPartition : public MutableVertexPartition
{
  public:
    ConductanceVertexPartition(Graph* graph,
        vector<size_t> const& membership);
    ConductanceVertexPartition(Graph* graph);
    virtual ~ConductanceVertexPartition();
    virtual ConductanceVertexPartition* create(Graph* graph);
    virtual ConductanceVertexPartition* create(Graph* graph, vector<size_t> const& membership);

    virtual double diff_move(size_t v, size_t new_comm);
    virtual double quality();

  protected:
  private:
};

#endif // CONDUCTANCEVERTEXPARTITION_H
