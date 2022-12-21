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

int main(int argc, char *argv[])
{

    std::string path = "../../web/template/";
    Builder::Page page("index.html");

    // generate head
    page.head = Builder::replaceString(Builder::fileToString(path + "head.html"), "{TITLE}", "Mihails Mozajevs");
    // add stylesheets
    page.addStyleFile("template/style.css");
    page.addStyleFile("template/textStyle.css");

    std::string links = Builder::fileToString(path + "links.html");
    std::string cv = Builder::parseMarkdown(Builder::fileToString("../../web/cv.md"));

    std::string footer = Builder::fileToString(path + "footer.html");
    footer = Builder::replaceString(footer, "{GENERATED_DATE}", CurrentDate());
    footer = Builder::replaceString(footer, "{CURRENT_YEAR}", CurrentYear());

    // making the page
    page.body += links;
    page.body += cv;
    page.body += footer;

    std::ofstream out("../../web/index.html");
    out << page.generate();
    out.close();

    std::cout << page.generate() << std::endl;
    return 0;
}

#endif
