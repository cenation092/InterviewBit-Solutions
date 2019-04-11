void Solution::reverseWords(string &A) {
    reverse(A.begin(), A.end());
    string s = "";
    int i = 0;
    while( A[i] == ' ')i++;
    string temp = "";
    while( i < A.size() && A[i] != ' ' ){
        temp += A[i];
        i++;
    }
    reverse(temp.begin(), temp.end());
    s += temp;
    while( i < A.size() ){
        temp = "";
        while( i < A.size() && A[i] != ' ' ){
            temp += A[i];
            i++;
        }
        if( temp.size() > 0 ){
            s += ' ';
            reverse(temp.begin(), temp.end());
            s += temp;
        }
        i++;
    }
    A = s;
}
