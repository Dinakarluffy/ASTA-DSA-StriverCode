#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the linked list

    // Constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor for initializing only the data
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
Node *convertArr(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // Move the pointer to the new node
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *addTwoNode(Node *l1, Node *l2)
{
        Node *dummy = new Node(-1); 
        Node *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> data; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            Node *node = new Node(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
}
int main()
{
    // The given two list is reverse order and sum it and  store in LL
    vector<int> arr1 = {3, 5};
    vector<int> arr2 = {4, 5, 9, 9};
    Node*h1=convertArr(arr1);
    Node*h2=convertArr(arr2);
    Node*h3=addTwoNode(h1,h2);
    print(h3);
}