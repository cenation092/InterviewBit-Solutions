int Div( int &num, int den ){
    int cnt = 0;
    while( num % den == 0 ){
        num /= den;
        cnt++;
    }
    return cnt;
}

int Solution::isPower(int A) {
    int num = A;a
    if( num == 1 )return 1;
    int have = 0;
    for( int i = 2; i * i <= A; i++ ){
        if( num % i == 0 ){
            int fre = Div(num, i);
            have = __gcd(have, fre);
            if( have == 1 ){
                return 0;
            }
        }
    }
    if( num != 1 )return 0;
    return 1;
}
