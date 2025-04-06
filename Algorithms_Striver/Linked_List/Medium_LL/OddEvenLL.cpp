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
Node *OddEvenSegregated_Brute(Node *head)
{
    // TC=>O(2N)
    // SC=>O(n)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
    {
        arr.push_back(temp->data);
    }
    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
    {
        arr.push_back(temp->data);
    }
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
Node *OddEvenSegregated_Optimal(Node *head)
{
    // TC=>O(N)
    // SC=>O(1)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main()
{
    // Create List odd lenght node will first after arranging odd ,arrange even Nodes
    vector<int> arr = {1, 2, 3, 4, 5,6};
    Node *head = convertArr2LL(arr);
    head = OddEvenSegregated_Brute(head);

    print(head);
    Node *head1 = convertArr2LL(arr);
    head1 = OddEvenSegregated_Optimal(head1);

    print(head1);
}