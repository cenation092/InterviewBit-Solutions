int go_small(const vector<int> &A, int num ){
    int l = 0, r = A.size()-1;
    while( l <= r ){
        int mid = (l+r)/2;
        if( A[mid] < num )l = mid+1;
        else r = mid-1;
    }
    return l;
}

int go_large(const vector<int> &A, int num ){
    int l = 0, r = A.size()-1;
    while( l <= r ){
        int mid = (l+r)/2;
        if( A[mid] <= num )l = mid+1;
        else r = mid-1;
    }
    return (int)A.size()-l;
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size() + B.size();
    int l = INT_MIN, r = INT_MAX;
    if( n&1 ){
        while( l <= r ){
            int mid = (l+r)/2;
            int small = go_small(A, mid);
            small += go_small(B, mid);
            int large = go_large(A, mid);
            large += go_large(B, mid);
            if( small <= n/ 2 && large <= n/2 )return mid;
            if( small < large )l = mid+1;
            else r = mid-1;
        }
    }
    else{
        double a , b;
        l = INT_MIN, r = INT_MAX;
        while( l <= r ){
            int mid = (l+r)/2;
            int small = go_small(A, mid);
            small += go_small(B, mid);
            int large = go_large(A, mid);
            large += go_large(B, mid);
            if( small <= (n/2-1) && large <= n/2 ){
                a = mid;
                break;
            }
            if( small < large )l = mid+1;
            else r = mid-1;
        }
        l = INT_MIN, r = INT_MAX;
        while( l <= r ){
            int mid = (l+r)/2;
            int small = go_small(A, mid);
            small += go_small(B, mid);
            int large = go_large(A, mid);
            large += go_large(B, mid);
            if( small <= n/2 && large <= (n/2-1) ){
                b = mid;
                break;
            }
            if( small <= large )l = mid+1;
            else r = mid-1;
        }
        return (a+b)/2;
    }
}
