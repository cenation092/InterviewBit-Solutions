#define mp make_pair
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> v;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size()-1;
    v.push_back(A[n]+B[n]);
    set<pair<int,int> > idx;
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(mp(A[n-1]+B[n],mp(n-1,n)));
    pq.push(mp(A[n]+B[n-1],mp(n,n-1)));
    idx.insert(mp(n-1,n));
    idx.insert(mp(n,n-1));
    while( v.size() != A.size() ){
        pair<int, pair<int, int> > cur = pq.top();
        pq.pop();
        v.push_back(cur.first);
        int i = cur.second.first;
        int j = cur.second.second;
        if( i > 0 && idx.count(mp(i-1,j)) == 0 ){
            pq.push(mp(A[i-1]+B[j], mp(i-1,j)));
            idx.insert(mp(i-1,j));
        }
        if( j > 0 && idx.count(mp(i,j-1)) == 0){
            pq.push(mp(A[i]+B[j-1], mp(i,j-1)));
            idx.insert(mp(i,j-1));
        }
    }
    return v;
}
