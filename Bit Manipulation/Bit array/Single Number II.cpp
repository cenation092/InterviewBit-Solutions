// if ith bit appears thrice make it clear
int Solution::singleNumber(const vector<int> &A) {
    int one = 0, two = 0, clear;
    for( int i = 0; i < A.size(); i++ ){
        two = two | (A[i] & one);
        one = one ^ A[i];
        clear = one & two;
        one = one ^ clear;
        two = two ^ clear;
    }
    return one;
}
