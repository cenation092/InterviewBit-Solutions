vector<int> pre( const string &s ){
    int n = s.size();
    vector<int> pi(n);
    for( int i = 1; i < n; i++ ){
        int j = pi[i-1];
        while( j > 0 && s[i] != s[j] ) j = pi[j-1]; // trim the current character
        if( s[i] == s[j] )j++;// if current match
        pi[i] = j;
    }
    return pi;
}

int Solution::strStr(const string l, const string s) {
    int j = 0;
    vector<int> idx;
    int n = l.size();
    int m = s.size();
    vector<int> pi = pre(s);
    for( int i = 0; i < n; i++ ){
        while( j > 0 && l[i] != s[j] ) j = pi[j-1]; // trim the current character
        if( l[i] == s[j] )j++; // if current match
        if( j == m )idx.push_back(i-m+1);
    }
    if( idx.empty() )return -1;
    return idx[0];
}
