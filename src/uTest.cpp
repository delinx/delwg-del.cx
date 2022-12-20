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

bool uTest_MarkdownParagraph()
{
    return (Builder::parseMarkdown("Hello this is a test.") == "<p>Hello this is a test.</p>");
}

bool uTest_MarkdownTwoParagraphs()
{
    return (Builder::parseMarkdown("Hello this is a test.\n\nThis is a second paragraph.") == "<p>Hello this is a test.</p><br><p>This is a second paragraph.</p>");
}

bool uTest_MarkdownHeader()
{
    return (Builder::parseMarkdown("#Hello this is a test.") == "<h1>Hello this is a test.</h1>");
}

bool uTest_MarkdownHeaderTwo()
{
    return (Builder::parseMarkdown("##Hello this is a test.") == "<h2>Hello this is a test.</h2>");
}

bool uTest_MarkdownHeaderThree()
{
    return (Builder::parseMarkdown("###Hello this is a test.") == "<h3>Hello this is a test.</h3>");
}

bool uTest_MarkdownHeaderFour()
{
    return (Builder::parseMarkdown("####Hello this is a test.") == "<h4>Hello this is a test.</h4>");
}

bool uTest_MarkdownHeaderFive()
{
    return (Builder::parseMarkdown("#####Hello this is a test.") == "<h5>Hello this is a test.</h5>");
}

bool uTest_MarkdownHeaderSix()
{
    return (Builder::parseMarkdown("######Hello this is a test.") == "<h6>Hello this is a test.</h6>");
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
    assert(uTest_MarkdownParagraph(), true, "Markdown Basic Paragraph");
    assert(uTest_MarkdownTwoParagraphs(), true, "Markdown Basic Paragraphs");
    assert(uTest_MarkdownHeader(), true, "Markdown Header 1");
    assert(uTest_MarkdownHeaderTwo(), true, "Markdown Header 2");
    assert(uTest_MarkdownHeaderThree(), true, "Markdown Header 3");
    assert(uTest_MarkdownHeaderFour(), true, "Markdown Header 4");
    assert(uTest_MarkdownHeaderFive(), true, "Markdown Header 5");
    assert(uTest_MarkdownHeaderSix(), true, "Markdown Header 6");


    std::cout << std::endl
              << "--- UNIT TESTS END ---" << std::endl
              << std::endl;
    printResults();
    return 0;
}
