#ifndef INPUT_GRAPH_HPP
#define INPUT_GRAPH_HPP

#include <vector>
#include <istream>


namespace src
{
  std::vector< std::vector< int > > inputGraph(std::istream & in, int & currentVertex);
}

#endif