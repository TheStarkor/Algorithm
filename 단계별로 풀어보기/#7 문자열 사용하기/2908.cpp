#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    string a, b; cin >> a >> b;
    bool aa = true;
    for(int i=2;i>=0;i--){
        if(a[i] < b[i]) {
            aa = false;
            break;
        } else if (a[i] > b[i]) break;
    }
    if(aa){
        for(int i=2;i>=0;i--) cout << a[i];
    } else {
        for(int i=2;i>=0;i--) cout << b[i];
    }
}
