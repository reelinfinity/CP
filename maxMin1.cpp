#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int max,min;
};

node maxMin(vector<int> &v,int n){
    node res;
    int i;
    if(n & 1){
        res.max=v[0];
        res.min=v[0];
        i=1;
    }
    else{
        if(v[0] > v[1]){
            res.max=v[0];
            res.min=v[1];
        }
        else{
            res.max=v[1];
            res.min=v[0];
        }
        i=2;
    }
    while(i<n-1){
        if(v[i] > v[i+1]){
            if(res.max < v[i]) res.max=v[i];
            if(res.min > v[i+1]) res.min=v[i+1];
        }
        else{
            if(res.max < v[i+1]) res.max=v[i+1];
            if(res.min > v[i]) res.min=v[i];
        }
        i+=2;
    }
    return res;
}

int main()
{
    int n=0,x=0;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }
    node res=maxMin(v,n);
    cout << res.max << " " << res.min;
    return 0;
}
