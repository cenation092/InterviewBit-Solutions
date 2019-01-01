#define watch2(x, y) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define watch3(x, y, z) cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cerr <<#x<<": "<<x<<endl;
#include <vector> 
#include<stack>
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

void setZeroes(vector<vector<int> > &ar) {
    int n = ar.size();
    int m = ar[0].size();
    int row[n], col[m];
    for( int i = 0; i < n; i++ )row[i] = 0;
    for( int i = 0; i < m; i++ )col[i] = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            if( ar[i][j] == 0 ){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for( int i = 0; i < n; i++ ){
        if( row[i] ){
            for( int j = 0; j < m; j++ ){
                ar[i][j] = 0;
            }
        }
    }
    for( int j = 0; j < m; j++ ){
        if( col[j] ){
            for( int i = 0; i < n; i++ ){
                ar[i][j] = 0;
            }
        }
    }
}               

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ar( n, vector<int>(m) );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            cin >> ar[i][j];
        }
    }
    setZeroes(ar);
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}