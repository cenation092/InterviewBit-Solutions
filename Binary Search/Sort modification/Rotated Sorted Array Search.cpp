int Solution::search(const vector<int> &A, int num) {
    int n = A.size();
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l + r)/ 2;
        if(A[mid] == num) return mid;
        if( A[l] < A[r] ){
            if( num < A[mid] )r = mid-1;
            else l = mid+1;
        }
        else{
            if( A[l] < A[mid] ){
                if( num >= A[l] && num < A[mid] )r = mid-1;
                else l = mid+1;
            }
            else{
                if( A[mid] < num && num <= A[r] )l = mid+1;
                else r = mid-1;
            }
        }
    }
    return -1;
}
