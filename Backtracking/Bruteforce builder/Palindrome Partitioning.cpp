bool pal( string &a ){
    string b = a;
    reverse(b.begin(), b.end() );
    return (a == b);
}

void go( int i, string &A, vector<string> &v, vector<vector<string> > &ans ){
    if( i == A.size() ){
        ans.push_back(v);
        return;
    }
    string z = "";
    for( int j = i; j < A.size(); j++ ){
        z += A[j];
        if( pal(z) ){
            v.push_back(z);
            go(j+1, A, v, ans);
            v.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;
    vector<string> s;
    go(0, A, s, ans);
    return ans;
}
