# Functionalities of Program
1. Merge Sorted Linked List
    - This program demonstrates the merging of two sorted linked lists into one sorted list. 
    - The function **mergeTwoLists** is used to 
        - check if the first list is empty so that it can return the second list.
        - check if the second list is empty so that it can return the first list.
        - if the val of first list is less than the second one then it will call the function mergeSortedLists by passing the first list as first argument and second list as second argument.
        - else  it will call the function mergeSortedLists by passing the second list as first argument and first list as second argument.
    - The function **mergeSortedLists** is used to merge the two sorted list in which the first list < second list.
    - **printList** is used to print the list.
    - **insertNode** is used to insert value in the linked list
    - **deleteList** is used to delete the list from the memory

2. Infix to Postfix Conversion and Evaluation
- isOperator Function:

    - Determines whether a given character is an arithmetic operator (+, -, *, /).
- getPrecedence Function:

    - Returns the precedence of a given operator. Higher precedence indicates a higher priority in the order of operations.
- infixToPostfix Function:

    - Converts an infix mathematical expression to postfix notation using a stack.
    - Handles operands, parentheses, and operators with the appropriate order of operations.
- evaluatePostfix Function:

    - Evaluates a postfix expression using a stack.
    - Supports basic arithmetic operations (+, -, *, /) on integer operands.
- Main Function:

    - Takes user input for an infix mathematical expression.
    - Calls infixToPostfix to convert the expression to postfix and displays the result.
    - Calls evaluatePostfix to evaluate the postfix expression and displays the final result.
# Instruction for executing 
1.Merge Sorted List
- Compile the program
- Input the number of element of 1st linked list.
- Enter the elements of linked list 1.
- Input the number of element of 2nd linked list.
- Enter the elements of linked list 2.

2.Infix to postfix conversion
- Compile the program 
- Enter the infix expression that you want to evalute.