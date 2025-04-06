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
Node *sortLL(Node *head)
{
    // TC=>O(N+NlogN+N)
    // SC=>O(N)
    Node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    int i = 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    while (i < n && temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next; // Chage because in even length middle normal alg return middle,in merge
    // sort need m1 ,so that's why
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeTwoNode(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;

            list1 = list1->next;
        }
        else
        {
            temp->next = list2;

            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1 != NULL)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummyNode->next;
}
Node *sortLL_optimal(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middleNode = findMiddle(head);
    Node *left = head;
    Node *right = middleNode->next;
    middleNode->next = NULL;
    left = sortLL_optimal(left);
    right = sortLL_optimal(right);
    return mergeTwoNode(left, right);
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    Node *head = convertArr2LL(arr);
    head = sortLL(head);
    print(head);
    Node *head1 = convertArr2LL(arr);
    head1 = sortLL_optimal(head1);
    print(head1);
}
