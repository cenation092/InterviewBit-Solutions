int inc( int pre, int cur, const vector<int> &A, vector<vector<int> > &dp ){
    if( cur < 0 )return 0;
    if( dp[pre][cur] != -1 )return dp[pre][cur];
    int Ans = 0;
    if( A[pre] > A[cur] ){
        Ans = 1 + inc(cur, cur-1, A, dp);
    }
    Ans = max( Ans, inc(pre, cur-1, A, dp));
    return dp[pre][cur] = Ans;
}

int dec( int pre, int cur, const vector<int> &A, vector<vector<int> > &dp ){
    if( cur == A.size() )return 0;
    if( dp[pre][cur] != -1 )return dp[pre][cur];
    int Ans = 0;
    if( A[pre] > A[cur] ){
        Ans = 1 + dec(cur, cur+1, A, dp);
    }
    Ans = max( Ans, dec(pre, cur+1, A, dp));
    return dp[pre][cur] = Ans;
}

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    int Ans = 0;
    vector<vector<int> > idp(n, vector<int>(n, -1)), ddp(n, vector<int>(n, -1));
    for( int i = 0; i < A.size(); i++ ){
        int l = 1+inc(i, i-1, A, idp);
        int r = dec(i, i+1, A, ddp);
        //cout << i << " -> " << l << " | " << r << endl;
        Ans = max( Ans, l+r);
    }
    return Ans;
}
