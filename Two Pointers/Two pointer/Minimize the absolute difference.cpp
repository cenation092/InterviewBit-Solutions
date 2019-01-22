int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int a = 0, b = 0, c = 0;
    int ans = 1000000000;
    while(a < A.size() and b < B.size() and c < C.size() ){
        vector<int> v = {A[a], B[b], C[c]};
        sort(v.begin(), v.end());
        ans = min( ans, v[2]-v[0]);
        if( A[a] == v[0] )a++;
        if( B[b] == v[0] )b++;
        if( C[c] == v[0] )c++;
    }
    return ans;
}
