#define mod 1000000007

long long go(int point, vector<long long> &dp ){
    if( point == 0 || point == 1 )return 1;
    if( dp[point] != -1 )return dp[point];
    long long ans = 0;
    for( int i = 0; i < point; i++ ){
        ans = (ans%mod + (go(i, dp)%mod *1LL* go(point-i-1, dp)%mod) % mod) % mod;
    }
    return dp[point] = ans;
}

int Solution::chordCnt(int A) {
    vector<long long> dp(A+1, -1);
    return go(A, dp);
}
