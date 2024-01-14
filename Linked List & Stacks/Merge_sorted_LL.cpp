#include <iostream>
using namespace std;

// Node structure representing an element in the input lists
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *mergeSortedLists(ListNode *list1, ListNode *list2)
{
    // Initialize pointers to traverse the two lists
    ListNode *curr1 = list1; // Pointer for the first list
    ListNode *curr2 = list2; // Pointer for the second list

    // Pointers to keep track of the next node in each list
    ListNode *next1 = curr1->next;
    ListNode *next2 = curr2->next;

    // Check if the first list is empty, in that case, simply append the second list
    if (next1 == nullptr)
    {
        curr1->next = curr2;
        return list1;
    }

    // Traverse the first list until the end or until the second list is empty
    while (next1 != nullptr && curr2 != nullptr)
    {
        // Check if the current node in the first list is less than or equal to the current node in the second list
        // and less than the next node in the first list
        if ((curr1->val <= curr2->val) && (curr2->val <= next1->val))
        {
            // Insert the current node from the second list into the first list
            curr1->next = curr2;

            // Update pointers for the second list
            next2 = curr2->next;
            curr2->next = next1;

            // Move pointers in both lists
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Move forward in the first list
            curr1 = next1;
            next1 = next1->next;

            // If the end of the first list is reached, append the remaining nodes from the second list
            if (next1 == nullptr)
            {
                curr1->next = curr2;
                return list1;
            }
        }
    }

    // Return the merged list
    return list1;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->val < list2->val)
        return mergeSortedLists(list1, list2);
    else
        return mergeSortedLists(list2, list1);
}

// Function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
// Function to insert a node at the end of a linked list
void insertNode(ListNode *&head, int val) {
    ListNode *newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a linked list
void deleteList(ListNode *&head) {
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    // Initialize the lists
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    // Input for List 1
    int n1;
    cout << "Enter the number of elements for List 1: ";
    cin >> n1;

    cout << "Enter elements for List 1 in sorted order:\n";
    for (int i = 0; i < n1; ++i) {
        int val;
        cin >> val;
        insertNode(l1, val);
    }

    // Input for List 2
    int n2;
    cout << "Enter the number of elements for List 2: ";
    cin >> n2;

    cout << "Enter elements for List 2 in sorted order:\n";
    for (int i = 0; i < n2; ++i) {
        int val;
        cin >> val;
        insertNode(l2, val);
    }

    // Print the input lists
    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    // Merge the lists
    ListNode *merged = mergeTwoLists(l1, l2);

    // Print the merged list
    cout << "Merged List: ";
    printList(merged);

    // Cleanup
    deleteList(l1);
    deleteList(l2);
    deleteList(merged);

    return 0;
}
