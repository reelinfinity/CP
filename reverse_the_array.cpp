#include <iostream>
//#include <algorithm>
using namespace std;

void reverse(int* a,int n){
    int start=0;
    int end=n-1;
    while(start<end){
        swap(a[start++],a[end--]);
    }
}

int main()
{
    int n;
    cin >> n;
    int *a= new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    reverse(a,n);
    for(int j=0;j<n;j++){
        cout << a[j] << " ";
    }
    return 0;
}
