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

bool uTest_MarkdownParagraphWithNewLine()
{
    return (Builder::parseMarkdown("Hello this is a \ntest.") == "<p>Hello this is a test.</p>");
}

bool uTest_MarkdownTwoParagraphs()
{
    return (Builder::parseMarkdown("Hello this is a test.\n\nThis is a second paragraph.") == "<p>Hello this is a test.</p><p>This is a second paragraph.</p>");
}

bool uTest_MarkdownNewLineSymbol()
{
    return (Builder::parseMarkdown("Hello this is a test.\\nThis is a second line test.") == "<p>Hello this is a test.<br>This is a second line test.</p>");
}

bool uTest_MarkdownNewLineSymbolWithSpace()
{
    return (Builder::parseMarkdown("Hello this is a test.\\n This is a second line test.") == "<p>Hello this is a test.<br>This is a second line test.</p>");
}

bool uTest_MarkdownNewLineSymbolEndLine()
{
    return (Builder::parseMarkdown("Hello this is a test.\\n") == "<p>Hello this is a test.<br></p>");
}

bool uTest_MarkdownNewLineSymbolEndLineWithSpace()
{
    return (Builder::parseMarkdown("Hello this is a test.\\n ") == "<p>Hello this is a test.<br></p>");
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
    return (Builder::parseMarkdown("[Hello this is a test.](https://delwg.com)") == "<p><a href=\"https://delwg.com\">Hello this is a test.</a></p>");
}

bool uTest_MarkdownImageSimple()
{
    return (Builder::parseMarkdown("![Hello this is a test.](https://delwg.com)") == "<p><img src=\"https://delwg.com\" alt=\"Hello this is a test.\"></p>");
}

bool uTest_MarkdownImageWithStyle()
{
    return (Builder::parseMarkdown("![Hello this is a test.](https://delwg.com){width:100px;}") == "<p><img src=\"https://delwg.com\" alt=\"Hello this is a test.\" style=\"width:100px;\"></p>");
}

bool uTest_list()
{
    return (Builder::parseMarkdown("*Hello this is a test.") == "<ul><li>Hello this is a test.</li></ul>");
}

bool uTest_listTwo()
{
    return (Builder::parseMarkdown("*Hello this is a test.\n*Hello this is a test.") == "<ul><li>Hello this is a test.</li><li>Hello this is a test.</li></ul>");
}

bool uTest_bold()
{
    return (Builder::parseMarkdown("Hello this **is** a test.") == "<p>Hello this <b>is</b> a test.</p>");
}

bool uTest_italic()
{
    return (Builder::parseMarkdown("Hello this __is__ a test.") == "<p>Hello this <i>is</i> a test.</p>");
}

bool uTest_divider()
{
    return (Builder::parseMarkdown("Hello this is a test.\n\\---\nThis is a second paragraph.") == "<p>Hello this is a test.</p><hr><p>This is a second paragraph.</p>");
}

bool uTest_ignoreTag()
{
    return (Builder::parseMarkdown("<<TAG>>This is tag comment, it cannot be parsed\ntest") == "<p>test</p>");
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
    assert(uTest_MarkdownParagraph(), true, "Paragraph");
    assert(uTest_MarkdownParagraphWithNewLine(), true, "Paragraph With New Line");
    assert(uTest_MarkdownNewLineSymbol(), true, "New Line Symbol");
    assert(uTest_MarkdownNewLineSymbolWithSpace(), true, "New Line Symbol With Space");
    assert(uTest_MarkdownNewLineSymbolEndLine(), true, "New Line Symbol At End Of Line");
    assert(uTest_MarkdownNewLineSymbolEndLineWithSpace(), true, "New Line Symbol At End Of Line With Space");
    assert(uTest_MarkdownTwoParagraphs(), true, "Paragraphs");
    assert(uTest_MarkdownHeader(), true, "Header 1");
    assert(uTest_MarkdownHeaderTwo(), true, "Header 2");
    assert(uTest_MarkdownHeaderThree(), true, "Header 3");
    assert(uTest_MarkdownHeaderFour(), true, "Header 4");
    assert(uTest_MarkdownHeaderFive(), true, "Header 5");
    assert(uTest_MarkdownHeaderSix(), true, "Header 6");
    assert(uTest_MarkdownLink(), true, "Link");
    assert(uTest_MarkdownImageSimple(), true, "Image");
    assert(uTest_MarkdownImageWithStyle(), true, "Image With Style");
    assert(uTest_list(), true, "List");
    assert(uTest_listTwo(), true, "List Two");
    assert(uTest_bold(), true, "Bold");
    assert(uTest_italic(), true, "Italic");
    assert(uTest_divider(), true, "Divider");
    assert(uTest_ignoreTag(), true, "Ignore <!TAG!> Tag");

    std::cout << "\n### UNIT TESTS END ###\n\n";
    printResults();
    return 0;
}
