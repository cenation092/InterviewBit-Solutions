int Solution::solve(vector<int> &A) {
    long long p[A.size()];
    p[0] = A[0];
    set<long long> s;
    s.insert(p[0]);
    for( int i = 1; i < A.size(); i++ ){
        p[i] = A[i] + p[i-1];
        if( s.find(p[i]) != s.end() )return 1;
        s.insert(p[i]);
    }
    return 0;
}
