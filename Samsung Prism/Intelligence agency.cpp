/*
Problem Statement:
You are given a map of a country in the form of a binary tree where each node represents the position of a criminal organization. 
As a police officer, your task is to deploy handlers and spies to monitor the criminal network closely. 
To do so, you have assigned a handler at each level of the binary tree. 
Now, to minimize the risk of exposure, you need to assign the minimum number of spies at different locations (i.e., nodes in the binary tree). 
Each spy can observe activities of its current location and its directly connected locations, i.e., parent and child nodes. 
Find out and print the minimum number of spies required to monitor the whole network. 
Also, print the value of Y = a²x² + b²x, where a is the total number of handlers, b is the total criminal organizations, and x is the minimum number of spies required.

Input Format:
The input contains a single line:
- The line consists of multiple space-separated integers denoting the level order traversal of the tree where each positive integer denotes a node (i.e., position of the criminal organization).
- -1 denotes a NULL child and -2 denotes the termination of the tree.
The input will be read from the STDIN by the candidate.

Output Format:
The output will be two space-separated integers where the first one denotes the minimum number of spies needed to monitor the criminal network 
and the second one denotes the value of Y.
The output will be matched to the candidate's output printed on the STDOUT.

Constraints:
- 1 <= total number of positions of the criminal organization <= 9000

Example:
Input:
1 2 3 -1 5 -1 4 -2

Output:
2 22

Explanation:
The tree formed in the question are:
      1
    /   \
   2     3
  /     /
 5     4
- a = 3 => total handlers
- b = 5 => total criminal organizations
- x = 2 => minimum number of spies required
Two spies should be deployed so that they can do surveillance of (1, 2 and 5) and (1, 3 and 4) locations respectively 
which are directly connected locations 2 and 3.
Hence result: Y = 3²(2)² + 5²2 = 12 + 10 = 22.
*/

// T.C - O(n)
// S.C - O(n)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& nodes, int& a, int& b){
    if(nodes.empty() || nodes[0] == -2) return NULL;
    
    TreeNode* root = new TreeNode(nodes[0]);
    int i = 1;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while(i<nodes.size()){
        TreeNode* curr = q.front();
        q.pop();
        
        if(i<nodes.size() && nodes[i] != -1 && nodes[i] != -2){
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
            b++;
        }
        i++;
        
        if(i<nodes.size() && nodes[i] != -1 && nodes[i] != -2){
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
            b++;
        }
        i++;
    }
    
    queue<TreeNode*> levelQ;
    levelQ.push(root);
    
    while(!levelQ.empty()){
        int sz = levelQ.size();
        
        while(sz--){
            TreeNode* temp = levelQ.front();
            levelQ.pop();
            if(temp->left) levelQ.push(temp->left);
            if(temp->right) levelQ.push(temp->right);
        }
        a++;
    }
    
    return root;
}

// 0 - spy, 1 - monitored, 2- notmonitored

int dfs(TreeNode* root, int& spies){
    if(!root) return 1;
    
    int left = dfs(root->left,spies);
    int right = dfs(root->right,spies);
    
    if(left == 2 || right == 2){
        spies++;
        return 0;
    }
    
    if(left == 0 || right == 0) return 1;
    
    return 2;
}

int main()
{
    vector<int> nodes;
    int val;
    while(cin>>val && val != -2)
        nodes.push_back(val);
        
    int b = 1;
    int a = 0;  
    
    TreeNode* root = buildTree(nodes,a,b);
    // cout<<a<<" "<<b<<endl;
    
    int spies = 0;
    if(dfs(root,spies) == 2) spies++;
    
    int x = spies;
    int Y = a*x*x + b*x;
    
    cout<<x<<" "<<Y<<endl;
    return 0;
}
