#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d, Node *n)
    {
        data = d;
        next = n;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
Node *convert2Arr(vector<int> &arr)
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
Node *findNthNode(Node *temp, int k)
{
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
            return temp;
        temp = temp->next;
        cnt++;
    }
    return temp;
}
Node *rotateLL(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    Node *tail = head;
    int cnt = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        cnt++;
    }
    if (k % cnt == 0)
        return head;
    k = k % cnt;
    tail->next = head;
    Node *newLastNode = findNthNode(head, cnt - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}
int main()
{
    // rightRotate
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convert2Arr(arr);
    head = rotateLL(head, 23);
    print(head);
}