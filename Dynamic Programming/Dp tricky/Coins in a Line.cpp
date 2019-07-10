int go( int l, int r, vector<int> &A, vector<vector<int> > &dp ){
    if( l > r )return 0;
    if( l == r )return A[l];
    if( l+1 == r )return max(A[l], A[r]);
    if( dp[l][r] != -1 )return dp[l][r];
    int L = A[l] + min( go(l+1, r-1, A, dp), go(l+2, r, A, dp) );
    int R = A[r] + min( go(l+1, r-1, A, dp), go(l, r-2, A, dp) );
    return dp[l][r] = max(L, R);
}
 
int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > dp(n, vector<int> (n, -1));
    return go(0, (int)A.size()-1, A, dp);
}