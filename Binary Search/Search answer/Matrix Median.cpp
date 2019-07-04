int Solution::findMedian(vector<vector<int> > &A) {
    int l = 0, r = INT_MAX;
    int n = A.size();
    int m = A[0].size();
    n = n*m;
    while( l <= r ){
        int mid = (l+r)/2;
        int small = 0, large = 0;
        for( int i = 0; i < A.size(); i++ ){
            int L = 0, R = A[i].size()-1;
            while( L <= R ){
                int Mid = (L+R) / 2;
                if( A[i][Mid] < mid )L = Mid+1;
                else R = Mid-1;
            }
            small += L;
            L = 0, R = A[i].size()-1;
            while( L <= R ){
                int Mid = (L+R)/2;
                if( A[i][Mid] <= mid )L = Mid+1;
                else R = Mid-1;
            }
            large += (int)(A[i].size()) - L;
        }
        if( small <= n/2 && large <= n/2 )return mid;
        if( small < large )l = mid+1;
        else r = mid-1;
    }
}
