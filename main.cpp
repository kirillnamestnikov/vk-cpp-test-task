#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

std::vector< int > getDistances(const std::vector< std::vector< int > > & graph, int currentVertex)
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

std::vector< std::vector< int > > inputGraph(std::istream & in, size_t graphVertices, size_t graphEdges)
{
  std::vector< std::vector< int > > res(graphVertices);
  for (size_t i = 0; i < graphEdges; ++i)
  {
    int from = 0, to = 0;
    in >> from >> to;
    res[from].push_back(to);
    res[to].push_back(from); 
  }
  return res;
}

int main()
{
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