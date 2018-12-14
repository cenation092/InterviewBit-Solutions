int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int ans = 0;
    for( int i = 0; i < n-1; i++ ){
        ans += max( abs(A[i] - A[i+1]), abs(B[i] - B[i+1]) );
    }
    return ans;
}
