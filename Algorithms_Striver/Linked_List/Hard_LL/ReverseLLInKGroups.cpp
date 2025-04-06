#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d, Node *n)
    {
        data = d;
        next = n;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
Node *convert2Arr(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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
    cout << endl;
}
Node *reverseLL(Node *head)
{
    
    Node *temp = head;

    // Initialize pointer 'prev' to NULL,
    // representing the previous node
    Node *prev = NULL;

    // Traverse the list, continue till
    // 'temp' reaches the end (NULL)
    while (temp != NULL)
    {
        // Store the next node in
        // 'front' to preserve the reference
        Node *front = temp->next;

        // Reverse the direction of the
        // current node's 'next' pointer
        // to point to 'prev'
        temp->next = prev;

        // Move 'prev' to the current
        // node for the next iteration
        prev = temp;

        // Move 'temp' to the 'front' node
        // advancing the traversal
        temp = front;
    }

    // Return the new head of
    // the reversed linked list
    return prev;
}
Node *reverseLL_recursive(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newNode = reverseLL_recursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newNode;
}
Node *findKthNode(Node *temp, int k)
{
    k -= 1;

    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
Node *reverseLLKGroup(Node *head, int k)
{
    if(head==NULL||k==1){
        return head;
    }
    Node*temp=head;
    Node*prevNode=NULL;
    while(temp!=NULL){
        Node*kthNode=findKthNode(temp,k);
        if(kthNode==NULL){
            if(prevNode){
                prevNode->next=temp;
            }
            break;
        }
        Node*nextNode=kthNode->next;
        kthNode->next=NULL;
        reverseLL(temp);
        if(temp==head){
            head=kthNode;
        }
        else{
            prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = convert2Arr(arr);
    // print(head);
    head = reverseLL(head);
    // print(head);
    int k = 3;
    Node *head1 = convert2Arr(arr);
    print(head1);
    Node *head2 = reverseLLKGroup(head1, 3);
    print(head2);
}