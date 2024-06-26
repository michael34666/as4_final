# Michael Dadush
# 206917908
# Michael_Dadush12@gmail.com

This project implements a generic Tree data structure in C++, supporting both general trees (template <typename T, size_t K = 2>) 
and binary trees (template <typename T>). The implementation includes various iterators for traversing the tree in different orders,

# Files:
node.hpp: Defines the Node class template for creating nodes in a tree structure.
tree.hpp: supporting both general trees (template <typename T, size_t K = 2>) 
and binary trees (template <typename T>)
iterator.hpp: Defines various iterators used for traversing trees.
complex.hpp: Defines the Complex class for complex number operations.
Demo.cpp: Contains a demo that supplies in the as
main.cpp: Uses the Complex class for various operations.


# Libraries Used:
C++ Standard Library: Utilized for standard containers (vector) and language features.

# Class Hierarchy
Node.hpp: Defines the Node class representing elements within the tree structure. Each node contains data of type T and maintains references to child nodes.

Tree.hpp: Contains the Tree class implementation, which manages nodes (Node<T>) and supports operations for adding nodes, as well as iterators for various traversal orders.

Iterator.hpp: Defines various iterator classes used for traversing the tree in different orders (pre-order, post-order, in-order, bfs scan, dfs scan,min heap scan), including specialized iterators like IteratorHeapOrder for heap order traversal.


# Node Class Template (node.hpp)
The Node class template represents a node in a tree structure. Each node contains a data element of type T and maintains a vector of child nodes.

## Public Members:
Constructor: Initializes a node with a given value.
get_value(): Retrieves the value stored in the node.
set_value(): Sets the value stored in the node.
get_son(): Returns a constant reference to the vector of child nodes.
left(), right(): Return the left and right child nodes (specific to binary trees).
setLeft(), setRight(): Sets the left and right child nodes (specific to binary trees).
son_remove(): Clears the vector of child nodes.
Private Members:
data: The value stored in the node.
son: A vector containing pointers to child nodes.
Tree Class Template (tree.hpp)
The Tree class template represents a tree data structure. It uses the Node class to construct the tree and provides various operations for manipulating and traversing the tree.


# tree class:
## Public Members:

Constructor: Initializes an empty tree. 
Destructor: Cleans up allocated resources when the Tree object goes out of scope or is explicitly destroyed. 
add_root(): Adds a root node to the tree.
add_sub_node(): Adds a child node to a parent node.
begin_pre_order(), end_pre_order(): Returns iterators for pre-order traversal.
begin_post_order(), end_post_order(): Returns iterators for post-order traversal.
begin_in_order(), end_in_order(): Returns iterators for in-order traversal.
begin_bfs_scan(), end_bfs_scan(): Returns iterators for breadth-first scan traversal.
begin_dfs_scan(), end_dfs_scan(): Returns iterators for depth-first scan traversal.
begin_heap_order(), end_heap_order(): Returns iterators for heap order traversal.
gui:using sfml lib




# Iterator Classes (iterator.hpp)
The iterator.hpp file defines various iterators used for traversing trees in different orders:

IteratorPreOrder: Pre-order traversal iterator.
IteratorPostOrder: Post-order traversal iterator.
IteratorInOrder: In-order traversal iterator.
IteratorBfsOrder: Breadth-first scan iterator.
IteratorDfsOrder: Depth-first scan iterator.
HeapOrderIterator: Iterates over nodes in min heap order traversal.

