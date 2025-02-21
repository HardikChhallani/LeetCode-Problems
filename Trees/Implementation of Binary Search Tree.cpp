#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right) {}
};

class BST{
public:
    BST() {}
    
    TreeNode* insertElement(TreeNode* node, int val){
        if(!node)
            return new TreeNode(val);
        
        if(node->val == val) return node;
        
        if(node->val < val)
            node->right = insertElement(node->right,val);
        else if(node->val > val)
            node->left = insertElement(node->left,val);
        
        return node;
    }
    
    void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }
};

int main(){
    BST bst;
    TreeNode* root = nullptr;
    
    int x = 0;
    while (true) {
        cin >> x;
        if (x == -1) break; 
        root = bst.insertElement(root, x);
    }
    
    cout<<"inorder is"<<endl;
    bst.inorderTraversal(root);
    return 0;
}
