vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size() + A.size()-1;
    vector<vector<int> > v(n);
    for( int i = 0; i < A.size(); i++ ){
        int x = 0, y = i;
        while( x >= 0 && y >= 0 && x < A.size() && y < A.size()){
            v[i].push_back(A[x][y]);
            x++, y--;
        }
    }
    for( int i = 1; i < A.size(); i++ ){
        int x = i, y = A.size()-1;
        while( x >= 0 && y >= 0 && x < A.size() && y < A.size() ){
            v[A.size()+i-1].push_back(A[x][y]);
            x++, y--;
        }
    }
    return v;
}
