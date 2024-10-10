#include <iostream>
#define n 5

using namespace std;

struct nvect
{
    float val[n];

};
int main(){
    struct nvect v = {1, 2, 3, 4, 5};
    struct nvect w = {6,7,8,9,10};
    cout << v.val << w.val;
}

