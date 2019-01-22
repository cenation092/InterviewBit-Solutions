ListNode *rev( ListNode *head ){
    if( head == NULL || head->next == NULL )return head;
    ListNode *root = NULL;
    while( head != NULL ){
        ListNode *Temp = head->next;
        head->next = root;
        root = head;
        head = Temp;
    }
    return root;
}

int Solution::lPalin(ListNode* A) {
    ListNode *slow = A, *fast = A;
    while( fast != NULL && fast->next != NULL && fast->next->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *B = rev(slow->next);
    slow->next = NULL;
    while( A != NULL && B != NULL ){
        if( A->val != B->val )return 0;
        A = A->next;
        B = B->next;
    }
    return 1;
}