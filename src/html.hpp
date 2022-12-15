#ifndef HTLM_HPP
#define HTLM_HPP

#include "types.hpp"
#include <iostream>

class Html
{
      public:
    class Tag
    {
          public:
        Tag();
        std::string type = "DEFAULT";
        void append(std::string str);
        std::string toString();
    };

    Html();

    void append(Tag tag);
    std::string toString();
};

#endif  // HTLM_HPP
