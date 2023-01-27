<<TAG>>Advice for programming beginners|2023-01-20<<TAG>>
[2023-01-20] **Advice for programming beginners**
\---
In this post I want to share my **personal** advice for the beginners who are just 
starting their journey and are unsure of the next steps. I have been programming 
for about 14 years at the time of writing this post, I started when I was around ten 
years old and aside from few short breaks and burnouts here and there, I have always loved programming. 


## Pick up TWO languages instead of one
I bet you are not even sure how to learn one, so why in hell would I tell you to learn two? 
\nWell, I do have a sensible reason behind it. In this post, I would assume that you don't 
have a specific field or tool you **must** work in; if you do have such field/tool then you 
better seek advise from others who do the same professionally.


It's very difficult to become a well rounded developer if you only know a high/low level language. 

* If you only learn a low level language, chances are you will get burned out or doubt your ability 
long before you are capable of making anything __actually__ useful. Most things which you assume to be easy, like 
adding UI to your program with a button you can press, end up being extremely involved requiring a lot of additional 
learning.

* If you only learn a high level language, you will be able to start making things much quicker, yet 
the lack of understanding of the fundamentals will catch up with you eventually! Understanding of how CPU, RAM, 
OS and etc. actually work will allow you to understand reasoning behind various architectural decisions made for you and 
make you aware of various limitations. Things will work until they don't, and once they stop that's where deeper 
understanding will become irreplaceable. 


My recommendations for a **low level language** (pick one)

* [Easy] C
\n* [Medium] C++
\n* [Medium-Hard] Rust

If you are looking to get employed within few years, C and C++ make more sense, they are widely used in the industry. 
Rust is less adopted but personally have became my favourite out of the three, its extremely powerful yet not widely 
adopted __yet__. Keep in mind that both C++ and Rust have significantly more features then one programmer will likely 
ever use, so don't try to learn **everything**, its unrealistic and impractical. The C programming language is very 
small, you can learn all the key words within 1 week, that simplicity however comes with a cost of not many things being 
ready made for you to simply use, you will need to learn how to make things yourself which other languages already have, 
however its not a bad thing. If you pick one of them **you cannot go wrong**, all three languages share huge amount of 
concepts, ideas and key words, if you learn one of them, you learn at least 40% of the two others. If you are looking to 
get employed soon then research which one of these is mostly used in your local area and in your global field.


My recommendations for a **high level language** (pick one)

* Python
\n* JavaScript

You can think of these as Lego bricks of the programming industry. Both are designed to handle as many things for 
you as possible, making sure you can accomplish whatever you wish to in as few lines as possible. Python will fit well 
for working with files (data, ML, images, video) or for writing small utilities, it's especially great for **automation**, you can link various 
protocols and systems together using python incredibly easily utilising all the wonderful libraries other people already 
made. Python is also a bit easier to install and run compared to JavaScript if you want to accomplish things outside of 
browser. However, if you are interested in utilising browser, be that for websites or general apps, then JavaScript will 
be a better fit for that since it's de-facto industry standard. Generally, high level languages are easier to pick up then low 
level languages, so nothing stops you from learning basics in both and then choosing one to focus on.


## How to learn TWO languages?

I have already discussed positives and negatives about both, in short, one gives you more control yet requires more work 
to get things done, other gives you less control but allows you to make things work in less time. So use that to your advantage! 

With high level language try to have fun, write some small tools you can think of, parse 
your music library and extract information about genres, write program which takes your pictures and makes a collage out 
of them. Don't worry about making things **right** or **doing things properly**, just focus on making things work, use 
other peoples libraries, copy paste code, basically practice making a working product. 

With low level language, you have much finer control over everything, with both C and C++ you are responsible for clearing 
memory you don't need anymore, making sure you are reading and writing data within bounds of your variables and much 
more. Take advantage of that, try to deeply learn about every key word, every symbol you write, yet don't let 
perfectionism take over, make those data leaks, make data overflows, learn how to debug them and how to inspect memory 
of your application using debuggers. Try to learn and appreciate how computers really think by taking step lower and 
learning about compiler, assembler language and etc. 


## Learning the **tool** vs learning the **craft**

I might of made it sound like you should never learn high level language deeply, or quickly prototype in a lower level 
language, that is not my message. My recommendation above is based around the idea of two mindsets.

Any craft, including programming, can benefit from separating those two mindsets. It's essential to allow yourself to 
create without being too judgmental of quality or methods to get things done; yet its equally essential to be able to 
learn your tools deeply, by learning every nuance of the tool you are exposing yourself to new creative possibilities.
The trick it to **not** do both **at the same time**!

### Learning the craft

When learning the craft, you cannot afford staring at the blank canvas for too long. No one cares how perfect your first 
brush stroke it, if it never becomes a painting. Improvise, hack things together, salvage the situation but keep moving 
forward, focus on finishing projects and finishing your project. Don't practice the first verse of the song, sing it wholly 
even if poorly. Listen, at the end of the day, no one will be able to teach you how to make things, how to build apps, 
how to solve real problems. Even if you spend third of your life at planning your next app, writing documentation, 
drawing architectural designs; things will not go as planned, you will find problems in areas you never expected to have 
any, and your carefully engineered solutions to problems you __imagined__ will end up being useless or causing more 
issues then their worth. You cannot **prepare** to writing a good app as a beginner, you have to just write it, and then 
maybe re-write it again, and again, and every time you will be more and more proud of it then the last time. Any 
programmer who doesn't think **__who was the incompetent idiot who wrote this crap__** looking at their own 3 months old code
, is doing something wrong. The only way to the mastery is trough **failure**, and you have to truly embrace it. 

### Learning the tool

Learning your tools is the best on small toy projects, ones you have no desire to finish. Learning tools could be 
learning how to debug, learning more about the build system, etc. But most impotently, learning your programming 
language of choice in details. I bet there are things you use all the time which you don't truly understand inner 
working of, where does C __malloc__ or C++ __new__ get memory from? How does your array actually look in the RAM? 
I cannot tell you what to learn exactly, but my general advise is to be mindful of what you are using, and not being 
afraid of stopping work and looking things up; be playful and curious, experiment. 

### Learn to program before you learn to design

Be weary of planning everything ahead, and drafting design and plan of your entire project before writing any code. 
Sure, some planning is great, yet before you mastered your tools you are not capable of making adequate plans. So write 
a short description of how you think things will work, then go ahead and finish the project, look back at your 
description and reflect, through repetition you will learn things worth and not worth planning ahead. 


## Use your time wisely

While you are learning absolute basics it makes sense to spend about 60% of your time on practicing and 40% on learning, 
however once you done with basics from whatever source you are using, you should gradually decrease learning time and 
increase practice time. You will need to experiment to find out what is best for you, but I know for a fact there is 
no well rounded programmers I know personally who put less time into practice then into studying, to put that book down 
and write some code! For me current ratio is about 80% to 20%, although it fluctuates when I learn new languages or 
concepts. Just try to be concious of separating __learning__ time and __working__ time, it's great to be able to solve 
problems with __only__ things you already know, and then learning about alternative solutions you don't yet know.

\---
## TL;DR

* Learn **C** or **C++** or **Rust**
\n* Learn **Python** or **JavaScript**
\n* Spend about **70%** of time on programming and **30%** on learning
\n* Practice, practice, practice. If you have not written 10,000 lines of code and you are worried you don't feel
confident yet, don't worry, you have no reason to feel confident! Get to typing!
\n* When practicing craft, get things done, even if in junkiest way possible.
\n* When practicing tools, focus on fundamentals and ground truths, always ask why.
\n* Don't try to design before you know your tools well and you made few things, before that your design process is
imagination and wishful thinking.
\n* Not knowing things is normal, even after 10 years of doing this you will still not know things on regular basis.
\n* Don't memorise things you don't often need, learn to search the documentation instead.
