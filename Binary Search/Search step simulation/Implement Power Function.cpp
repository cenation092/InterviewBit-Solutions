int go_code( int a, int n, int mod ){
    if( a == 0 )return 0;
    int ans = 1, neg = 0;
    if( a < 0 ){
        if( n&1 )neg = 1;
        a = -a;
    }
    while( n > 0 ){
        if( n&1 )ans = (ans *1LL* a) % mod;
        a = (a *1LL* a) % mod;
        n /= 2;
    }
    if( neg ){
        ans = -ans;
        while( ans < 0 )ans += mod;
    }
    return ans;
}

int Solution::pow(int x, int n, int d) {
    return go_code(x,n,d);
}
