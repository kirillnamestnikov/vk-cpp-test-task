#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "get_distances.hpp"
#include "input_graph.hpp"

int main()
{
  using namespace src;
  std::ifstream input("graph.txt");
  size_t graphVertices = 0, graphEdges = 0;
  input >> graphVertices >> graphEdges;
  std::vector< std::vector< int > > graph = inputGraph(input, graphVertices, graphEdges);
  int currentVertex = 0;
  input >> currentVertex;
  std::vector< int > res = getDistances(graph, currentVertex);
  for (const auto & el: res)
  {
    std::cout << el << "\n";
  }
}