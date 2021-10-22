#include <iostream>
using namespace std;

void partition(int *a,int n){
    int i=0,j=1;
    while(j<n){
        if(a[j]<0){
            swap(a[++i],a[j]);
        }
        j++;
    }
    swap(a[i],a[0]);
}

int main()
{
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    f(a,n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
