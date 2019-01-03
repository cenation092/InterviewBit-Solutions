int Solution::searchMatrix(vector<vector<int> > &ar, int B) {
    int n = ar.size();
    for( int i = 0; i < n; i++ ){
        int l = 0, r = ar[i].size()-1;
        while( l <= r ){
            int mid = (l+r)/2;
            if( ar[i][mid] == B )return 1;
            if( ar[i][mid] < B )l = mid+1;
            else r = mid-1;
        }
    }
    return 0;
}
