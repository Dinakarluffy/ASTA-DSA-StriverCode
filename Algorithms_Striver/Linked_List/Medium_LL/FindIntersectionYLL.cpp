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
Node *intersectionPoint_LL(Node *head1, Node *head2)
{
    // TC=>O(N1*N)+O(N2*N)
    // SC=>O(N1)
    map<Node *, int> mpp;
    Node *temp = head1;
    while (temp != NULL)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Node *collisionPoint(Node *t1, Node *t2, int diff)
{
    while (diff)
    {
        diff--;
        t2 = t2->next;
    }
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}
Node *intersectionPoint_LL_Better(Node *head1, Node *head2)
{
    // TC=>O(N1)+O(N2)+O(N2-N1)+O(N1)
    Node *temp1 = head1;
    Node *temp2 = head2;
    int N1 = 0, N2 = 0;
    while (temp1 != NULL)
    {
        N1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        N2++;
        temp2 = temp2->next;
    }
    if (N1 < N2)
    {
        return collisionPoint(head1, head2, N2 - N1);
    }
    else
    {
        return collisionPoint(head2, head1, N1 - N2);
    }
}
Node *intersectionPoint_LL_optimal(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    Node *t1 = head1;
    Node *t2 = head2;
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
        if (t1 == t2)
            return t1;
        if (t1 == NULL)
            t1 = head2;
        if (t2 == NULL)
            t2 = head1;
    }
    return t1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> arr2 = {10, 2, 3, 4};
    Node *head1 = convertArr2LL(arr);
    Node *head2 = convertArr2LL(arr2);
    Node *ans = intersectionPoint_LL(head1, head2);
    print(ans);
}