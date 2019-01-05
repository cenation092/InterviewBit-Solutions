int Solution::isPalindrome(int A) {
    if( A < 0 )return 0;
    int R = 0, S = A;
    while( A > 0 ){
        R = R * 10 + A%10;
        A /= 10;
    }
    if( R == S )return 1;
    return 0;
}
