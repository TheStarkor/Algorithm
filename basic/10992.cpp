#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1;i<n;i++){
        for (int j=0;j<n-i;j++) cout << " ";
        cout << "*";
        for (int j=0;j<(i-1)*2-1;j++) cout << " ";
        if (i !=1) cout << "*";
        cout << "\n";
    } 
    for (int i=0;i<2*n-1;i++) cout << "*";
}