// UNIT TESTS
#include "builder.hpp"
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

bool uTest_MakeBasicSite()
{
    // Builder *builder = new Builder();
    Builder::Page page("index.html");
    page.body = "body text";
    page.head = "head text";

    std::cout << std::endl
              << page.generate();

    return true;
}

bool uTest_replaceStringSuccess()
{
    std::string result = Builder::replaceString("Hello this is {TITLE}.", "{TITLE}", "me");
    return result == "Hello this is me.";
}

bool uTest_replaceStringFail()
{
    std::string result = Builder::replaceString("Hello this is {TITLE}.", "{WRONGTAG}", "me");
    return result == "Hello this is {TITLE}.";
}

bool uTest_MakeBasicSiteWithTemaplates()
{
    std::string path = "/home/del/cpp/delwg/web";
    Builder::Page page("index.html");
    page.head = Builder::replaceString(Builder::templateToString(path + "/template/head.template"), "{TITLE}", "Mihails Mozajevs");
    page.body = "body text";

    std::cout << std::endl
              << page.generate();
    return true;
}

int main(int argc, char *argv[])
{
    std::cout << std::endl
              << "--- UNIT TESTS ---" << std::endl
              << std::endl;

    assert(uTest_MakeBasicSite(), true, "Make Basic Site");
    assert(uTest_replaceStringSuccess(), true, "Replace String Success");
    assert(uTest_replaceStringFail(), true, "Replace String Not Found");
    assert(uTest_MakeBasicSiteWithTemaplates(), true, "Make Basic Site With Templates");

    std::cout << std::endl
              << "--- UNIT TESTS END ---" << std::endl
              << std::endl;
    printResults();
    return 0;
}
