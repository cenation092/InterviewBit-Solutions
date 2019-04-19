bool cmp( pair<int,int> x, pair<int,int> y ){
    if( x.first == y.first )return x.second < y.second;
    return x.first < y.first;
}

int Solution::maximumGap(const vector<int> &A) {
    priority_queue<int> idx;
    int n = A.size();
    vector<pair<int, int> > v(n);
    for( int i = 0; i < n; i++ ){
        v[i] = make_pair(A[i], i);
    }
    sort(v.begin(), v.end(), cmp );
    int ans = -1;
    for( int i = n-1; i >= 0; i-- ){
        int cur = v[i].second;
        idx.push(v[i].second);
        while( idx.top() < cur ){
            idx.pop();
        }
        ans = max( ans, idx.top()-cur);
    }
    return ans;
}
