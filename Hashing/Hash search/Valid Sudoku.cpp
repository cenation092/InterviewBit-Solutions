int Solution::isValidSudoku(const vector<string> &A) {
    for( int i = 0; i < A.size(); i++ ){
        set<char> s;
        for( int j = 0; j < A[i].size(); j++ ){
            if( s.find( A[i][j]) != s.end() )return 0;
            if( A[i][j] != '.' )s.insert(A[i][j]);
        }
    }
    for( int j = 0; j < A[0].size(); j++ ){
        set<char> s;
        for( int i = 0; i < A.size(); i++ ){
            if( s.find( A[i][j]) != s.end() )return 0;
            if( A[i][j] != '.' )s.insert(A[i][j]);
        }
    }
    int n = sqrt((int)A.size());
    for( int k = 0; k < A.size(); k += n ){
        for( int l = 0; l < A.size(); l += n ){
            set<char> s;
            for( int i = k; i < k+n; i++ ){
                for( int j = l; j < l+n; j++ ){
                    if( s.find( A[i][j]) != s.end() )return 0;
                    if( A[i][j] != '.' )s.insert(A[i][j]);
                }
            }   
        }
    }
    return 1;
}
