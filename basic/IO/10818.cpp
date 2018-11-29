#include <iostream> 
using namespace std;

int main(){
    int n, cmp, min=1000000, max=-1000000;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cmp;
        if (cmp < min) min = cmp;
        if (cmp > max) max = cmp;
    }
    cout << min << " " << max;
}