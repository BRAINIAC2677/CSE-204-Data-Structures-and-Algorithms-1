#include <bits/stdc++.h>
using namespace std;

#define isSet(n, i) bool(n & (1LL << i))
#define Set(n, i) (n | (1LL << i))
#define toggleBit(n, i) (n ^ (1 << i))
#define N 12

int main()
{
    int n, allmask = 0;
    cin >> n;
    int cost[n][n];
    for (int i = 0; i < n; i++)
    {
        allmask = Set(allmask, i);
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    int dp[allmask + 1] = {0};
    for (int i = 1; i <= allmask; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (isSet(i, j))
            {
                int cur = dp[toggleBit(i, j)];
                for (int k = 0; k < n; k++)
                {
                    if (isSet(i, k))
                    {
                        cur += cost[j][k];
                    }
                }
                dp[i] = min(dp[i], cur);
            }
        }
    }
    cout << dp[allmask] << "\n";
    return 0;
}