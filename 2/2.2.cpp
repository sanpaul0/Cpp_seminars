#include <iostream>

using namespace std;

int main() {
    while (true){

    
        int fnum, snum, res;
        cin >> fnum;
        cin >> snum;
        if (fnum > 0 && snum > 0){
            res = fnum + snum;
            cout << res;
        } else if (fnum < 0 && snum < 0){
            continue; 
        } else {
            break;
        }
    }
    return 0;
}