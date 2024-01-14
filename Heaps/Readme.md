# Merge K Sorted Lists using Priority Queue
## Overview
This C++ program demonstrates the efficient merging of k sorted lists using a priority queue. The program defines a ListNode structure to represent elements in a linked list and a compare structure to serve as a comparison function for the min-heap (implemented as a priority queue).

## Functionality - 

## Approach of how to merge k sorted lists using heap

- First, we need to create a min-heap.
- Since the smallest elements are present at the beginning of each list as each of them is sorted, so, we need to insert each list’s first element in our heap.
- Now, while our heap is not empty, we need to take out its top element and attach it at the end of our result list.
- The node which we attached to the end of the result list will be from one of the K given linked list, so if the next node of the node which we attached at the end of the result list exists, we need to push it into the min heap.
- Finally, when our min heap is empty, at that time the result list will contain all the nodes of the K given linked list in sorted order.
## Algorithm of how to merge k sorted lists using heap
1. The mergeKLists function takes a vector of sorted linked lists as input.
1. Write a comparator function for the priority queue to store minimum elements at the top.
1. Push starting node of all the lists in the min-heap.
1. Now, create a node head with zero value that will act as a dummy node for our newly created list.
1. Initialize a temp variable with the address of the above-created node.
1. Run a while loop till the priority queue not empty.
1. Store the topmost element of the queue into a variable, say p.
1. Now remove the top element from the priority queue.
1. Attach the node p at the end of our new list by doing temp->next = p.
1. Now advance the temp variable by one node i.e, temp = temp->next.
1. If the node after p is not NULL, push the node after p into the priority queue.
1. After the completion of the while loop, return head->next, as it will be the first node of our newly created linked list.
