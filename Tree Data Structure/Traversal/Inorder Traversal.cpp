/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    stack<TreeNode*> s;
    TreeNode *cur = A;
    int empty = 0;
    while(!empty){
        if( cur != NULL ){
            s.push(cur);
            cur = cur->left;
        }
        else{
            if( !s.empty() ){
                cur = s.top();
                v.push_back(cur->val);
                cur = cur->right;
                s.pop();
            }
            else empty = 1;
        }
    }
    return v;
}
