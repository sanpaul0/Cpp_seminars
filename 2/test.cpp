#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int siz;
    cin >> siz;
    int m[siz];
    int ans = 0;
    cout << m[0] << m[1] << m[2] << m[3] << "\n";
    for (int i=0; i< siz; i++) {
        m[i] = i*i;
        cout << m[i] << "\n";
        ans+=m[i];
    }
    cout << ans << "\n";
    return 0;
}