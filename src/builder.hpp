#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "types.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

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
        void addStyleFile(std::string path);
        void save();
    };

    Page* pages = NULL;

    static std::string fileToString(std::string path);
    static std::string replaceString(std::string source, std::string target, std::string text);
    static std::string parseMarkdown(const std::string& input);
    Builder();
};


#endif
