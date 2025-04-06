#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    }
};
Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, mover);
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
Node *DeleteAllOccurenceKeyDLL(Node *head, int key)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *nextNode = temp->next;

            Node *prev = temp->back;
            if (nextNode)
            {
                nextNode->back = prev;
            }
            if (prev)
            {
                prev->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 2, 2, 2, 1, 2, 2, 2, 2};
    Node *head = convertArr2DLL(arr);
    head = DeleteAllOccurenceKeyDLL(head, 2);
    print(head);
}