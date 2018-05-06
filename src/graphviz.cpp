#include <sstream>
#include <fstream>
#include <utility>
#include "graphviz.h"

using namespace graphvizpp;

Node *Graph::add_node(std::string id) {
    auto node = new Node(std::move(id));
    nodes.push_back(node);
    return node;
}

Edge *Graph::add_edge(std::string from, std::string to) {
    auto edge = new Edge(std::move(from), std::move(to));
    edges.push_back(edge);
    return edge;
}

std::string Graph::to_string() {
    std::stringstream out;
    out << (strict ? "strict " : "")
        << (directed ? "digraph" : "graph")
        << "{\n";
    for(const auto &attribute : graph_attributes){
        out << '\t' << attribute.first << '=' << attribute.second << '\n';
    }
    out << '\t' << "node [ ";
    for(const auto &attribute : node_attributes){
        out << attribute.first << '=' << attribute.second << ' ';
    }
    out << "]\n"
        << '\t' << "edge [ ";
    for(const auto &attribute : edge_attributes){
        out << attribute.first << '=' << attribute.second << ' ';
    }
    out << "]\n";
    for(auto &node : nodes){
        out << '\t' << node->id << " [ ";
        for(const auto &attribute : node->attributes){
            out << attribute.first << '=' << attribute.second << ' ';
        }
        out << "]\n";
    }
    for(auto &edge : edges){
        out << '\t' << edge->from << (directed ? " -> " : " -- ") << edge->to << " [ ";
        for(const auto &attribute : edge->attributes){
            out << attribute.first << '=' << attribute.second << ' ';
        }
        out << "]\n";
    }
    out << '}';
    return out.str();
}

void Graph::to_file(const std::string &path) {
    std::ofstream file(path, std::ios_base::out);
    file << to_string();
}
