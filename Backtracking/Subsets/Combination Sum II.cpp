set<vector<int> > ans;
int vis[100001];

void go(int i, int left, vector<int> &A ){
    if( i == A.size() ){
        if( left == 0 ){
            vector<int> v;
            for( int j = 0; j < i; j++ ){
                if( vis[j] )v.push_back(A[j]);
            }
            ans.insert(v);
        }
        return;
    }
    vis[i] = 1;
    go(i+1, left-A[i], A);
    vis[i] = 0;
    go(i+1, left, A);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    ans.clear();
    memset(vis, 0, sizeof(vis));
    go(0, B, A);
    vector<vector<int> > v;
    for( auto it : ans ){
        v.push_back(it);
    }
    return v;
}
