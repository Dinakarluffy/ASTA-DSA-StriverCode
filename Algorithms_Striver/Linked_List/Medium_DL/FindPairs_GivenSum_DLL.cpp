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
vector<vector<int>> FindPairs_DLL(Node *head, int sum)
{
    Node *temp1 = head;
    vector<vector<int>> pairs;
    while (temp1 != NULL)
    {
        Node *temp2 = temp1->next;
        while (temp2 != NULL && temp1->data + temp2->data <= sum)
        {
            if (temp1->data + temp2->data == sum)
            {
                pairs.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return pairs;
}
Node *findTail(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairs(Node *head, int sum)
{
    //This work only DLL is sorted
    //TC=>O(N)+O(N)
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;
    Node *left = head;
    Node *right = findTail(head);
    while (left->data < right->data)
    {
        if (left->data + right->data == sum)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if (left->data + right->data < sum)
        {
            left = left->next;
        }
        else
        {
            right = right->back;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2,3};
    int target = 3;
    Node *head = convertArr2DLL(arr);
    vector<vector<int>> value = FindPairs_DLL(head, target);
    for (auto it : value)
    {
        for (auto els : it)
        {
            cout << els << " ";
        }
        cout << endl;
    }
    vector<pair<int, int>> ans1 = findPairs(head, target);
    for (auto it : ans1)
    {
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;
}