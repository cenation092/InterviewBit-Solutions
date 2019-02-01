int Max;
int Time = 1;
map<int,int> have;
map<int,int> has_del;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

void removeExtras(){
    while(!pq.empty()){
        int lru = pq.top().second;
        if( has_del.count(lru) > 0 && has_del[lru] > 0 ){
            has_del[lru]--;
            pq.pop();
        }
        else break;
    }
}

LRUCache::LRUCache(int capacity) {
    while( !pq.empty() )pq.pop();
    have.clear();
    has_del.clear();
    Max = capacity;
}

int LRUCache::get(int key) {
    removeExtras();
    if( have.count(key) ){
        if( has_del.count(key) )has_del[key]++;
        else has_del[key] = 1;
        pq.push(make_pair(Time++, key));
        return have[key];
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    removeExtras();
    if( have.count(key) ) has_del[key]++;
    else if( have.size() == Max ){
        int lru = pq.top().second;
        pq.pop();
        have.erase(lru);
        has_del[lru] = max(0, has_del[lru]-1);
    }
    pq.push(make_pair(Time++, key));
    have[key] = value;
}
