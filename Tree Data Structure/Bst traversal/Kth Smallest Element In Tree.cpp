int ans;
int K;
void dfs( TreeNode *root){
    if( root == NULL || K < 0 )return;
    dfs(root->left);
    K--;
    if( K == 0 ){
        ans = root->val;
        return;
    }
    dfs(root->right);
}
    
int Solution::kthsmallest(TreeNode* A, int B) {
    K = B;
    dfs(A);
    return ans;
}