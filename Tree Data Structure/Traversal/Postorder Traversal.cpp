/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> v;
    int empty = 1;
    TreeNode *cur = A;
    while(1){
        while( cur != NULL ){
            s.push(cur);
            s.push(cur);
            cur = cur->left;
        }
        if(s.empty())break;
        cur = s.top();
        s.pop();
        if( !s.empty() && s.top() == cur )cur = cur->right;
        else{
            v.push_back(cur->val);
            cur = NULL;
        } 
    }
    return v;
}
