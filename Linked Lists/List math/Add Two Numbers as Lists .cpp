ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if( !A )return B;
    if( !B )return A;
    int carry = 0;
    ListNode *root = NULL, *iterator;
    while( A != NULL || B != NULL ){
        int sum = carry;
        if( A != NULL )sum += A->val;
        if( B != NULL )sum += B->val;
        carry = sum / 10;
        sum = sum % 10;
        if( root == NULL ){
            root = new ListNode(sum);
            iterator = root;
        }
        else{
            iterator->next = new ListNode(sum);
            iterator = iterator->next;
        }
        if( A != NULL )A = A->next;
        if( B != NULL )B = B->next;
    }
    if( carry != 0 )iterator->next = new ListNode(carry);
    return root;
}
