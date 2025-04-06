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
Node *deleteMiddleNodeLL(Node *head)
{
    // SC=>(N+n/2)
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int res = cnt / 2;
    temp = head;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            Node *middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *deleteMiddleNodeLL_optimal(Node *head)
{
    // SC=>O(n/2)
    // The Tortoise and the Hare modify the algorithm according to the problem
    // THe change is skip one step ,so we increase one in the step in fast
    Node *slow = head, *fast = head;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    slow->next = slow->next;
    delete middle;
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    head = deleteMiddleNodeLL(head);
    print(head);
    Node *head1 = convertArr2LL(arr);
    head1 = deleteMiddleNodeLL(head1);
    print(head1);
}