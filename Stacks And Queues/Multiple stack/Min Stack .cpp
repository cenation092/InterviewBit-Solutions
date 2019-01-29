stack<int> s, m;
MinStack::MinStack() {
    while( !s.empty())s.pop();
    while( !m.empty())m.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if( m.empty() )m.push(x);
    else{
        if( x < m.top() ) m.push(x);
        else m.push(m.top());
    }
}

void MinStack::pop() {
    if( s.empty() )return;
    s.pop(); m.pop();
}

int MinStack::top() {
    if( s.empty() )return -1;
    return s.top();
}

int MinStack::getMin() {
    if( m.empty() )return -1;
    return m.top();
}

