#include "builder.hpp"
#include <chrono>
#ifdef UNIT_TEST
#include "uTest.cpp"
#else

#include "types.hpp"
#include <iostream>

using sysclock_t = std::chrono::system_clock;

std::string CurrentDate()
{
    std::time_t now = sysclock_t::to_time_t(sysclock_t::now());
    char buf[64] = { 0 };
    std::strftime(buf, sizeof(buf), "This page was generated at %H:%M:%S %Y/%m/%d London, UK", std::localtime(&now));
    return std::string(buf);
}

std::string CurrentYear()
{
    std::time_t now = sysclock_t::to_time_t(sysclock_t::now());
    char buf[64] = { 0 };
    std::strftime(buf, sizeof(buf), "%Y", std::localtime(&now));
    return std::string(buf);
}

int main(int argc, char* argv[])
{

    // Global
    std::string templatesPath = "../../web/template/";
    std::string menu = Builder::fileToString(templatesPath + "menu.html");
    std::string footer = Builder::fileToString(templatesPath + "footer.html");
    footer = Builder::replaceString(footer, "{GENERATED_DATE}", CurrentDate());
    footer = Builder::replaceString(footer, "{CURRENT_YEAR}", CurrentYear());

    // MAIN PAGE
    Builder::Page mainPage("index.html");

    mainPage.head = Builder::replaceString(Builder::fileToString(templatesPath + "head.html"), "{TITLE}", "Mihails Mozajevs");
    mainPage.addStyleFile("template/style.css");
    mainPage.addStyleFile("template/textStyle.css");
    mainPage.path = "../../web/";

    std::string links = Builder::fileToString(templatesPath + "links.html");
    std::string cv = Builder::parseMarkdown(Builder::fileToString("../../web/cv.md"));

    mainPage.body += menu;
    mainPage.body += links;
    mainPage.body += cv;
    mainPage.body += footer;

    mainPage.save();

    // BLOG PAGE
    Builder::Page blogPage("blog.html");

    blogPage.head = Builder::replaceString(Builder::fileToString(templatesPath + "head.html"), "{TITLE}", "Mihails Mozajevs");
    blogPage.addStyleFile("template/style.css");
    blogPage.addStyleFile("template/textStyle.css");
    blogPage.path = "../../web/";

    blogPage.body += menu;
    // build all the blog pages and add links to them
    std::string blogs[] = { "generator.md", "keyboards.md", "vim.md" };
    std::string blogLinks;
    for(i32 i = 0; i < sizeof(blogs) / sizeof(blogs[0]); i++)
    {
        Builder::Page blogUniquePage(Builder::replaceString(blogs[i], ".md", ".html"));
        blogUniquePage.head = Builder::replaceString(Builder::fileToString(templatesPath + "head.html"), "{TITLE}", "Mihails Mozajevs");
        blogUniquePage.addStyleFile("../template/style.css");
        blogUniquePage.addStyleFile("../template/textStyle.css");
        blogUniquePage.path = "../../web/blog/";
        blogUniquePage.body += menu;
        blogUniquePage.body += Builder::parseMarkdown(Builder::fileToString("../../web/blog/" + blogs[i]));
        blogUniquePage.body += footer;
        blogLinks += "<a href=\"blog/" + blogUniquePage.fileName + "\">" + Builder::replaceString(blogs[i], ".md", "") + "</a><br>";
        blogUniquePage.save();
    }
    blogPage.body += Builder::replaceString(Builder::fileToString(templatesPath + "blog.html"), "{BLOG_LINKS}", blogLinks);
    blogPage.body += footer;

    blogPage.save();

    return 0;
}

#endif
