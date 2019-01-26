int Solution::colorful(int A) {
    map<long long, int> have;
    vector<int> v;
    while( A > 0 ){
        v.push_back(A%10);
        A /= 10;
    }
    for( int i = 0; i < v.size(); i++ ){
        int p = 1;
        for( int j = i; j < v.size(); j++ ){
            p *= v[j];
            if( have.count(p) > 0 )return 0;
            have[p] = 1;
        }
    }
    return 1;
}
