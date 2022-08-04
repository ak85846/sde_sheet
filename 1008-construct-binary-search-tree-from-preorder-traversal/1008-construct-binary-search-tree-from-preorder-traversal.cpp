/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return backtrack(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* backtrack(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int first_larger = start + 1;
        while (first_larger <= end && preorder[first_larger] < preorder[start]) {
            first_larger++;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        root->left = backtrack(preorder, start + 1, first_larger - 1);
        root->right = backtrack(preorder, first_larger, end);
        return root;
    }
};