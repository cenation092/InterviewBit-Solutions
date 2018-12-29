/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* leaf( TreeNode *root , TreeNode *add ){
    if( root == NULL ){
        root = add;
        return root;
    }
    root->right = leaf( root->right, add);
    return root;
}

TreeNode* dfs( TreeNode *root ){ 
    if( root == NULL )return root;
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    swap(root->left, root->right);
    root->right = leaf(root->right, root->left);
    root->left = NULL;
    return root;
}

TreeNode* Solution::flatten(TreeNode* A) {
    return dfs(A);
}
