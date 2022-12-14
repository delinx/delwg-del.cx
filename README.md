# Delinx Website Generator

### Template structure of the web project
```
html/page.html
html/header.html
html/footer.html
html/HomePage.md
html/blog/howToblabla.md
html/blog/howToblabl2.md
html/blog/WhyDidImake1.md
```
### High level overview of generator functions
* Read .html pages and construct them using {HEADER} type tags to replace with context.
```
Make index.html out of page.html + header.html + footer.html, populate it with context from HomePage.md
```
* Convert basic .md syntax to basic html
* Generate list of links based on directory
```
Based on html/blog directory generate a HTML link list which can be used to open generated pages for each of those blog pages
```
