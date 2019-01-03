int Solution::searchInsert(vector<int> &ar, int B) {
    int l = 0, r = ar.size()-1;
    int mid;
    while( l <= r ){
        mid = (l+r)/2;
        if( ar[mid] == B )return mid;
        if( ar[mid] > B )r = mid-1;
        else l = mid+1;
    }
    if( ar[mid] > B )return mid;
    return mid+1;
}
