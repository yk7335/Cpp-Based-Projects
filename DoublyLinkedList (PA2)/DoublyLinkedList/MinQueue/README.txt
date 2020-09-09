I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work. On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
Your Name: Yash Kalyani                  Date: 3/6/2020

Name: Yash Kalyani
UIN: 827003754
Email: yk7335@tamu.edu
Section: 511
Resources:
http://mitk.org/images/c/ca/MoveConstructor.pdf
https://www.softwaretestinghelp.com/doubly-linked-list/

Known Problems:
Known problems that I had with this code was with the main file. I wasn't sure that I covered all the test cases in the main
file.
Short Description of Code:
The MinQueue class uses the templated doubly linked list class and creates a list where you can preform the functions
enqueue (insert first) and dequeue (remove last). So the order is first in first out. There is one extra function called the
MinQueue function which finds the smallest element in the linked list and returns it's value.
Testing:
I tested each function to make sure it behaved as I thought it would. After testing each function I made sure the edge cases
worked. The run time for every function is O(1) because they run in constant time. The MinQueue function is the only function
that doesn't run on constant time because it has a while loop in it. MinQueue's Big O notation is O(n) because it only has one
for loop that iterates i by one. The runtime of enqueue and dequeue is F(x) = 3 for dequeue and F(x) = 2 because enqueue only
does two constant time operations while the dequeue does 3 constant time operations that is why there big O is constant or O(1).
The run time function for the MinQueue function is approximately 2n+4 therefore it's big O is O(n). My test for correctness is
my main file. I ran each function to make sure they did there job and tried to cover every edge case I thought was important. The
MinQueue function sets the low value to the first nodes object then it loops through the linked list and sees if there is a lower
value in the list if there is it re assigns low to that value and at the end I return the low value. I throw an exception just in
case if the linked list was empty. 
