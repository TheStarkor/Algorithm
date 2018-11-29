#include <iostream> 
using namespace std;

int main(){
    int n, i=1;
    cin >> n;
    while ((n-i)>=0){
        for(int j=0;j<n-i;j++) cout << " ";
        for(int j=0;j<i-1;j++) cout << "* ";
        cout << "*" << '\n';  
        i++;        
        }
}