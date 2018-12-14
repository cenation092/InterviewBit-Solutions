vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long A_sum = (n * (n+1)) / 2;
    long long A_sq_sum = (n * (n+1) * (2*n + 1)) / 6;
    long long sum = 0, sq_sum = 0;
    for( int i = 0; i < n; i++ ){
        sum += A[i];
        sq_sum += A[i] * 1LL * A[i];
    }
    long long S = ( A_sq_sum - sq_sum ) / (A_sum - sum );
    int y = S + A_sum - sum;
    y /= 2;
    int x = y - A_sum + sum;
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    return v;
}
