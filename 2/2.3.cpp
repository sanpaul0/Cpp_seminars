#include <iostream>

using namespace std;

int main(){
    int siz;
    cin >> siz;
    int m[siz];
    int ans = 0;
    for (int i=0; i< siz; i++) {
        m[i] = i*i;
        ans+=m[i];
    }
    cout << ans << "\n";
    return 0;
}