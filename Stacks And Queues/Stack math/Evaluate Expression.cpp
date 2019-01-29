int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    for( auto it : A ){
        if( it.size() > 1 || ( it[0] >= '0' && it[0] <= '9') ){
            int num = 0;
            int sign = (it[0] == '-' );
            for( int i = (it[0] == '-')?1:0; i < it.size(); i++ ){
                num = num * 10 + (it[i]-'0');
            }
            if( sign )num = -num;
            s.push(num);
        }
        else{
            int n2 = s.top();s.pop();
            int n1 = s.top();s.pop();
            if( it == "+" )s.push(n1+n2);
            else if( it == "*" )s.push(n1*n2);
            else if( it == "-" )s.push(n1-n2);
            else s.push(n1/n2);
        }
    }
    return s.top();
}
