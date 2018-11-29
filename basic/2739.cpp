#include <iostream> 
using namespace std;

int main(){
    int cnt;
    cin >> cnt;
    for(int i=1;i<=9;i++){
        cout << cnt << " * " << i << " = " << cnt*i << '\n';
    }
}