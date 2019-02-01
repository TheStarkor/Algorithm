#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
        int r;
        char s[20];
        scanf("%d %s", &r, s);
        for (int i=0;i<strlen(s);i++){
            for(int j=0;j<r;j++) printf("%c", s[i]);
        }
        printf("\n");
    }
}
