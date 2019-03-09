struct one_node{
    int sum;
    int idx;
    void leaf(int sum, int idx){
        this->sum = sum;
        this->idx = idx;
    }
    void merge( one_node &n1, one_node &n2 ){
        sum = n1.sum + n2.sum;
        idx = max( n1.idx, n2.idx);
    }
};

one_node tree[1000000];

void build( int node, int l, int r ){
    // leaf
    if( l == r ){
        tree[node].leaf(1, l);
        return;
    }
    int mid = (l+r)/2;
    int left_node = node*2;
    int right_node = node*2+1;
    build(left_node, l, mid);
    build(right_node, mid+1, r);
    tree[node].merge(tree[left_node], tree[right_node]);
}

void update( int node, int l, int r, int idx ){
    //position used
    if( l == r ){
        tree[node].leaf(0, -1);
        return;
    }
    int mid = (l+r)/2;
    int left_node = node*2;
    int right_node = node*2+1;
    if( idx <= mid )update(left_node, l, mid, idx);
    else update(right_node, mid+1, r, idx);
    tree[node].merge(tree[left_node], tree[right_node]);
}

int query( int node, int l, int r, int sum ){
    // required position
    if( tree[node].sum == sum ){
        return tree[node].idx;
    }
    int mid = (l+r)/2;
    int left_node = node*2;
    int right_node = node*2+1;
    if( tree[left_node].sum >= sum ){ // exist in left
        int sum_left = sum;
        return query(left_node, l, mid, sum_left);
    }
    else{ // exist in right
        int sum_left = sum - tree[left_node].sum;
        return query(right_node, mid+1, r, sum_left);
    }   
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    build(1, 0, n-1);
    vector<pair<int,int> > Ar;
    for( int i = 0; i < A.size(); i++ ){
        Ar.push_back(make_pair(A[i], B[i]));
    }    
    sort(Ar.begin(), Ar.end());
    vector<int> ans(n);
    for( int i = 0; i < n; i++ ){
        int sum = Ar[i].second + 1;
        int idx = query(1, 0, n-1, sum);
        update(1, 0, n-1, idx);
        ans[idx] = Ar[i].first;
    }
    return ans;
}
