int n;
int cnt = 0;

bool sq( int a, int b ){
    a += b;
    int root = sqrt(a);
    return (root*root == a);
}

void go( int i, vector<int> &A ){
    if( i > 1 && !sq(A[i-1], A[i-2]) )return;
    if( i == A.size() ){
        if( i > 1 )cnt++;
        return;
    }
    set<int> have;
    for( int j = i; j < n; j++ ){
        if( have.find(A[j]) != have.end() )continue;
        have.insert(A[j]);
        swap(A[i], A[j]);
        go(i+1, A);
        swap(A[i], A[j]);
    }
}

int Solution::solve(vector<int> &A) {
    cnt = 0;
    n = A.size();
    go(0, A);
    return cnt;
}
