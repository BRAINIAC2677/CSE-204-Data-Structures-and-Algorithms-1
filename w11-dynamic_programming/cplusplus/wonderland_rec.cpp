#include <bits/stdc++.h>
using namespace std;

#define isSet(n, i) bool(n & (1LL << i))
#define Set(n, i) (n | (1LL << i))
#define unSet(n, i) (n & !(1LL << i))
#define N 12

int allmask[N];
int n, cost[N][N], dp[N][1025];

int rec(int idx, int mask)
{
    mask = Set(mask, idx);
    if (mask == allmask[n])
    {
        return cost[idx][idx];
    }
    if (dp[idx][mask] != -1)
    {
        return dp[idx][mask];
    }
    int cur = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!(isSet(mask, i)))
        {
            int extra = 0;
            for (int k = 0; k < n; k++)
            {
                if (isSet(mask, k))
                {
                    extra += cost[i][k];
                }
            }
            cur = min(cur, rec(i, mask) + extra);
        }
    }
    return dp[idx][mask] = cur + cost[idx][idx];
}

int main()
{
    allmask[0] = 0;
    for (int i = 1; i < N; i++)
    {
        allmask[i] = (allmask[i - 1] + 1) * 2 - 1;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, rec(i, 0));
    }
    cout << ans << "\n";
    return 0;
}