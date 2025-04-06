#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int da, Node *next1)
    {
        data = da;
        next = next1;
    }
    Node(int da)
    {
        data = da;
        next = NULL;
    }
};
Node *convertArr2LL(vector<int> &arr)
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
Node *removeNthNodeFromEnd_brute(Node *head, int n)
{
    // TC=>O(len)+O(len-N)=>O(2len)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == n)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }
    int res = cnt - n;
    temp = head;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
            break;

        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    return head;
}
Node *removeNthNodeFromEnd_optimal(Node *head, int n)
{
    //TC=>O(len)
    //SC=>O(1)
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*fast=head;
    Node*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if (fast==NULL)
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node*delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;

}
int main()
{
    // N=3 means you need to delete 3rd node from backward in ll
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    head = removeNthNodeFromEnd_brute(head, 3);

    print(head);
    Node *head1 = convertArr2LL(arr);
    head1 = removeNthNodeFromEnd_optimal(head1, 6);

    print(head1);
}