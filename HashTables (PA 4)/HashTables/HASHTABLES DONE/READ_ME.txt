Topic: Hashtables

Description:

We were given the task to read in a CSV file and take in the roster which had the names of student, their UIN, email
address. We then read the input file which contained the kids that had the same data inside the CSV but they also had a
quiz grade .We then input this data in our data structure Hashtable which we created using Vectors with linked lists and
each part of the list contained a pair with the key of the hashtable and the quiz value. We then wrote a CSV file with the
entire roster including the kids with and without a quiz score. 

I created a Hashtable using vectors with lists inside of each vector and at each node of the list there is a std::pair
structure containing the key value (index of vector (location)), and a quiz score. The hashtable took in the quiz value as a
typename T. In our main we converted the string quiz grade into a integer before we inserted in the pair. The hashtable
had constructor, destructor, insert, search, and other statistic algorithms. The insert function push backed a pair into a
list in the index of the vector which came from the hash function. The search algorithm looks for a specific quiz grade
and returns it if it’s there if it isn’t it returns a nullptr.

There are two files which we read and one output file which we write too. The files we read in are the roster file and
input file. The roster file contains all the students while the input file only contains the students who have a quiz score.
The output file basically combines the two and gives all students and lists the score If they have one if not then that part
of it is just blank. Assumptions we have made in our input data is that every data is separated by a comma and there are
not any missing commas which if there were would make our output file incorrect. 

Testing:
I tested my Statistical calculations (Min, Max, and Average length of lists) by computing it for the output roster that was
constructed. The main CPP file created a output file and uses the functions inside CSV editor class and Hashtable class to
construct an output CSV and fill it with values and get statistical measurements on the vector and the list. To run the
program type, make then ./main.	