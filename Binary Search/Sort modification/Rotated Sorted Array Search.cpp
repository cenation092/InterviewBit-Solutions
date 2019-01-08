int Solution::search(const vector<int> &A, int num) {
    int l = 0, r = A.size()-1;
    while( l <= r ){
        int mid = (l+r)/2;
        if( num == A[mid] )return mid;
        if( num > A[mid] && num <= A[r] ){
            l = mid+1;
        }
        else if( num < A[mid] && num >= A[r] ){
            r = mid-1;
        }
        else{
            if( A[mid] <= A[r] ){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    return -1;
}