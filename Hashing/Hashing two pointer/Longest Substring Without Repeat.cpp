int Solution::lengthOfLongestSubstring(string A) {
    int ans = 0;
    int l = 0, r = 0;
    set<char> have;
    while( r < A.size() ){
        while( have.find(A[r]) != have.end() ){
            have.erase(A[l++]);
        }
        have.insert(A[r++]);
        ans = max( ans, r-l );
    }
    return ans;
}
