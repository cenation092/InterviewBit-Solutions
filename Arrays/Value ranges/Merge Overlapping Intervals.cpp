/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp( Interval a, Interval b ){
    if( a.start == b.start ){
        return a.end < b.end;
    }
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort( A.begin(), A.end(), cmp);
    int i = 0;
    Interval cur;
    vector<Interval> v;
    for( ; i < A.size(); ){
        cur.start = A[i].start;
        cur.end = A[i].end;
        while( i < A.size() && A[i].start <= cur.end ){
            cur.end = max( cur.end, A[i].end);
            i++;
        }
        v.push_back(cur);
    }
    return v;
}
