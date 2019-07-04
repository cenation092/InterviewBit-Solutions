struct x{
    int num, idx, inv;
};

void merge(int a, int b, int c, int d, vector<x> &A ){
    vector<x> L, R;
    for( int i = a; i <= b; i++ ){
        L.push_back(A[i]);
    }
    for( int i = c; i <= d; i++ ){
        R.push_back(A[i]);
    }
    int left = d-c+1;
    int i = L.size()-1, j = R.size()-1;
    vector<x> M;
    while( i >= 0 && j >= 0 ){
        if( L[i].num > R[j].num ){
            L[i].inv += left;
            i--;
        }
        else{
            j--;
            left--;
        }
    }
    i = 0, j = 0;
    while( i < L.size() && j < R.size() ){
        if( L[i].num < R[j].num ){
            M.push_back(L[i]);
            i++;
        }
        else{
            M.push_back(R[j]);
            j++;
        }
    }
    while( i < L.size() ){
        M.push_back(L[i]);
        i++;
    }
    while( j < R.size() ){
        M.push_back(R[j]);
        j++;
    }
    for( int l = 0, r = a; r <= d; r++, l++ ){
        A[r] = M[l];
    }
}
void go( int l, int r, vector<x> &A ){
    if( l >= r )return;
    int mid = (l+r)/2;
    go(l, mid, A);
    go(mid+1, r, A);
    merge(l, mid, mid+1, r, A);
}

vector<int> Solution::solve(vector<int> &A) {
    vector<x> ar((int)A.size());
    for( int i = 0; i < A.size(); i++ ){
        ar[i].num = A[i];
        ar[i].idx = i;
        ar[i].inv = 0;
    }
    go(0, A.size()-1, ar);
    vector<int> v((int)A.size());
    for( auto it : ar ){
        v[it.idx] = it.inv;
    }
    return v;
}
