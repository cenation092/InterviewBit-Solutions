int Solution::reverse(int A) {
    int neg = 0;
    if( A < 0 )neg = 1, A = -A;
    long long R = 0;
    while( A > 0 ){
        R = R * 10 + A % 10;
        A /= 10;
    }
    if( R > (long long)INT_MAX)return 0;
    if( neg) R = -R;
    return R;
}
