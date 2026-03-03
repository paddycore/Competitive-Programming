#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


void solve() {
    int W,H,n;cin >> W >> H >> n;
    vector<vector<int>> dp(W + 1,vector<int>(H + 1));
    for(int i=1;i<=W;i++){
        for(int j=1;j<=H;j++){
            dp[i][j] = i * j;
        }
    }
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        dp[x][y] = 0;
    }

    for(int w = 1;w <= W;w++){
        for(int h=1;h <= H;h++){
            for(int i=1;i<=w/2;i++){
                dp[w][h] = min(dp[w][h],dp[i][h] + dp[w - i][h]);
            }
            for(int j=1;j<=h/2;j++){
                dp[w][h] = min(dp[w][h],dp[w][j] + dp[w][h - j]);
            }
        }
    }

    cout << dp[W][H];

}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    
    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
