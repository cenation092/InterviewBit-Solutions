int Solution::solve(vector<int> &A, int B, int C) {
    vector<int> cnt(10,0), have(10,0);
    string s = to_string(C);
    if( B > s.size() )return 0;
    int n = s.size()-1, ans = 0;
    for( int i = 0; i < A.size(); i++ )cnt[A[i]] = have[A[i]] = 1;
    for( int i = 1; i < 10; i++ )cnt[i] += cnt[i-1];
    if( B < s.size() && B != 1 )return pow(cnt[9],B-1)*(cnt[9]-cnt[0]);
    if( B < s.size() )return pow(cnt[9],B-1)*(cnt[9]);
    if( s.size() > 1 )ans = (cnt[s[0]-'0'-1]-cnt[0]) * pow(cnt[9],n);
    else ans = (cnt[s[0]-'0'-1]) * pow(cnt[9],n);
    for( int i = 1; i < s.size(); i++ ){
        if(!have[s[i-1]-'0'])break;
        n--;
        ans += cnt[s[i]-'0'-1] * pow(cnt[9],n);
    }
    return ans;
