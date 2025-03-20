#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "get_distances.hpp"
#include "input_graph.hpp"

int main(int argc, char * argv[])
{
  using namespace src;
  std::vector< std::vector< int > > graph;
  int currentVertex = 0;
  if (argc == 2)
  {
    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
      std::cerr << "Can not open the file\n";
      return 1;
    }
    graph = inputGraph(input, currentVertex);
    input.close();
  }
  else
  {
    std::cerr << "Wrong command line arguments\n";
    return 2;
  }
  std::vector< int > res = getDistances(graph, currentVertex);
  for (const auto & el: res)
  {
    std::cout << el << "\n";
  }
}