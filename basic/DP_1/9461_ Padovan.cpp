#include <iostream>
using namespace std;
long long d[101] = {0,1,1,1,2,2,};
int main(){
	int cnt, n;
	cin >> cnt;
	while(cnt--){
		cin >> n;
		for (int i=6;i<=n;i++) d[i] = d[i-1] + d[i-5];
		cout << d[n] << '\n';
	}
}