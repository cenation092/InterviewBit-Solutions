int Solution::isPalindrome(string A) {
    string s = "";
    for( int i = 0; i < A.size(); i++ ){
        if( A[i] >= 'A' && A[i] <= 'Z' ){
            A[i] = A[i] - 'A' + 'a';
            s += A[i];
        }
        else if( A[i] >= 'a' && A[i] <= 'z' ){
            s += A[i];
        }
        else if( A[i] >= '0' && A[i] <= '9' )s += A[i];
    }
    string r = s;
    reverse(r.begin(), r.end());
    return (r == s);
}
