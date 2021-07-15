#include <iostream>

using namespace std;
signed main() {
    int mat[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> mat[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    int qt = 0;
    int x, y;
    x = a;
    y = b;
    x--;
    while (x >= 0) {
        if (mat[x][y] == 2) {
            qt++;
            break;
        } else if (mat[x][y] == 1) {
            break;
        }
        x--;
    }
    x = a;
    y = b;
    x++;
    while (x < 8) {
        if (mat[x][y] == 2) {
            qt++;
            break;
        } else if (mat[x][y] == 1) {
            break;
        }
        x++;
    }
    x = a;
    y = b;
    y--;
    while (y >= 0) {
        if (mat[x][y] == 2) {
            qt++;
            break;
        } else if (mat[x][y] == 1) {
            break;
        }
        y--;
    }
    x = a;
    y = b;
    y++;
    while (y < 8) {
        if (mat[x][y] == 2) {
            qt++;
            break;
        } else if (mat[x][y] == 1) {
            break;
        }
        y++;
    }
    cout << qt << endl;
}
