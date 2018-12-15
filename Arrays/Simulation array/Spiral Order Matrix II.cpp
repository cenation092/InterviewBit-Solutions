vector<vector<int> > Solution::generateMatrix(int A) {
    int x = 1;
    int n = A;
    vector< vector<int> > ar(A, vector<int>(A) );
    int left = 0, right, up = 0, down = 0;
    right = 1;
    int l = 0, r = A-1;
    int up_row = 0, right_col = n-1;
    int down_row = n-1, left_col = 0;
    while(x <= A*A ){
        if( right ){
            for( int i = l; i <= r; i++ ){
                ar[up_row][i] = x;
                x++;
            }
            up_row++;
            l = up_row, r = down_row;
            right = 0, down = 1;
        }
        else if( down ){
            for( int i = l; i <= r; i++ ){
                ar[i][right_col] = x;
                x++;
            }
            right_col--;
            down = 0, left = 1;
            l = right_col, r = left_col;
        }
        else if( left ){
            for( int i = l; i >= r; i-- ){
                ar[down_row][i] = x;
                x++;
            }
            down_row--;
            left = 0, up = 1;
            l = down_row, r = up_row;
        }
        else if( up ){
            for( int i = l; i >= r; i-- ){
                ar[i][left_col] = x;
                x++;
            }
            up = 0, right = 1;
            left_col++;
            l = left_col, r = right_col;
        }
    }
    return ar;
}
