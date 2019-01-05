int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int> > v;
    for( int i = 0; i < A.size(); i++ ){
        v.push_back(make_pair(A[i], i));
    }
    sort( v.begin(),v.end() );
    priority_queue<pair<int,int> > pq;
    for( int i = 0; i < v.size(); i++ ){
        pq.push(make_pair(v[i].second, v[i].first));
    }
    int ans = -1;
    for( int i = 0; i < v.size(); i++ ){
        while( !pq.empty() && ( pq.top().first < v[i].second || pq.top().second < v[i].first)  ){
            pq.pop();
        }
        if( !pq.empty() ){
            ans = max( ans , pq.top().first - v[i].second );
        }
    }
    return ans;
}
