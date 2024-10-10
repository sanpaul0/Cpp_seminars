#include <iostream>
#define n 5

using namespace std;

struct nvect
{
    float val[n];
};

struct nvect summ(struct nvect v1, struct nvect v2){
    struct nvect ans;
    for (int i=0; i<n; i++){
        ans.val[i] = v1.val[i]+v2.val[i];
    }
    return ans;
}

float scprod(struct nvect v1, struct nvect v2){
    float ans;
    ans = 0;
    for (int i=0; i<n; i++){
        ans += v1.val[i]*v2.val[i];
    }
    return ans;
}

struct nvect prod(struct nvect v1, float numb){
    struct nvect ans;
    for (int i=0; i<n; i++){
        ans.val[i] = v1.val[i]*numb;
    }
    return ans;
}

struct nvect change(struct nvect v1){
    float a;
    for (int i = 0; i<n; i++){
        cin >> a;
        v1.val[i] = a;
    }
    return v1;
}

float printnv (struct nvect v){
    cout << "(";
    for (int i=0; i<n; i++){
        cout << v.val[i];
        if (i<n-1){
            cout << ", ";
        }
    }
    cout << ")";
    return 0;
}



int main(){
    nvect v = {1, 2, 3, 4, 5};
    nvect w = {6,7,8,9,10};
    cout << scprod(v, w);
    cout << scprod(prod(v, 100), summ(v, w));
    printnv(summ(v, w));
}
}

