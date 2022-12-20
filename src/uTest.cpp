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
    std::cout << " : " << str << "\n";
}

bool uTest_MakeBasicSite()
{
    // Builder *builder = new Builder();
    Builder::Page page("index.html");
    page.body = "body text";
    page.head = "head text";

    // FIXME, this is not a good test, it's just a placeholder, add string comparison
    return page.generate().length() == 109;
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

bool uTest_fileToString()
{
    std::string path = "../../misc/";
    std::string result = Builder::fileToString(path + "test.txt");
    return result == "Hello World!\n";
}

bool uTest_MakeBasicSiteWithTemaplates()
{
    std::string path = "../../misc/";
    Builder::Page page("index.html");
    page.head = Builder::replaceString(Builder::fileToString(path + "head.template"), "{TITLE}", "Mihails Mozajevs");
    page.body = "body text";

    // FIXME, this is not a good test, it's just a placeholder, add string comparison
    // probably make template in misc much simpler too
    return page.generate().length() == 382;
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

bool uTest_MarkdownLink()
{
    return (Builder::parseMarkdown("[Hello this is a test.](https://delwg.com)") == "<a href=\"https://delwg.com\">Hello this is a test.</a>");
}

bool uTest_MarkdownImage()
{
    return (Builder::parseMarkdown("![Hello this is a test.](https://delwg.com)") == "<img src=\"https://delwg.com\" alt=\"Hello this is a test.\">");
}

bool uTest_list()
{
    return (Builder::parseMarkdown("*Hello this is a test.") == "<ul><li>Hello this is a test.</li></ul>");
}

bool uTest_listTwo()
{
    return (Builder::parseMarkdown("*Hello this is a test.\n*Hello this is a test.") == "<ul><li>Hello this is a test.</li><li>Hello this is a test.</li></ul>");
}

int main(int argc, char *argv[])
{
    std::cout << "\n### UNIT TESTS ###\n";

    std::cout << "\n--- BUILDER ---\n";
    // basic generation
    assert(uTest_MakeBasicSite(), true, "Make Basic Site");
    assert(uTest_replaceStringSuccess(), true, "Replace String Success");
    assert(uTest_replaceStringFail(), true, "Replace String Not Found");
    assert(uTest_fileToString(), true, "File to String");
    assert(uTest_MakeBasicSiteWithTemaplates(), true, "Make Basic Site With Templates");

    std::cout << "\n--- MARKDOWN ---\n";
    // markdown
    assert(uTest_MarkdownParagraph(), true, "Markdown Basic Paragraph");
    assert(uTest_MarkdownTwoParagraphs(), true, "Markdown Basic Paragraphs");
    assert(uTest_MarkdownHeader(), true, "Markdown Header 1");
    assert(uTest_MarkdownHeaderTwo(), true, "Markdown Header 2");
    assert(uTest_MarkdownHeaderThree(), true, "Markdown Header 3");
    assert(uTest_MarkdownHeaderFour(), true, "Markdown Header 4");
    assert(uTest_MarkdownHeaderFive(), true, "Markdown Header 5");
    assert(uTest_MarkdownHeaderSix(), true, "Markdown Header 6");
    assert(uTest_MarkdownLink(), true, "Markdown Link");
    assert(uTest_MarkdownImage(), true, "Markdown Image");
    assert(uTest_list(), true, "Markdown List");
    assert(uTest_listTwo(), true, "Markdown List Two");

    std::cout << "\n### UNIT TESTS END ###\n\n";
    printResults();
    return 0;
}
