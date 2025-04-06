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
int Length_Loop_LL(Node *head)
{
    // TC=>O(N*2NlogN)
    // SC=>O(1)
    map<Node *, int> mp;
    Node *temp = head;
    int timer = 1;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            int value = mp[temp];
            return (timer - value);
        }
        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}
int findlength(Node *slow, Node *fast)
{
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt++;
        fast = fast++;
    }
    return cnt;
}
int Length_Loop_LL_optimal(Node *head)
{
    // TC=>O(n)
    Node *slow = head;
    Node *fast = fast;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findlength(slow,fast);
        }
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    Node *head = convertArr2LL(arr);
    Node *link = head;
    Node *temp = head;

    if (temp != NULL)
    {
        temp->next = link;
    }
    int n = Length_Loop_LL(temp);
    cout << n << endl;
}