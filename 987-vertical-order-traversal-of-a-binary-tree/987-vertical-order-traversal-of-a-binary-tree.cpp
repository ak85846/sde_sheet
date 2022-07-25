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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        queue<pair<int , TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()){
            multiset<pair<int,int>> tmp;
            int n=q.size();
            for(int i=0; i<n; i++){
                auto p = q.front();
                q.pop();
                tmp.insert({p.first,p.second->val});
                if(p.second->left) q.push({p.first-1 , p.second->left});                                
                if(p.second->right) q.push({p.first+1 , p.second->right});
            }
            for(auto p : tmp) m[p.first].push_back(p.second);
        }
        vector<vector<int>> res;
        for(auto [f,s] : m) res.push_back(s);
        return res;
    }
}; 