string Solution::convertToTitle(int A) {
    string s = "";
    while( A > 0 ){
        A--;
        s += A % 26 + 'A';
        A /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
}
