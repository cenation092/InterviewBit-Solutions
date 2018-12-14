int Solution::maxArr(vector<int> &A) {
    vector<int> n, p;
    int l = A.size() - 1;
    for( int i = 0; i < A.size(); i++ ){
        n.push_back(A[i]-(i+1));
        p.push_back(A[i]+(i+1));
    }
    int ans = -INT_MAX;
    sort( n.begin(), n.end() );
    sort( p.begin(), p.end() );
    ans = abs(p[l] - p[0]);
    ans = max( ans, abs(n[l] - n[0]));
    return ans;
}
