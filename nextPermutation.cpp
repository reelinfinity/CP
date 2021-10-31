#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> &v,auto i,auto j){
    auto s=i;
    auto e=j;
    while(s<e){
        swap(s,e);
        s++;e--;
    }
}

void nextPermutation(vector<int> &v,int n){
    auto it = v.end()-1;
    while(*it<*(it-1)){
        it--;
    }
    auto it1=it-1;
    auto it2=it,it3;
    int min=2147483647,tmp;
    while(it2!=v.end()){
        tmp=abs(*it2-*it1);
        if(tmp<min){
            min=tmp;
            it3=it2;
        }
        it2++;
    }
    swap(it3,it1);
    reverse(v,it,v.end()-1);
}

int main()
{
    int n,x,tmp;
    cin >> n;
    vector<int> v;
    tmp=n;
    while(tmp--){
        cin >> x;
        v.push_back(x);
    }
    nextPermutation(v,n);
    return 0;
}
