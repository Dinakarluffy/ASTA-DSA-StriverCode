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
Node *Detection_Loop_LL(Node *head)
{
    // TC=>O(N*2NlogN)
    // SC=>O(1)
    map<Node *, int> mp;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return temp;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return temp;
}
void printLoopNodes_LL(Node *head)
{
    Node *temp = head;
    temp = Detection_Loop_LL(temp);
    Node *temp1 = temp;

    temp = temp->next;
    while (temp1 != temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *StartingPoint_Loop_LL_optimal(Node *head)
{
    // TC=>O(n)
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // starting point
        }
    }
    return NULL;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    Node *head = convertArr2LL(arr);
    Node *link = head;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->next = link;
    }

    printLoopNodes_LL(temp);
    Node *head1 = StartingPoint_Loop_LL_optimal(temp);
    print(head1);
}