# Final Project
This final project is a collabrative effort by: Nick Robillard, Ben Thomas, and Abdullah Mousa
# Splay Trees
A splay tree is a binary search tree with the additional property that recently accessed elements are quick to access again. Like self-balancing binary search trees, a splay tree performs basic operations such as insertion, look-up, and removal in O(log n) amortized time.

whenever an element is looked up in the tree, the splay tree reorganizes to move that element to the root of the tree. If the next lookup request is for the same element, it can be returned immediately. In general, if a small number of elements are being heavily used, they will tend to be found near the top of the tree and are thus found quickly.

# Instructions

1.)In order to run our code you need to first compile the code using 
g++ splay.cpp -o output

2.)Next run the code and make sure it takes in a file as the first arguement and the output file name as the second arguement
./output text.txt output.txt

3.)Next you will be prompted with 5 options in the terminal 

<img width="250" alt="Screen Shot 2022-04-24 at 5 51 54 PM" src="https://user-images.githubusercontent.com/71105877/164998155-ae41fa0b-82fd-441f-b350-c3254a5e4fe3.png">

4.) Next choose one of the numbers and in order to exit type 5


5.) When you print 4 it will print out a graph looking like this 

<img width="400" alt="Screen Shot 2022-04-26 at 10 07 10 PM" src="https://user-images.githubusercontent.com/71105877/165423981-8ffe4c89-c239-4c44-83e3-0115bc44869d.png">
