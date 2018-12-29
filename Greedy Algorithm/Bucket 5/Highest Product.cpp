#define watch2(x, y) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define watch3(x, y, z) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cerr <<#x<<": "<<x<<endl;
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility>
#include <algorithm>
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<string>
#include <limits>
#include<climits>
#define endl "\n"
using namespace std;

int maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int two_sub = A[0] * A[1];
    two_sub *= A[n-1];
    int three_pos = A[n-1] * A[n-2] * A[n-3];
    return max(two_sub, three_pos);
}

int main(){
    vector<int> A;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        int num;
        cin >> num;
        A.push_back(num);
    }
    cout << maxp3(A);
}