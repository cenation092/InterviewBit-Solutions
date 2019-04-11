int Solution::braces(string A) {
    stack<int> s;
    int open = 0;
    for( auto it : A ){
        if( it == '(' ){
            s.push(1);
        }
        else if( it == ')' ){
            if( s.top() == 1 )return 1;
            while(s.top() == 0 )s.pop();
            s.pop();
        }
        else if( it > 'z' || it < 'a'){
            s.push(0);
        }
    } 
    return 0;
}
