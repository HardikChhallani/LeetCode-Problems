class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();

        int rootVal = 0;
        int i = 0;
        while(i<n && isdigit(traversal[i])){
            rootVal = rootVal*10 + (traversal[i]-'0');
            i++;
        }

        TreeNode* root = new TreeNode(rootVal);
        stack<TreeNode*> st;
        st.push(root);

        while(i<n){
            int depth = 0;

            while(i<n && traversal[i] == '-'){
                depth++;
                i++;
            }

            int num = 0;
            while(i<n && isdigit(traversal[i])){
                num = num*10 + (traversal[i]-'0');
                i++;
            }

            TreeNode* temp = new TreeNode(num);

            while(st.size() > depth) st.pop();

            TreeNode* parent = st.top();

            if(parent->left == nullptr)
                parent->left = temp;
            else 
                parent->right = temp;
            
            st.push(temp);
        }
        return root;
    }
};
