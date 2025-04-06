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
Node *MergeNode(vector<Node *> lists)
{
    //TC=>O(N*K)+O(MlogM)+O(M)
    //SC=>O(M)+O(M)
    vector<int> arr;
    for (int i = 0; i < lists.size(); i++)
    {
        Node *temp = lists[i];
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(), arr.end());
    Node *head = convertArr2LL(arr);
    return head;
}
Node*mergeTwoNode(Node*list1,Node*list2){
    Node*dummyNode=new Node(-1);
    Node*res=dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data<list2->data){
            res->next=list1;
            res=list1;
            list1=list1->next;
        }
        else{
            res->next=list2;
            res=list2;
            list2=list2->next;
        }
    }
    if(list1)res->next=list1;
    if(list2)res->next=list2;
    return dummyNode->next;
}
Node *MergeKNode(vector<Node *> lists)
{
    //TC=>O(N1+N2))+O(N1+N2+N3)+O(N1+N2+N3+N4)=>ON((k*K+1)/2)
    //SC=>O(1)
    Node*head=lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        head=mergeTwoNode(head,lists[i]);
    }
    
    return head;
}
int main()
{
}