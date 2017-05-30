/*Count of Smaller Numbers After Self  - leet solution c++ */



class Solution {
public:
    struct Node{
        int val;
        int sum;
        int dup;
        Node *left;
        Node *right;
        Node(int val, int sum) : val(val), sum(sum), dup(1),
                                    left(nullptr), right(nullptr) {}
    };
    
    Node *insert(Node *root, int num, int i, vector<int> &res, int c) {
        if(root == nullptr) {
            root = new Node(num, 0);
            res[i] = c;
        }
        else if(root->val > num) {
            root->sum++;
            root->left = insert(root->left, num, i, res, c);
        }
        else if(root->val < num) {
            root->right = insert(root->right, num, i, res, c + root->dup + root->sum);
        }
        else if(root->val == num) {
            root->dup++;
            res[i] = c+root->sum;
        }
        return root;
    }
    vector<int> countSmaller(vector<int>& nums) {
        auto n = nums.size();
        vector<int> res(n, 0);
        Node *root=nullptr;
        for(int i=n-1; i >= 0; --i) {
            root = insert(root, nums[i], i, res, 0);
        }
        return res;
        
    }
};
