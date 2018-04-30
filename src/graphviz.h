#ifndef GRAPHVIZPP_LIBRARY_H
#define GRAPHVIZPP_LIBRARY_H

#include <string>
#include <vector>


namespace graphivizpp{
    class Graph{

        class Statement{

            enum Attribute{
                Graph,
                Node,
                Edge
            };

            std::vector statement_list;
        };
        bool directed = false;
        bool strict = false;
        std::string id = "";

    };
}


#endif