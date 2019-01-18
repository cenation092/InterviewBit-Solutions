vector<vector<int> > Solution::threeSum(vector<int> &A) {
    set<vector<int> > s;
    vector<vector<int> > V;
    if( A.size() == 0 )return V;
    sort( A.begin(), A.end() );
    for( int i = 0; i < A.size(); i++ ){
        int l = i+1, r = A.size()-1;
        while( l < r ){
            if( A[i] + A[l] + A[r] == 0 ){
                vector<int> v = {A[i], A[l], A[r]};
                sort(v.begin(), v.end());
                s.insert(v);
                l++, r--;
            }
            else if( A[l]+A[r]+A[i] < 0 )l++;
            else if( A[l]+A[r]+A[i] > 0 )r--;
        }
    }
    for( auto it : s ){
        V.push_back(it);
    }
    s.clear();
    return V;
}
