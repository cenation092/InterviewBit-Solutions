/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *pre = NULL;
TreeNode *first = NULL;
TreeNode *second = NULL;

void inorder( TreeNode *root ){
    if( root == NULL )return;
    inorder(root->left);
    if( pre == NULL )pre = root;
    else{
        if( pre->val > root->val ){
            if( first == NULL ){
                first = pre;
            }
            second = root;
        }
        pre = root;
    }
    inorder(root->right);
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    pre = NULL;
    first = NULL;
    second = NULL;
    vector<int> v;
    inorder(A);
    if( first != NULL && second != NULL ){
        v.push_back(first->val);
        v.push_back(second->val);
        if( v[0] > v[1] )swap(v[0], v[1]);
    }
    return v;
}
