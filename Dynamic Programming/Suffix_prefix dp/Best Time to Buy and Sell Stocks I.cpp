int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    if( n == 0 )return 0;
    int Max = A[n-1];
    for( int i = n-2; i >= 0; i-- ){
        if( A[i] > Max )Max = A[i];
        ans = max( ans, Max-A[i]);
    }
    return ans;
}