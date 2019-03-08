struct node{
    int fre;
    node *ar[26];
    node(){
        fre = 0;
        for( int i = 0; i < 26; i++ ){
            ar[i] = NULL;
        }
    }
};

void add(node *root, string s, int idx ){
    if( idx == s.size() )return;
    if( root->ar[s[idx]-'a'] == NULL ){
        root->ar[s[idx]-'a'] = new node();
    }
    root->ar[s[idx]-'a']->fre++;
    add(root->ar[s[idx]-'a'], s, idx+1);
}

int find(node *root, string s, int idx ){
    if( root->ar[s[idx]-'a']->fre == 1 )return idx;
    if( root->ar[s[idx]-'a'] != NULL ){
        return find(root->ar[s[idx]-'a'], s, idx+1);
    }
    return -1;
}

vector<string> Solution::prefix(vector<string> &ar) {
    int n = ar.size();
    vector<string> v;
    node *root = new node();
    for( int i = 0; i < n; i++ ){
        add(root, ar[i], 0);
    }
    for( int i = 0; i < n; i++ ){
        int idx = find(root, ar[i], 0);
        string s = "";
        for( auto it : ar[i] ){
            if( idx < 0 )break;
            s += it;
            idx--;
        }
        v.push_back(s);
    }
    return v;
}
