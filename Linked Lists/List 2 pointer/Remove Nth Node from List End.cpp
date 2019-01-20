/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = 0;
    ListNode *iterator = A;
    while( iterator != NULL ){
        n++;
        iterator = iterator->next;
    }
    if( B >= n ){
        return A->next;
    }
    n = n - B;
    iterator = A;
    for( int i = 1; i < n; i++ ){
        iterator = iterator->next;
    }
    if( iterator->next != NULL )iterator->next = iterator->next->next;
    return A;
}
