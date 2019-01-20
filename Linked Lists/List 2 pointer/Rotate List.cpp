/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int k) {
    ListNode *head, *temp = A;
    int n = 0;
    while( temp != NULL ){
        n++;
        if( temp->next == NULL )break;
        temp = temp->next;
    }
    k %= n;
    if( k == 0 )return A;
    n = n - k;
    ListNode *end = temp;
    temp = A;
    for( int i = 1; i < n; i++ ){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    end ->next = A;
    return head;
}
