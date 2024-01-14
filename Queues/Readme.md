# Functionality of a deque-based algorithm to efficiently find the maximum or minimum element in a sliding window of a large array.

- The main function **maxSlidingWindow** takes two parameters (nums,k)
    - nums: A vector of integers representing the input array.
    - k: An integer specifying the size of the sliding window.
- The algorithm iterates through the input array and maintains a deque (dq) to keep track of potential maximum elements in the current window.
- The vector result is used to store the result at each window.
- During iteration of the vector we first check if the front element present in the deque is of the current window if it is not then we remove that.
- After that we check if the element present at the back of the deque is less that the current element.
- If so we keep on removing the element by until the element at the back of the deque is greater than the current element or the deque is empty.
- Push the current index of the element in the deque.
- Add the maximum element present at the front of the deque after the limit of the window has been reached.

# How to execute 
- Compile the program.
- Enter the size of array.
- Enter the size of window.
- Add elements to the array.

