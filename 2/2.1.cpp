#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int num;
    cin >> num;
    int div;
    div = num/2;
    while (div >= sqrt(num))
    {
        if (num % div == 0)
        {
            cout << div;
            return 0;
        } else{
            --div;
        }
    }
    if (div < sqrt(num)){
        cout << "Simple number";
    }
    cout<<1;
    return 0;
}