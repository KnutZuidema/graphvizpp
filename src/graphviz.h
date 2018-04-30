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

        enum Layout{
            circo,
            dot,
            fdp,
            neato,
            osage,
            patchwork,
            sfdp,
            twopi
        };

        bool directed = false;
        bool strict = false;
        std::string id = "";
        Layout layout = dot;
    };
}


#endif