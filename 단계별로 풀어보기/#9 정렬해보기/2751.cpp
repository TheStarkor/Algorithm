#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, d[1000000];
	cin >> n;
	for (int i=0;i<n;i++) cin >> d[i];
	sort(d,d+n);
	for (int i=0;i<n;i++) cout << d[i] << '\n';
}
