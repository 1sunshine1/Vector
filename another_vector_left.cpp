#include <iostream>
using namespace std;

void reserve(int *num, int i, int j) {
    int head = i, tail = j;
    while (head < tail) {
        num[head] ^= num[tail];
        num[tail] ^= num[head];
        num[head] ^= num[tail];
        head++;
        tail--;
    }
    return ;
}

int num[10000];

int main() {
    int n, m, flag = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    reserve(num, 0, m - 1);
    reserve(num, m, n - 1);
    reserve(num, 0, n - 1);
    cout << num[0];
    for (int i = 1; i < n; i++) {
        cout << " " << num[i]  ;
    }
    return 0;
}
