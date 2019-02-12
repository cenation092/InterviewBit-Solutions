/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* find_source(TreeNode *root, int req ){
    queue<TreeNode*> q;
    q.push(root);
    while( !q.empty() ){
        TreeNode* cur = q.front(); q.pop();
        if( cur->val == req )return cur;
        if( cur->left != NULL )q.push(cur->left);
        if( cur->right != NULL )q.push(cur->right);
    }
    return NULL;
}

TreeNode* LcA( TreeNode* root, TreeNode* B, TreeNode* C ){
    if( root == NULL )return root;
    if( root == B || root == C )return root;
    TreeNode *left = LcA(root->left, B, C);
    TreeNode *right = LcA(root->right, B, C);
    if( left != NULL && right != NULL )return root;
    if( left == NULL )return right;
    else return left;
}

int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode *node1 = find_source(A, B);
    TreeNode *node2 = find_source(A, C);
    if( node1 == NULL || node2 == NULL )return -1;
    return LcA(A, node1, node2)->val;
}
