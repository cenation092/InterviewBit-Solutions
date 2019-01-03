vector<int> Solution::searchRange(const vector<int> &ar, int B) {
    int l = 0, r = ar.size()-1;
    int L = -1, R = -1;
    while( l <= r ){
        int mid = (l+r)/2;
        if( ar[mid] == B ){
            r = mid-1;
            L = mid;
        }
        else if( ar[mid] < B ){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    l = 0, r = ar.size()-1;
    while( l <= r ){
        int mid = (l+r)/2;
        if( ar[mid] == B ){
            l = mid + 1;
            R = mid;
        }
        else if( ar[mid] < B ){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    vector<int> v = {L, R};
    return v;
}
