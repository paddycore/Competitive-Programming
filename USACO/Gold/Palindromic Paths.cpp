#include <bits/stdc++.h>

using namespace  std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int MOD = 1e9 + 7;

int main(){
    setIO("palpath");

    int n;cin >> n;
    vector<string> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] = " " + a[i];
    }

    if(a[1][1] != a[n][n]){
        cout << 0;
        return 0;
    }

    vector<vector<ll>> dp(n + 2,vector<ll>(n + 2));

    dp[1][n] = 1;
    for(int k=0;k<n;k++){
        vector<vector<ll>> next_dp(n + 2,vector<ll>(n + 2));
        for(int r1 = 1;r1 <= n;r1++){
            for(int r2 = 1;r2 <= n;r2++){
                int c1 = k + 2 - r1;
                int c2 = 2*n - k - r2;
                if(c1 < 1 || c1 > n || c2 < 1 || c2 > n) continue;
                if(a[r1][c1] == a[r2][c2]){
                    next_dp[r1][r2] =  ((dp[r1][r2] + dp[r1][r2 + 1]) % MOD + (dp[r1 - 1][r2] + dp[r1 - 1][r2 + 1]) % MOD) % MOD;
                }
            }
        }
        dp = next_dp;
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans = (ans + dp[i][i]) % MOD;
    }
    cout << ans;
    return 0;
}
