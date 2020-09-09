I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work. On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
Your Name: Yash Kalyani                  Date: 2/16/2020

Name: Yash Kalyani
UIN: 827003754
Email: yk7335@tamu.edu
Section: 511
Resources:
  https://en.cppreference.com/w/cpp/language/enum
  https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=vs-2019
  https://piazza.com/class/k4ylut1dmys4fw?cid=216
  https://www.youtube.com/results?search_query=template+classes+in+c%2B%2B

Known Problems:
  In my program I initially made two files. One was the main which was given and a header file which was
  home to all of the declarations for my classes. I wasn't sure if I needed another fine which held my
  definitions of classes but I felt comfortable not using one so I decided to leave it out. Was confused on
  the syntax of the template classes so I had to use my resources to figure out the syntax.
Short Description of Code:
  The code uses the collection class from the previous assignment but this time we templated it to work with
  stress ball and a new class that is similar to stress balls but its dealing with jeans and it's colors and
  sizes. The main point of the program was to pass through two types of class through collection class and sort
  them both.
Testing:
  I tested my program for correctness on Putty and if I saw any errors I would try and fix them one by one until the program would
  compile. I didn't run into any segmentation faults or any errors like it so the use of my debugger wasn't really necessary.
How to run:
  run makefile by typing make and then either type ./StressBallTest or ./JeansTest. 

----------------------------------Answer to Generic Programming Question--------------------------------
What are Templates? When you program Templates can be used to pass through different types of data types to accomplish
one main goal. For example if you have a template class that adds to things together you can pass in either to ints or
two characters to obtain two different answers. In the ints case you will get a sum of the two numbers and in the
characters case you would get the two characters put together in a string. If we didn't have templates then we would have
to write the template class twice once for the numbers and again for the characters. The template class makes it easier for
us to pass multiple type of data types to obtain similar actions on the dat types. Templates are mainly used to make coding
take up less lines of code and to compress things down. In this program I used a template class called collection what this
class did is that it took in whatever data type you passed in (another class type in our case it was stress balls and jeans)
and it sorted them by sizes of stress balls or sizes of the jeans. Templated made things easier because we didn't have to
create two different classes to pass in stress balls and jeans. The templated class let us take input of two different types
and be able to preform similar tasks like sorting, swapping, making a union. 
