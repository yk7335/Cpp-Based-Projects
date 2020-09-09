I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work. On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
Your Name: Yash Kalyani                  Date: 1/22/2020

Name: Yash Kalyani
UIN: 827003754
Email: yk7335@tamu.edu
Section: 511
Resources:
  https://en.cppreference.com/w/cpp/language/enum
  https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=vs-2019
Known Problems:
  In my program I initially made two files. One was the main which was given and a header file which was
  home to all of the declarations for my classes. I wasn't sure if I needed another fine which held my
  definitions of classes but I felt comfortable not using one so I decided to leave it out.
Short Description of Code:
  The code I built is a header file which has 4 main components. Two of them are enum classes for color and
  size. One of the main components is the Stress_ball class which contains all the functions like getters, constructors,
  and operator overloading function. The last component of the program is the overloaded operator << which is located outside
  the class. The class creates an object of type enum class of a ball that has two attributes, size and color. In the main
  code is written to figure out if the constructors are working properly and whether two random balls created have the same attributes.
Testing:
  I tested my program for correctness on Putty and if I saw any errors I would try and fix them one by one until the program would
  compile. I didn't run into any segmentation faults or any errors like it so the use of my debugger wasn't really necessary.
How to run:
  Run the makefile by typing make then ./Stress_Main
