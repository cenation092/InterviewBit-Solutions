int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0;
    for( int i = 0; i < A.size(); i++ ){
        sum += A[i];
    }
    int l = 0;
    int temp = 0;
    for( int i = 0; i < A.size(); i++ ){
        temp += A[i];
        if( temp > sum )sum = temp;
        while( temp < 0 && l <= i){
            if( temp > sum )sum = temp;
            temp -= A[l++];
        }
    }
    return sum;
}
