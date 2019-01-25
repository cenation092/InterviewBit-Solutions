vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> B;
    for( int i = 0; i < A.size(); i++ ){
        while( !s.empty() && s.top() >= A[i] )s.pop();
        if( s.empty() )B.push_back(-1);
        else B.push_back(s.top());
        s.push(A[i]);
    }
    return B;
}
