#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "types.hpp"
#include <iostream>
#include <sstream>

class Builder
{
      public:
    class Page
    {
          public:
        std::string fileName = "";
        std::string path = "/";

        std::string header = "";
        std::string body = "";
        std::string footer = "";

        Page(std::string fileName);

        std::string generate();
    };

    Page *pages = NULL;
    Builder();
};


#endif
