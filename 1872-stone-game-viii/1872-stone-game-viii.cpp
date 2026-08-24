class Solution {
public:
    int dp[100009][2];
    vector<int> a;
    int solve(int i=1, int j=0) {
        if (i == a.size()) {
            return 0;
        }
        int &ans=dp[i][j];
        if (~ans) return ans;

        if (i+1 == a.size()) return ans=solve(i+1, !j)+(j?-a[i]:a[i]);

        if (!j) {
            ans=max(solve(i+1, j), solve(i+1, !j)+a[i]);
        } else {
            ans=min(solve(i+1, j), solve(i+1, !j)-a[i]);
        }

        return ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        a.push_back(stones[0]);
        for (int i=1; i<stones.size(); i++) a.push_back(stones[i]+a.back());
        memset(dp, -1, sizeof dp);
        return solve();
    }
};