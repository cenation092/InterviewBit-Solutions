bool cmp( string a, string b ){
    return (a+b) > (b+a);
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> ar;
    for( auto it : A ){
        ar.push_back(to_string(it));
    }
    sort(ar.begin(), ar.end(), cmp);
    string s = "";
    for( auto it : ar ){
        s += it;
    }
    string ans = "";
    int i = 0;
    while( s[i] == '0' && i < s.size()-1 )i++;
    for( ; i < s.size(); i++ ){
        ans += s[i];
    }
    return ans;
}
