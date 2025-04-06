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
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
Node *AddOneToLL_brute(Node *head)
{
    // TC=>O(3N)
    // SC=>O(1)
    head = reverseLL(head);

    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseLL(head);
    return head;
}
int addHelper(Node *temp)
{
    if (temp == NULL)
    {
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->data = temp->data + carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}
Node *AddOneToLL_optimal(Node *head)
{
    // TC=>O(3N)
    // SC=>O(1)
    int carry = addHelper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);

        newNode->next = head;
        head = newNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {9, 9, 9};

    Node *head1 = convertArr2LL(arr);
    head1 = AddOneToLL_brute(head1);

    print(head1);
    Node *head2 = convertArr2LL(arr);
    head2 = AddOneToLL_optimal(head2);

    print(head2);
}