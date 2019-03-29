// find the largest suffix of array which is in decreasing order
// then find the immediate largest number of the number which is at before the suffix segment
// then swap them


void Solution::nextPermutation(vector<int> &ar) {
    int n = ar.size();
    int mid = n-1;
    for( int i = n-1; i > 0; i-- ){
        if( ar[i] > ar[i-1] )break;
        mid--;
    }
    reverse(ar.begin()+mid, ar.end());
    if( mid != 0 ){
        for( int i = mid; i < n; i++ ){
            if( ar[mid-1] < ar[i] ){
                swap(ar[i], ar[mid-1]);
                break;
            }
        }
    }
}

