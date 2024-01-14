#include <iostream>
using namespace std;
int count = 0;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertAtBst(Node* root,int data){
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {

        root->right = insertAtBst(root->right, data);
    }
    else
    {
        root->left = insertAtBst(root->left, data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root= insertAtBst(root, data);
        cin>>data;
    }
}

void kthSmallest(Node* root, int &k,int &result){
    if(root == NULL || k==0)
        return;
    kthSmallest(root->left,k,result);
    k--;

    if(k==0){
        result = root->data;
        return;
    }

    kthSmallest(root->right,k,result);
}
int main(){
    Node* root = NULL;
    cout<<"Enter the data to create binary search tree:(Enter -1 for termination)";
    takeInput(root);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result = -1;
    kthSmallest(root,k,result);
    cout<< result;
}