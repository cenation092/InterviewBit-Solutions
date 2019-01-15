string Solution::longestCommonPrefix(vector<string> &A) {
    string ans = "";
    for( int i = 0; i < A.size()-1; i++ ){
        string s = "";
        for( int j = 0; min( A[i].size(), A[i+1].size()); j++ ){
            if( A[i][j] != A[i+1][j] )break;
            s += A[i][j];
        }
        if( ans.size() == 0 )ans = s;
        else{
            string z = "";
            for( int j = 0; j < min(ans.size(), s.size()); j++ ){
                if( ans[j] != s[j] )break;
                z += s[j];
            }   
            ans = z;
        }
    }
    if( A.size() == 1 )return A[0];
    if( A.size() > 1 ){
        int n = (int)A.size()-1;
        string s = "";
        for( int j = 0; j < min( ans.size(), A[n].size()); j++ ){
            if( A[n][j] != ans[j] )break;
            s += A[n][j];
        }
        ans = s;
    }
    return ans;
}
