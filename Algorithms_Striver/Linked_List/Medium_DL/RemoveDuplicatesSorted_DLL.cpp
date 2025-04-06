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
        next = nullptr;
        back = nullptr;
    }
};
Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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
}
Node *RemoveDuplicates_DLL(Node *head)
{
    // Tc=>O(N)
    Node *temp = head;

    while (temp != NULL && temp != NULL)
    {
        Node *prev = temp->back;
        Node *nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if (nextNode)
            nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 4};
    Node *head = convertArr2DLL(arr);
    head = RemoveDuplicates_DLL(head);
    print(head);
}