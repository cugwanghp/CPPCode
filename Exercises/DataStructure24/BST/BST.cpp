/*
 * @Description: 
 * @Version: 1.0
 * @Author: Wang Hongping
 * @Date: 2024-12-10 11:10:04
 * @LastEditors: Wang Hongping
 * @LastEditTime: 2024-12-10 11:10:10
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void findClosestValues(TreeNode* root, double target, vector<int>& closest) {
        if (!root) return;

        // Check the current node
        closest.push_back(root->val);
        
        // Decide which side to go based on the target
        if (target < root->val) {
            findClosestValues(root->left, target, closest);
        } else {
            findClosestValues(root->right, target, closest);
        }
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> closest;

        // Do the traversal to collect potential closest values
        findClosestValues(root, target, closest);
        
        // Sort the collected closest values based on their distance to the target
        sort(closest.begin(), closest.end(), [target](int a, int b) {
            return fabs(a - target) < fabs(b - target);
        });

        // Return the first k closest values
        if (closest.size() > k) {
            closest.resize(k);
        }

        return closest;
    }
};

int main() {
    // Constructing the BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    double target = 3.714286; // Example target value
    int k = 2; // Number of closest values to find

    Solution sol;
    vector<int> result = sol.closestKValues(root, target, k);

    cout << "The closest " << k << " values to " << target << " are:";
    for (int val : result) {
        cout << " " << val;
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
