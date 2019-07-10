int Solution::longestValidParentheses(string A) {
    stack<int> s;
    s.push(-1);
    int Ans = 0;
    for( int i = 0; i < A.size(); i++ ){
        if( A[i] == '{' || A[i] == '[' || A[i] == '(' || A[i] == '<' ){
            //cout << "push -> " << A[i] << endl;
            s.push(i);
        }
        else if( s.top() == -1 ){
            s.push(i);
        }
        else if( A[i] == '}' ){
            if( A[s.top()] != '{' )s.push(i);
            else{
                s.pop();
                //cout << i << " | " << s.top() << endl;
                Ans = max( Ans, i-s.top());
            }
        }
        else if( A[i] == ']' ){
            if( A[s.top()] != '[' )s.push(i);
            else{
                s.pop();
                //cout << i << " | " << s.top() << endl;
                Ans = max( Ans, i-s.top());
            }
        }
        else if( A[i] == ')' ){
            if( A[s.top()] != '(' )s.push(i);
            else{
                s.pop();
                //cout << i << " | " << s.top() << endl;
                Ans = max( Ans, i-s.top());
            }
        }
        else if( A[i] == '>' ){
            if( A[s.top()] != '<' )s.push(i);
            else{
                s.pop();
                //cout << i << " | " << s.top() << endl;
                Ans = max( Ans, i-s.top());
            }
        }
    }
    return Ans;
}

