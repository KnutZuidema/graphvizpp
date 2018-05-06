#ifndef GRAPHVIZPP_LIBRARY_H
#define GRAPHVIZPP_LIBRARY_H

#include <string>
#include <utility>
#include <vector>
#include <map>

namespace graphvizpp{
    class Node;
    class Graph;

    class Edge{
        friend class Graph;
        std::string from, to;
        std::map<std::string, std::string> attributes;

    public:
        Edge(std::string from, std::string to) :
                from(std::move(from)), to(std::move(to)) {}
    };


    class Node{
        friend class Graph;
        std::string id;
        std::map<std::string, std::string> attributes;

    public:
        explicit Node(std::string id) :
                id(std::move(id)) {}
    };


    class Graph{
        bool directed;
        bool strict;
        std::string id;
        std::vector<Node*> nodes;
        std::vector<Edge*> edges;

    public:
        std::map<std::string, std::string> graph_attributes;
        std::map<std::string, std::string> node_attributes;
        std::map<std::string, std::string> edge_attributes;

        explicit Graph(bool directed, bool strict = false, std::string id = "") :
                directed(directed), strict(strict), id(std::move(id)) {}

        Node* add_node(std::string id);

        Edge* add_edge(std::string from, std::string to);

        std::string to_string();

        void to_file(const std::string &path);
    };

}


#endif