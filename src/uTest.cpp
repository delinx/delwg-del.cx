// UNIT TESTS
#include "html.hpp"
#include <iostream>

int passed = 0;
int failed = 0;

void printResults()
{
    std::cout << "\e["
              << "7;32mPASSED: " << float(100.f / (passed + failed) * passed) << "% (" << passed << ") "
              << "\e[0m"
              << "\n";
    std::cout << "\e["
              << "7;31mFAILED: " << float(100.f / (passed + failed) * failed) << "% (" << failed << ") "
              << "\e[0m"
              << "\n\n";
}

void assert(bool a, bool b, std::string str)
{
    std::cout << "> ";
    if(a == b)
    {
        std::cout << "\e["
                  << "7;32mPASS"
                  << "\e[0m";
        passed++;
    }
    else
    {
        std::cout << "\e["
                  << "7;31mFAIL"
                  << "\e[0m";
        failed++;
    }
    std::cout << " : " << str << std::endl;
}

bool uTest_basicSyntax()
{
    Html html;


    return true;
}

int main(int argc, char *argv[])
{
    std::cout << std::endl
              << "--- UNIT TESTS ---" << std::endl
              << std::endl;

    assert(uTest_basicSyntax(), true, "uTest_basicSyntax");

    std::cout << std::endl
              << "--- UNIT TESTS END ---" << std::endl
              << std::endl;
    printResults();
    return 0;
}
