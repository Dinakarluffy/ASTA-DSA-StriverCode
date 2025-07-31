#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
 
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
    Node(int val, Node *left, Node *right) : data(val), left(left), right(right) {}
};
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}
void display(Node *root)
{
    if (root == NULL)
        cout << "No datas in the trees";
    else
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;

            for(int i=0;i<q.size();i++){
            Node *le = q.front();
            q.pop();
            level.push_back(le->data);
            if (le->left != NULL)
                q.push(le->left);
            if (le->right)
                q.push(le->right);
        }
        ans.push_back(level);
    }
    for(auto it:ans){
        for(auto els:it){
            cout<<els<<" ";
        }
        cout<<endl;
    }

    }
}
int main()
{
    int n=5;
    int arr[5]={1,2,3,4,5};
    Node * root =NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    display(root);    
    
    return 0;
}