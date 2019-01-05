int Solution::titleToNumber(string A) {
    reverse(A.begin(), A.end() );
    int num = 0;
    for( int i = 0;i < A.size(); i++ ){
        num += pow(26,i)*(A[i]-'A'+1);
    }
    return num;
}
