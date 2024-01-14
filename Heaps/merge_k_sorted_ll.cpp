#include <iostream>
#include<vector>
#include<queue>

using namespace std;

// Node structure representing an element in the input lists
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparison function for the min-heap
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    for(auto l : lists) {
        if(l)  pq.push(l);
    }
    if(pq.empty())  return NULL;

    ListNode* head=new ListNode(0);
    ListNode* temp=head;
    while(!pq.empty())
    {
        ListNode* p = pq.top();
        pq.pop();
        temp->next = p;
        temp=temp->next;
        if(p->next!=NULL) pq.push(p->next);
    }
    return head->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode*> lists;

    // Creating three sorted lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    cout << "Original lists:" << endl;
    for (int i = 0; i < lists.size(); ++i) {
        cout << "List " << i + 1 << ": ";
        printList(lists[i]);
    }

    ListNode* mergedList = mergeKLists(lists);

    cout << "\nMerged list:" << endl;
    printList(mergedList);

    // Cleanup: free allocated memory
    for (ListNode* list : lists) {
        while (list != nullptr) {
            ListNode* temp = list;
            list = list->next;
            delete temp;
        }
    }

    // Cleanup: free merged list
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
