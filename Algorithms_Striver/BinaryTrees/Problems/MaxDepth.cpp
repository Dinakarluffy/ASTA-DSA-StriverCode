                            
#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

// TreeNode struct represents
// a node in a binary tree
struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;

    // Default constructor for TreeNode
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    // parameter for TreeNode
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left
    // child, and right child
    // parameters for TreeNode
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if(root==NULL)return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return (1+max(lh,rh));
}
int maxDepthTree(TreeNode*root){
    if(root==NULL)return 0;
    int leftHeight=maxDepthTree(root->left);
    int rightHeight=maxDepthTree(root->right);
    return (1+max(leftHeight,rightHeight));
}