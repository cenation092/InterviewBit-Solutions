int Solution::largestRectangleArea(vector<int> &A) {
    long long ans = 0;
    A.push_back(0);
    stack<int> s;
    s.push(0);
    for( int i = 1; i < A.size(); i++ ){
        while( !s.empty() && A[i] < A[s.top()] ){
            int num = A[s.top()]; s.pop();
            int left = 0;
            if( !s.empty())left = s.top()+1;
            int right = i;
            ans = max( ans, (right-left)*1LL*num);
        }
        s.push(i);
    }
    return ans;
}
