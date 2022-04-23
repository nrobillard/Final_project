# Final Project
This final project is a collabrative effort by: Nick Robillard, Ben Thomas, and Abdullah Mousa
# Splay Trees
A splay tree is a binary search tree with the additional property that recently accessed elements are quick to access again. Like self-balancing binary search trees, a splay tree performs basic operations such as insertion, look-up, and removal in O(log n) amortized time.

whenever an element is looked up in the tree, the splay tree reorganizes to move that element to the root of the tree. If the next lookup request is for the same element, it can be returned immediately. In general, if a small number of elements are being heavily used, they will tend to be found near the top of the tree and are thus found quickly.

