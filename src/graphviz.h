#ifndef GRAPHVIZPP_LIBRARY_H
#define GRAPHVIZPP_LIBRARY_H

#include <string>
#include <vector>

namespace graphivizpp{

    class Edge{
        std::string id;
        std::string label;
        unsigned double damping = 0.99;
        unsigned double k = 0.3;
        std::string url = "";
    };


    class Node{
        std::string id;
        std::string label;
        std::vector<Edge> edges;
    };


    class Graph{
        bool directed;
        bool strict;
        std::string id;
        std::string label;
        std::vector<Node> nodes;
    };

}


#endif