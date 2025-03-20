#include "get_distances.hpp"
#include <queue>

std::vector< int > src::getDistances(const std::vector< std::vector< int > > & graph, int currentVertex)
{
  std::vector< int > res(graph.size(), -1);
  std::queue< int > traverseQueue;
  traverseQueue.push(currentVertex);
  res[currentVertex] = 0;
  constexpr int EDGE_SIZE = 1;
  while (!traverseQueue.empty())
  {
    int cur = traverseQueue.front();
    traverseQueue.pop();
    for (const auto & el: graph[cur])
    {
      if (res[el] == -1)
      {
        res[el] = res[cur] + EDGE_SIZE;
        traverseQueue.push(el); 
      }
    }
  }
  return res;
}