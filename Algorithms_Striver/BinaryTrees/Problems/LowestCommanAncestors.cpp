#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;
// USE inorder
struct Node
{
    int val;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val1) : val(val1), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};