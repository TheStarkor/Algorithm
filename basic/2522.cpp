#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=1;i<=2*n-1;i++){
        for (int j=0;j<abs(n-i);j++) cout << " ";
        for (int k=0;k<n-abs(n-i);k++) cout << "*";
        cout << '\n';
    }
}