int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > v(n, vector<int> (m));
    v[0][0] = A[0][0];
    for( int j = 1; j < m; j++ ){
        v[0][j] = v[0][j-1] + A[0][j];
    }
    for( int i = 1; i < n; i++ ){
        v[i][0] = v[i-1][0] + A[i][0];
    }
    for( int i = 1; i < n; i++ ){
        for( int j = 1; j < m; j++ ){
            v[i][j] = min( v[i-1][j], v[i][j-1] ) + A[i][j];
        }
    }
    return v[n-1][m-1];
}
