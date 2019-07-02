int Solution::longestConsecutive(const vector<int> &A) {
    set<int> s;
    for( auto it : A )s.insert(it);
    int ans = 0;
    int pre = INT_MIN;
    int l = 0;
    for( auto it : s ){
        if( pre == INT_MIN ){
            pre = it;
        }
        else{
            if( pre == it-1 ){
            }
            else{
                l = 0;
            }
            pre = it;
        }
        l++;
        ans = max( ans, l);
    }
    return ans;
}
