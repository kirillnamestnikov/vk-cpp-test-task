#include "input_graph.hpp"

std::vector< std::vector< int > > src::inputGraph(std::istream & in, int & currentVertex)
{
  size_t graphVertices = 0, graphEdges = 0;
  in >> graphVertices >> graphEdges;
  std::vector< std::vector< int > > res(graphVertices);
  for (size_t i = 0; i < graphEdges; ++i)
  {
    int from = 0, to = 0;
    in >> from >> to;
    res[from].push_back(to);
    res[to].push_back(from); 
  }
  in >> currentVertex;
  return res;
}