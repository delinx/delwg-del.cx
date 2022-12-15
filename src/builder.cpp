#include "builder.hpp"

Builder::Builder()
{
}

Builder::Page::Page(std::string fileName)
{
    Builder::Page::Page::fileName = fileName;
}

std::string Builder::Page::generate()
{
    std::stringstream data;

    data << "<!DOCTYPE html>"
         << std::endl
         << "<html>"
         << std::endl
         << "<head>"
         << std::endl
         << Builder::Page::header
         << std::endl
         << "</head>"
         << std::endl
         << "<body>"
         << std::endl
         << Builder::Page::body
         << std::endl
         << Builder::Page::footer
         << std::endl
         << "</body>"
         << std::endl
         << "</html>"
         << std::endl
         << "<!-- Generated by delwg -->"
         << std::endl;


    return data.str();
}
