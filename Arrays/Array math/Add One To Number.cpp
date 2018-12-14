vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    int carry = 1;
    for( int i = 0; i < n; i++ ){
        ans.push_back( (A[i]+carry) % 10 );
        carry = (A[i]+carry) / 10;
    }
    if( carry > 0 )ans.push_back(carry);
    reverse( ans.begin(), ans.end() );
    return ans;
}
