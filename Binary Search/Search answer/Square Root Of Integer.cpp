int Solution::sqrt(int A) {
    long long l = 0, r = A;
    long long ans;
    while( l <= r ){
        long long mid = (l+r)/2;
        if( mid*mid == A*1LL )return mid;
        if( mid*mid > A*1LL )r = mid-1;
        else{
            ans = mid;
            l = mid+1;
        } 
    }
    return ans;
}
