/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<pair<int, ListNode*>, vector< pair<int, ListNode*> >, greater< pair<int, ListNode*> > > cur;
    for( int i = 0; i < A.size(); i++ ){
        cur.push( make_pair(A[i]->val, A[i]));
    }
    ListNode *root = new ListNode(0);
    ListNode *tail = root;
    while( !cur.empty() ){
        pair<int, ListNode*> temp = cur.top();
        cur.pop();
        tail->next = temp.second;
        tail = tail->next;
        if( tail->next != NULL ){
            cur.push(make_pair(tail->next->val, tail->next));
        }
    }
    return root->next;
}
