ListNode* Solution::partition(ListNode* A, int x) {
    ListNode *iterator = A;
    ListNode *small = NULL, *small_Head = NULL;
    ListNode *large = NULL, *large_Head = NULL;
    while( iterator != NULL ){
        if( iterator->val < x ){
            if( small_Head == NULL ){
                small_Head = iterator;
                small = iterator;
            }
            else{
                small->next = iterator;
                small = small->next;
            }
        }
        else{
            if( large_Head == NULL ){
                large_Head = iterator;
                large = iterator;
            }
            else{
                large->next = iterator;
                large = large->next;
            }
        }
        iterator = iterator->next;
    }
    if( large != NULL )large->next = NULL;
    if( small != NULL )small->next = NULL;
    if( large_Head == NULL )return small_Head;
    if( small_Head == NULL )return large_Head;
    small = small_Head;
    while( small->next != NULL ){
        small = small->next;
    }
    small->next = large_Head;
    return small_Head;
    
}