#include <iostream>
using namespace std;

int main(){
	int d[11] = {0, 1, 2, 4,};
	int n, cnt;	
	cin >> cnt;
	while (cnt--){
		cin >> n;
		for (int i=4;i<=n;i++) d[i] = d[i-1] + d[i-2] + d[i-3];
		cout << d[n] << '\n';
	}
}