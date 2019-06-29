vector<vector<int> > ans;

void go( int i, int j, vector<int> &A ){
    if( i == j ){
        ans.push_back(A);
        return;
    }
    for( int fix = i; fix <= j; fix++ ){
        swap(A[i], A[fix]);
        go(i+1, j, A);
        swap(A[i], A[fix]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    for( int i = 0; i < ans.size(); i++ )ans.clear();
    go(0, (int)A.size()-1, A);
    return ans;
}
