#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int da, Node *le, Node *ri)
    {
        data = da;
        right = ri;
        left = le;
    }
    Node(int da)
    {
        data = da;
        right = NULL;
        left = NULL;
    }
};
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val > root->data)
        root->right = insert(root->right, val);
    else
    {
        root->left = insert(root->left, val);
    }
    return root;
}
void display(Node *root)
{
    if (root == NULL)
        cout << "No elements in tree";
    Node *temp = root;
    queue<Node *> qu;
    qu.push(temp);
    vector<vector<int>> ans;
    while (!qu.empty())
    {
        vector<int> level;
        for (int i = 0; i < qu.size(); i++)
        {
            Node *te = qu.front();
            qu.pop();
            level.push_back(te->data);
            if (te->left)
                qu.push(te->left);
            if (te->right)
                qu.push(te->right);
        }
        ans.push_back(level);
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *root = new Node(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        root = insert(root, arr[i]);
    }
    display(root);
}