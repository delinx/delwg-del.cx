#include "builder.hpp"
#include <iostream>
#include <sstream>
#include <string>

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
         << Builder::Page::head
         << std::endl
         << "</head>"
         << std::endl
         << "<body>"
         << std::endl
         << Builder::Page::body
         << std::endl
         << "</body>"
         << std::endl
         << "</html>"
         << std::endl
         << "<!-- Generated by delwg -->"
         << std::endl;

    return data.str();
}

std::string Builder::templateToString(std::string path)
{
    std::ifstream t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

std::string Builder::replaceString(std::string source, std::string target, std::string text)
{
    u64 result = source.find(target);
    if(result <= source.length())
    {
        return source.replace(source.find(target), target.length(), text);
    }
    return source;
}

// Empty line is a new line
// # is a header
// * is a list
// [text](link) is a link
// ![text](link) is a image
// **bold** is bold
// *italic* is italic
std::string Builder::parseMarkdown(const std::string& input)
{
    std::string output;

    std::istringstream f(input);
    std::string line;

    bool inList = false;

    while(std::getline(f, line))
    {
        // beginning types
        if(line == "")
        {
            output += "<br>";
        }
        else if(line[0] == '#')
        {
            u8 hlevel = 0;
            for(size_t i = 0; i < line.length(); i++)
            {
                if(line[i] != '#')
                {
                    break;
                }
                else
                {
                    hlevel++;
                }
            }

            if(hlevel > 6)
            {
                hlevel = 6;
            }

            std::string hlevelStr = std::to_string(hlevel);
            output += "<h" + hlevelStr + ">" + line.substr(hlevel) + "</h" + hlevelStr + ">";
        }
        else if(line[0] == '*')
        {
            if(!inList)
            {
                output += "<ul>";
                inList = true;
            }
            output += "<li>" + line.substr(1) + "</li>";
        }
        else if(line[0] != '*' && inList)
        {
            output += "</ul>";
            inList = false;
            output += line;
        }
        else if(line[0] == '[')
        {
            u64 end = line.find("]");
            u64 start = line.find("(");
            std::string text = line.substr(1, end - 1);
            std::string link = line.substr(start + 1, line.length() - start - 2);
            output += "<a href=\"" + link + "\">" + text + "</a>";
        }
        else if(line[0] == '!')
        {
            u64 end = line.find("]");
            u64 start = line.find("(");
            std::string text = line.substr(2, end - 2);
            std::string link = line.substr(start + 1, line.length() - start - 2);
            output += "<img src=\"" + link + "\" alt=\"" + text + "\">";
        }
        else
        {
            output += "<p>" + line + "</p>";
        }
    }

    // std::cout << output << std::endl;
    return output;
}
