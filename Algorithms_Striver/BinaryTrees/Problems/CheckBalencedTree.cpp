
#include <iostream>
#include <algorithm>

using namespace std;

// Balenced Binary Tree ->For Every Node ,(height of left)-(height of right)<=1

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
    // Function to check if a binary tree is balanced
    bool isBalanced(Node *root)
    {
        // If the tree is empty, it's balanced
        if (root == nullptr)
        {
            return true;
        }

        // Calculate the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Check if the absolute difference in heights
        // of left and right subtrees is <= 1
        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right))
        {
            return true;
        }

        // If any condition fails, the tree is unbalanced
        return false;
    }

    // Function to calculate the height of a subtree
    int getHeight(Node *root)
    {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == nullptr)
        {
            return 0;
        }

        // Recursively calculate the height
        // of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Return the maximum height of left and right subtrees
        // plus 1 (to account for the current node)
        return max(leftHeight, rightHeight) + 1;
    }

    int leftHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + leftHeight(node->left);
    }

    int rightHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + rightHeight(node->right);
    }

    bool NaiveCheck(Node *node)
    {
        if (node == NULL)
            return true;

        int LH = leftHeight(node);
        int RH = rightHeight(node);

        if (abs(LH - RH) > 1)
            return false;

        return NaiveCheck(node->left) && NaiveCheck(node->right);
    }

    int checkOptimal(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // Recursively calculate the height
        // of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Return the maximum height of left and right subtrees
        // plus 1 (to account for the current node)
        if(abs(leftHeight-rightHeight)>1)return -1;
        if(leftHeight==-1 || rightHeight==-1)return -1;  
        return max(leftHeight, rightHeight) + 1;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
