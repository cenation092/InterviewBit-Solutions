int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if( A.size() < 3 )return (int)A.size();
    map<pair<int,int>,int> point;
    int ans = 0;
    for( int i = 0; i < A.size(); i++ ){
        int x1 = A[i], y1 = B[i];
        int over = 0;
        map<pair<int,int>, int > same;
        for( int j = 0; j < A.size(); j++ ){
            int x2 = A[j], y2 = B[j];
            int top = y2-y1;
            int bot = x2-x1;
            if( top == 0 && bot == 0 ){
                over++;
                continue;
            }
            int neg = (top < 0);
            neg += (bot < 0);
            neg %= 2;
            top = abs(top);
            bot = abs(bot);
            int gcd = __gcd(top, bot);
            if( gcd != 0 ){
                top /= gcd;
                bot /= gcd;
            }
            if( neg )top *= -1;
            same[make_pair(top, bot)]++;
        }
        for( auto it : same ){
            int cnt = it.second;
            ans = max( ans, cnt+over);
        }
    }
    return ans;
}
