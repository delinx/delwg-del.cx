#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "types.hpp"
#include <fstream>
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

        std::string head = "";
        std::string body = "";

        Page(std::string fileName);

        std::string generate();
    };

    Page *pages = NULL;

    static std::string templateToString(std::string path);
    static std::string replaceString(std::string source, std::string target, std::string text);
    Builder();
};


#endif
