#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void recursiveRightView(Node *root, int level,vector<int>&ans)
    {
        if(root==NULL)return;
        if(level==ans.size()){ans.push_back(root->data);}
        recursiveRightView(root->right,level+1,ans);
        recursiveRightView(root->left,level+1,ans);
    }
    vector<int> rightViewTree(Node*root){
        int level=0;
        vector<int>ans;
        if(root==NULL)ans;
        recursiveRightView(root,level,ans);
        return ans;
    }
    void recursiveLeftView(Node *root, int level,vector<int>&ans)
    {
        if(root==NULL)return;
        if(level==ans.size()){ans.push_back(root->data);}
        recursiveRightView(root->left,level+1,ans);

        recursiveRightView(root->right,level+1,ans);
    }
    vector<int> lefttViewTree(Node*root){
        int level=0;
        vector<int>ans;
        if(root==NULL)ans;
        recursiveLeftView(root,level,ans);
        return ans;
    }
};