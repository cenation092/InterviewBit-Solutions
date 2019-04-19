void Solution::rotate(vector<vector<int> > &A) {
    int x = 0, y = 0;
    int n = A.size();
    while( x < n && y < n ){
        int i = x+1, j = y+1;
        while( i < n && j < n ){
            swap( A[x][j], A[i][y] );
            i++, j++;
        }
        x++;
        y++;
    }
    int l = 0, r = n-1;
    while( l < r ){
        int i = 0;
        while( i < n ){
            swap(A[i][l], A[i][r]);
            i++;
        }
        l++;
        r--;
    }
}
