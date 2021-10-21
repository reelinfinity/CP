#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int max,min;
};

node maxMin(vector<int> &v,int p,int q){
    node result;
    if(p == q){
        result.max=v[p];
        result.min=v[p];
        return result;
    }
    else{
        int mid=(p+q)/2;
        node r1=maxMin(v,p,mid);
        node r2=maxMin(v,mid+1,q);
        if(r1.max>r2.max){
            result.max=r1.max;
        }
        else{
            result.max=r2.max;
        }
        if(r1.min<r2.min){
            result.min=r1.min;
        }
        else{
            result.min=r2.min;
        }
        return result;
    }
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
    node res=maxMin(v,0,n-1);
    cout << res.max << " " << res.min;
    return 0;
}
