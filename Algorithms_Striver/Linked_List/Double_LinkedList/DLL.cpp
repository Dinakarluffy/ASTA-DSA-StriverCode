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
Node *DeleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}
Node *DeleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;

    // or
    //  while (prev->next->next != NULL)
    //  {
    //      prev = prev->next;
    //  }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    delete tail;
    return head;
}
Node *DeleteKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;
    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return DeleteHead(head);
    }
    else if (front == NULL)
    {
        return DeleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    kNode->next = NULL;
    kNode->back = NULL;
    delete kNode;
    return head;
}
void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == NULL)
    {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = NULL;
    delete temp;
}
Node *insertBeforeHead(Node *head, int value)
{
    Node *newNode = new Node(value, head, NULL);
    head->back = newNode;
    return newNode;
}
Node *insertBeforeTail(Node *head, int value)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, value);
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;

    Node *newNode = new Node(value, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
Node *insertBeforeKThElement(Node *head, int k, int value)
{
    if (k == 1)
    {
        return insertBeforeHead(head, value);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(value, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
void insertBeforNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *h1 = convertArr2DLL(arr);
    print(h1);
    cout << endl;
    Node *h2 = convertArr2DLL(arr);
    h2 = DeleteHead(h2);
    print(h2);
    cout << endl;
    Node *h3 = convertArr2DLL(arr);
    h3 = DeleteTail(h3);
    print(h3);
    cout << endl;
    cout << "Delete Kth Element" << endl;
    Node *h4 = convertArr2DLL(arr);
    h4 = DeleteKthElement(h4, 4);
    print(h4);
    cout << endl;
    cout << "Delete Node" << endl;
    Node *h5 = convertArr2DLL(arr);
    deleteNode(h5->next->next->next);
    print(h5);
    cout << endl;
    cout << "Insert Before Head" << endl;
    Node *h6 = convertArr2DLL(arr);
    h6 = insertBeforeHead(h6, 113);
    print(h6);
    cout << endl;
    cout << "Insert Before tail" << endl;
    Node *h7 = convertArr2DLL(arr);
    h7 = insertBeforeTail(h7, 90);
    print(h7);
    cout << endl;
    cout << "Insert Before Kth Element" << endl;
    Node *h8 = convertArr2DLL(arr);
    h8 = insertBeforeKThElement(h8, 4, 101);
    print(h8);
    cout << endl;
    cout << "Insert Before Node" << endl;
    Node *h9 = convertArr2DLL(arr);
    insertBeforNode(h9->next->next, 101);
    print(h9);
    cout << endl;
    return 0;
}