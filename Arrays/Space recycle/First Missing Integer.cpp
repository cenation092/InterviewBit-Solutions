long long mod = 1000000000;
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int flag = 0;
    for( int i = 0; i < n; i++ ){
        if( A[i] == n )flag = 1;
        if( A[i] < 0 || A[i] >= n )A[i] = 0;
    }
    for( int i = 0; i < n; i++ ){
        while( A[i] > 0 && A[i] != i && A[A[i]] != A[i] ){
            swap(A[i], A[A[i]]);
        }
    }
    for( int i = 1; i < n; i++ ){
        if( A[i] != i )return i;
    }
    if( !flag )return n;
    return n+1;
}