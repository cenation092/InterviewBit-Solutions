int Solution::solve(string A) {
    int n = A.size();
    int ans = 0;
    for( int i = 0; i < A.size(); i++ ){
        if( A[i] >= 'A' && A[i] <= 'Z' )A[i] = A[i] - 'A' + 'a';
        if( A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' ){
            ans = (ans + n-i) % 10003;
        }
    }
    return ans;
}
