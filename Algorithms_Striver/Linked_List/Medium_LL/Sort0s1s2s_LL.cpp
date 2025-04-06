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
Node *SortZeorsOnesTwos_brute(Node *head)
{
    // TC=>O(2N)
    // SC=>O(1)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int cntz = 0, cntO = 0, cntT = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            cntz++;
        }
        else if (temp->data == 1)
        {
            cntO++;
        }
        else
        {
            cntT++;
        }
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (cntz)
        {
            temp->data = 0;
            cntz--;
        }
        else if (cntO)
        {
            temp->data = 1;
            cntO--;
        }
        else
        {
            temp->data = 2;
            cntT--;
        }
        temp = temp->next;
    }
    return head;
}
Node *SortZeorsOnesTwos_optimal(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *zeroHead = new Node(-1), *zero = zeroHead;
    Node *oneHead = new Node(-1), *one = oneHead;
    Node *twoHead = new Node(-1), *two = twoHead;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    Node *newHead = zeroHead->next;
    return newHead;
}
int main()
{
    vector<int> arr = {1, 0, 2, 1, 0};
    Node *h1 = convertArr2LL(arr);
    h1 = SortZeorsOnesTwos_brute(h1);
    print(h1);
    Node *h2 = convertArr2LL(arr);
    h2 = SortZeorsOnesTwos_optimal(h2);
    print(h2);
    return 0;
}