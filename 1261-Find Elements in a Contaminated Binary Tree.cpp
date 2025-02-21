// T.C - O(n)
// S.C - O(n)
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
class FindElements {
public:
    unordered_set<int> vals;
    FindElements(TreeNode* root) {
        root->val = 0;
        vals.insert(0);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            int x = curr->val;
            vals.insert(x);

            if(curr->left){
                curr->left->val = 2*x+1;
                q.push(curr->left);
            }
            if(curr->right){
                curr->right->val = 2*x+2;
                q.push(curr->right);
            }
        }
    }
    
    bool find(int target) {
        return vals.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
