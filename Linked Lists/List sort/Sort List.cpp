ListNode* merge(ListNode* A, ListNode* B ){
    ListNode *C = NULL;
    if( A == NULL )return B;
    if( B == NULL )return A;
    ListNode *head, *cur;
    if( A->val < B->val ){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    cur = head;
    while( A != NULL && B != NULL ){
        if( A->val < B->val ){
            cur->next = A;
            A = A->next;
        }
        else{
            cur->next = B;
            B = B->next;
        }
        cur = cur->next;
    }
    if( A != NULL )cur -> next = A;
    if( B != NULL )cur -> next = B;
    return head;
} 
 
ListNode* Solution::sortList(ListNode* A) {
    int n = 0;
    ListNode *temp = A;
    while( temp != NULL ){
        n++;
        temp = temp->next;
    }
    if( n < 2 )return A;
    ListNode *L = A;
    for( int i = 1; i < n/2; i++ ){
        A = A->next;
    }
    ListNode *R = A->next;
    A->next = NULL;
    L = sortList(L);
    R = sortList(R);
    return merge(L,R);
}