#include <iostream>
using namespace std;

int dp[16] = { 0 };

int main(void) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t, p;
        cin >> t >> p;
        if (dp[i-1] > dp[i]) dp[i] = dp[i-1];
        if (dp[i-1] + p > dp[i+t-1]) dp[i+t-1] = dp[i-1] + p;
    }
    cout << dp[N];
}
