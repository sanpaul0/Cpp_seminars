#include <iostream>
#include <string>

using namespace std;

void findelem(int *arr, int elem, int siz){
    for (int i=0; i<siz; i++){
        if (arr[i]== elem){
            cout << "arr["<<i<<"] -->" << elem;
            break;
        }
    }
}
void findelem(char *arr, char elem, int siz){
    for (int i=0; i<siz; i++){
        if (arr[i]== elem){
            cout << "arr["<<i<<"] -->" << elem;
            break;
        }
    }
}
void findelem(float *arr, float elem, int siz){
    for (int i=0; i<siz; i++){
        if (arr[i]== elem){
            cout << "arr["<<i<<"] -->" << elem;
            break;
        }
    }
}
int main(){
    std::string str;
    std::cin>>str; // char or int or float
    #define siz 7
    if (str == "int"){
        int arr[siz];
        int elem;
        cin >> elem;
        for (int i=0;i<siz;i++){
            cin >> arr[i];
        findelem(arr, elem, siz);
        }
    }
    else if (str == "float"){
        float arr[siz];
        float elem;
        cin >> elem;
        for (int i=0;i<siz;i++){
            cin >> arr[i];
        findelem(arr, elem, siz);
        }
    }
    else if (str == "char"){
        char arr[siz];
        char elem;
        cin >> elem;
        for (int i=0;i<siz;i++){
            cin >> arr[i];
        findelem(arr, elem, siz);
        }
    }
}