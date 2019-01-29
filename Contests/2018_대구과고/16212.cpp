#include <algorithm>
#include <iostream>
#include <utility>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    vector<int> a;
    for(int i=0;i<n;i++){
        int tmp; scanf("%d", &tmp);
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    for(auto &p : a) printf("%d ", p);
}
