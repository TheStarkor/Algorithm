#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int main(){
	int cnt, n, ans = 0, s[100001][3], d[100001][3];
	cin >> cnt;
	while(cnt--){
		cin >> n;
		for (int i=1;i<=2;i++){
			for (int j=1;j<=n;j++){
				cin >> s[j][i];
			}
		}
		d[1][0] = 0;
		d[1][1] = s[1][1];
		d[1][2] = s[1][2];
		for (int i=2;i<=n;i++){
			d[i][0] = max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
			d[i][1] = max(d[i-1][0],d[i-1][2]) + s[i][1];
			d[i][2] = max(d[i-1][0],d[i-1][1]) + s[i][2];
		}
		ans = max(max(d[n][0],d[n][1]),d[n][2]);
		cout << ans << '\n';
	}
}