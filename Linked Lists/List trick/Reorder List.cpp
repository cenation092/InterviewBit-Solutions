 ListNode* merge(ListNode *A, ListNode *B){
    if( A == NULL )return B;
    if( B == NULL )return A;
    int who =  0;
    ListNode *root = A;
    ListNode *iterator = A;
    while( A != NULL && B != NULL ){
        if( who&1 ){
            iterator->next = A;
            iterator = A;
            A = A->next;
        }
        else{
            iterator->next = B;
            iterator = B;
            B = B->next;
        }
        who++;
    }
    if( A != NULL )iterator->next = A;
    if( B != NULL )iterator->next = B;
    return root;
}

ListNode *reverseNode( ListNode *head ){
    if( head == NULL || head->next == NULL )return head;
    ListNode *iterator = head, *prev = head;
    iterator = iterator->next;
    prev->next = NULL;
    while( iterator != NULL ){
        ListNode *Temp = iterator->next;
        iterator->next = prev;
        prev = iterator;
        if( Temp == NULL )break;
        iterator = Temp;
    }
    return iterator;
}

ListNode* Solution::reorderList(ListNode* A) {
    ListNode *slow = A, *fast = A;
    while( slow->next != NULL && fast->next != NULL && fast->next->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;
    ListNode *B = reverseNode(mid);
    return merge(A, B);
}
