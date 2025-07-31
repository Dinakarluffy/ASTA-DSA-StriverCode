#include <iostream>

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Structure definition for
// a node in a binary tree
struct Node
{
    // Defining the value of
    // the node (integer data)
    int data;
    // Reference pointer to
    // the left child node
    Node *left;
    // Reference pointer to
    // the right child node
    Node *right;

    // Method to initialize
    // the node with a value
    Node(int val)
    {
        // Set the value of the
        // node to the passed integer
        data = val;
        // Initialize left and
        // r ight pointers as NULL
        left = right = NULL;
    }
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

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    // Creating a new node for the root of the
    // binary tree using dynamic allocation
    Node *root = new Node(1);
    // Creating left and right child
    // nodes for the root node
    root->left = new Node(2);
    root->right = new Node(3);
    // Creating a right child node for
    // the left child node of the root
    root->left->right = new Node(5);
}