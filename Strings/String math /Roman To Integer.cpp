int Solution::romanToInt(string A) {
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans = 0;
    for( int i = 0; i < A.size(); i++ ){
        if( i != (int)A.size() && m[A[i]] < m[A[i+1]] ){
            ans -= m[A[i]];
        }
        else{
            ans += m[A[i]];
        }
    }
    return ans;
}
