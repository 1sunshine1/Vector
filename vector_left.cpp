#include <iostream>
using namespace std;

int num[10000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = m; i < n; i++) {
        if (i == 0) {
            cout << num[i];
            return 0;
        }
        cout << num[i] << " ";
    }
    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
            cout << num[i];
            break;
        }
        cout << num[i] << " " ;
    }
    return 0;
}
