#include <iostream> 
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++) cout << " ";
        for(int k=0;k<i;k++) cout << "*";
        for(int l=0;l<i-1;l++) cout << "*";
        cout << '\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++) cout << " ";
        for(int k=0;k<n-i;k++) cout << "*";
        for(int l=0;l<n-i-1;l++) cout << "*";
        cout << '\n';
    }
}