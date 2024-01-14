# Kth Smallest Element in a Binary Search Tree (BST)
## Functionality
This C++ program implements an algorithm to find the kth smallest element in a Binary Search Tree (BST). The program allows users to create a BST by entering data, and then it finds and displays the kth smallest element in the tree.

## Data Structure
The program utilizes a binary tree structure, where each node has a value (data) and pointers to its left and right children. The BST property is maintained, where values in the left subtree are less than the node's value, and values in the right subtree are greater.

## Functionality
1. Insertion in BST (insertAtBst function)
The insertAtBst function is responsible for inserting a new node with a given value into the BST while maintaining the BST property.

2. Taking Input for BST Creation (takeInput function)
The takeInput function allows users to input data to create a BST. It repeatedly prompts the user for data until they enter -1, signifying the end of input.

3. Finding the Kth Smallest Element (kthSmallest function)
The kthSmallest function performs an in-order traversal of the BST, decrementing a counter (k) at each step. When k becomes zero, the function identifies the kth smallest element and stores it in the result variable.

## How to execute 
- Run the program.
- Enter data to create a BST. Use -1 to terminate the input.
- Enter the value of k.
- The program will find and display the kth smallest element in the BST.