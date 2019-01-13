void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> x;
    int i = 0, j = 0;
    while( i < A.size() && j < B.size() ){
        if( A[i] < B[j] ){
            x.push_back(A[i++]);
        }
        else{
            x.push_back(B[j++]);
        }
    }
    while( i < A.size() )x.push_back(A[i++]);
    while( j < B.size() )x.push_back(B[j++]);
    A = x;
}
