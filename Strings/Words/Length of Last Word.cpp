int Solution::lengthOfLastWord(const string A) {
    int n = A.size();
    int l = 0;
    int i = n-1;
    while( i >= 0 && A[i] == ' ' )i--;
    for( ; i >= 0; i-- ){
        if( A[i] == ' ')break;
        l++;
    }
    return l;
}
