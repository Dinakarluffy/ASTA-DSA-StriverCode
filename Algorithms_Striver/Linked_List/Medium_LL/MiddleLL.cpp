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
Node *middle_LL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int middle = (cnt / 2) + 1;
    temp = head;
    while (temp != NULL)
    {
        middle = middle - 1;
        if (middle == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}
Node *middleLL_optimal(Node *head)
{
    // TC=>O(n/2)
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    head = middle_LL(head);
    cout << head->data << endl;
    Node *head1 = convertArr2LL(arr);
    head1 = middleLL_optimal(head1);
    cout << head1->data << endl;
}