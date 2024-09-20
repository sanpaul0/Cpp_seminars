#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1, str2;
    cin >> str2;
    cin >> str1;
    int l1, l2, count;
    l1 = str1.size();
    l2 = str2.size();
    for (int i=0; i<= l2-l1; i++){
        if (str2.substr(i, l1) == str1){
            count+=1;
        }
    }
    cout << count;
    return 0;
}