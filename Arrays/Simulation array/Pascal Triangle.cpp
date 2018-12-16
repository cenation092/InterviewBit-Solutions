vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ar(A, vector<int>(A,0) );
    for( int i = 0; i < A; i++ ){
        ar[i][0] = 1;
    }
    for( int i = 1; i < A; i++ ){
        for( int j = 1; j < A; j++ ){
            ar[i][j] = ar[i-1][j] + ar[i-1][j-1];
        }
    }
    for( int i = 0; i < A; i++ ){
        int n = A-i-1;
        while(n){
            ar[i].pop_back();
            n--;
        }
    }
    return ar;
}
