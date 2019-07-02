vector<int> Solution::lszero(vector<int> &A) {
    long long p[A.size()];
    map<long long, int> idx;
    p[0] = A[0];
    idx[p[0]] = 0;
    idx[0]= -1;
    int ans = 0;
    int l = 0, r = 0;
    for( int i = 1; i < A.size(); i++ ){
        p[i] = A[i] + p[i-1];
        if( idx.count(p[i]) != 0 ){
            if( ans < i-idx[p[i]]+1 ){
                ans = i-idx[p[i]]+1;
                l = idx[p[i]], r = i;
            }
        }
        else{
            idx[p[i]] = i;
        }
    }
    vector<int> v;
    for( int i = l+1; i <= r; i++ ){
        v.push_back(A[i]);
    }
    if( v.size() == 0 ){
        for( auto it : A ){
            if( it == 0 )v.push_back(0);
        }
    }
    return v;
}
