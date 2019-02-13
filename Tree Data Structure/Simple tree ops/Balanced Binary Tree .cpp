/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int check( TreeNode *A , int &flag){
    if( A == NULL )return 0;
    int l = 1+check(A->left, flag);
    int r = 1+check(A->right, flag);
    if( abs(l-r) > 1 )flag = 0;
    return max(l, r);
} 

int Solution::isBalanced(TreeNode* A) {
    int flag = 1;
    check(A, flag);
    return flag;
}
