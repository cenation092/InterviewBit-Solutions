
int go( int l, int r, vector<int> &A, vector<vector<int> > &dp ){
    if( l > r )return 0;
    int &ans = dp[l][r];
    if( ans != -1 )return ans;
    for( int i = l; i <= r; i++ ){
        ans = max( ans, go(l, i-1, A, dp)+go(i+1, r, A, dp)+(l==0?1:A[l-1])*A[i]*(r==A.size()-1?1:A[r+1]) );
    }
    return ans;
}

int Solution::solve(vector<int> &A) {
    vector<vector<int> > dp(A.size(), vector<int>(A.size(), -1));
    return go(0, A.size()-1, A, dp);
}
