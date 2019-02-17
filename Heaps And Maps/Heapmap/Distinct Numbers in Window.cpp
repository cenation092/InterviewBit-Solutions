vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> v;
    map<int,int> count;
    if( B > A.size() )return v;
    for( int i = 0; i < B; i++ ){
        count[A[i]]++;
    }
    v.push_back(count.size());
    for( int i = 0; i + B < A.size(); i++ ){
        count[A[i]]--;
        count[A[i+B]]++;
        if( count[A[i]] == 0 )count.erase(A[i]);
        v.push_back(count.size());
    }
    return v;
}
