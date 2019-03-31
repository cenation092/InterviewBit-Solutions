double Get( const vector<int> &a, const vector<int> &b, int l1, int l2, int l ){
    if( l1 >= a.size() )return b[l2+l-1];
    if( l2 >= b.size() )return a[l1+l-1];
    if( l == 1 )return min(a[l1], b[l2]);
    int ex = l/2;
    int A = INT_MAX;
    int B = INT_MAX;
    if( l1+ex <= a.size() )A = a[l1+ex-1];
    if( l2+ex <= b.size() )B = b[l2+ex-1];
    if( A < B ){
        return Get(a, b, l1+ex, l2, l-ex);
    }
    return Get(a, b, l1, l2+ex, l-ex);
}

double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {
    int l = a.size() + b.size();
    if( l&1 ){
        return Get(a, b, 0, 0, l/2+1);
    }
    return (Get(a, b, 0, 0, l/2) + Get(a, b, 0, 0, l/2+1)) / 2;
}
