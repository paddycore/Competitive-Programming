#include <bits/stdc++.h>

using namespace  std;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int N = 1e3+10;
const int MOD = 1e9 + 9;

int dp[N][N][11];

int main(){
    setIO("team");

    int n,m,K;cin >> n >> m >> K;
    vector<int> a(n),b(m);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;


    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j][0] = 1;
        }
    }

    for(int k=1;k<=K;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j][k] = ((dp[i - 1][j][k] + dp[i][j - 1][k]) % MOD - dp[i - 1][j - 1][k] + MOD) % MOD;
                if(a[i - 1] > b[j - 1]){
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k - 1]) % MOD;
                }
            }
        }
    }
    cout << dp[n][m][K];
    return 0;
}
