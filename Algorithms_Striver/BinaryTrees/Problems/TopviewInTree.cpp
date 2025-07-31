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
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> pair;
        pair.push({root, 0});
        while (!pair.empty())
        {
            auto it = pair.front();
            Node *temp = it.first;
            pair.pop();
            int line = it.second;
            if (mp.find(line) == mp.end())
                mp[line] = temp->data;
            if (temp->left)
            {
                pair.push({temp->left, line - 1});
            }
            if (temp->right)
            {
                pair.push({temp->right, line + 1});
            }
        }
        for (auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};