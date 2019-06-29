int next( vector<int> &A ){
    int j = A.size()-1;
    while( j > 0 && A[j-1] >= A[j] )j--;
    if( j == 0 )return 0;
    reverse(A.begin()+j, A.end() );
    for( int i = j; i < A.size(); i++ ){
        if( A[i] > A[j-1] ){
            swap(A[i], A[j-1]);
            break;
        }
    }
    return 1;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    sort(A.begin(), A.end());
    ans.push_back(A);
    while(1){
        int is = next(A);
        if( !is )return ans;
        ans.push_back(A);
    }
}