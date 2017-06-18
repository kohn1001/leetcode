/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(!root){
            return output;
        }
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0,root));
		/* 
		 *
		 */
        while(!q.empty()){
            int size = q.size();
                TreeNode* t = q.front().second;
                int indx = q.front().first;
                q.pop();
                m[indx].push_back(t->val);
                if(t->left){
                    q.push(make_pair(indx - 1, t->left));
                }
                if(t->right){
                    q.push(make_pair(indx + 1, t->right));
                    
                }
        }
        for(auto& v : m){
            output.push_back(v.second);
        }
        return output;
    
    }
};
