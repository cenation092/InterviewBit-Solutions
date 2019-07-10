int Solution::maxProduct(const vector<int> &A) {
    int Min = A[0], Max = A[0];
    int Ans = A[0];
    for( int i = 1; i < A.size(); i++ ){
        if( A[i] < 0 )swap(Min, Max);
        Min = min( A[i], Min*A[i] );
        Max = max( A[i], Max*A[i] );
        Ans = max( Ans, Max);
    }
    return Ans;
}