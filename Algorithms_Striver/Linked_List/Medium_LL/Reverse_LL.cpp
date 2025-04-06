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
Node *reverseLL_brute(Node *head)
{
    // TC=>O(2n)
    // SC=>O(n)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node *reverseLL_optimal(Node *head)
{
    // TC=>O(n)
    // SC=>O(1)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;

    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *reverseLL_recursive(Node *head)
{
    // TC=>O(2n)
    // SC=>O(n)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLL_recursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    head = reverseLL_brute(head);

    print(head);
    Node *head1 = convertArr2LL(arr);
    head1 = reverseLL_optimal(head1);

    print(head1);
    Node *head2 = convertArr2LL(arr);
    head2 = reverseLL_recursive(head2);

    print(head2);
    return 0;
}