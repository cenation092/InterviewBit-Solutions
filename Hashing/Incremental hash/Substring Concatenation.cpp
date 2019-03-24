vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int l = 0;
    int n = B[0].size();
    map<string, int> Main;
    map<string, int> checker;
    for( auto it : B ){
        l += it.size();
        Main[it]++;
    }
    vector<int> ans;
    for( int i = 0; i < A.size(); i++ ){
        checker = Main;
        int flag = 1;
        for( int j = i, k = 0; k < l; ){
            if( j == A.size() )return ans;
            string s = "";
            for( int m = 0; m < n; m++, j++, k++ ){
                s += A[j];
            }
            if( checker.count(s) == 0 ){
                flag = 0;
                break;
            }
            checker[s]--;
            if( checker[s] == 0 )checker.erase(s);
        }
        if( flag )ans.push_back(i);
    }
    return ans;
}
