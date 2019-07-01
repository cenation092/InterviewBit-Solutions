int to_bin( string s ){
    int num = 0;
    int two = 1;
    for( int i = s.size()-1; i >= 0; i-- ){
        num += (s[i]-'0')*two;
        two *= 2;
    }
    return num;
}

vector<int> Solution::grayCode(int A) {
    vector<int> v;
    if( A == 0 )return v;
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for( int i = 2; i <= A; i++ ){
        vector<string> temp;
        for( int i = 0; i < ans.size(); i++ ){
            string s = ans[i];
            reverse(s.begin(), s.end());
            s = '0' + s;
            temp.push_back(s);
        }
        for( int i = ans.size()-1; i >= 0; i-- ){
            string s = ans[i];
            reverse(s.begin(), s.end());
            s = '1' + s;
            temp.push_back(s);
        }
        ans = temp;
    }
    for( auto it : ans ){
        while( it.size() < A )it = '0' + it;
        v.push_back(to_bin(it));
    }
    return v;
}
