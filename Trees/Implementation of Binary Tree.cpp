#include <iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(vector<int>& arr, int& index){
    if(index >= arr.size()) return nullptr;
    
    if(arr[index] == -1){
        index++;
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(arr[index]);
    index++;
    root->left = buildTree(arr,index);
    root->right = buildTree(arr,index);
    return root;
}

void preOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    cout<<root->val<<" -> ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    return ;
}

void inOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    preOrderTraversal(root->left);
    cout<<root->val<<" -> ";
    preOrderTraversal(root->right);
    return ;
}

void postOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    cout<<root->val<<" -> ";
    return ;
}

void levelOrderTraversal(TreeNode* root){
    if(root == NULL) return ;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        
        cout<<node->val<<" ";
        
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    
    return ;
}
int main()
{   
    vector<int> arr = {1,3,4,2,-1,-1,2,3,-1,-1};
    int index = 0;
    TreeNode* root = buildTree(arr,index);
    cout<<"preOrderTraversal"<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"inOrderTraversal"<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"postOrderTraversal"<<endl;
    postOrderTraversal(root);
    cout<<endl;
    cout<<"levelOrderTraversal"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}
