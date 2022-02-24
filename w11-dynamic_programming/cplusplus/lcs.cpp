#include <bits/stdc++.h>
using namespace std;

int **countLCS(string a, string b)
{
    int an = a.size(), bn = b.size(), **dp;
    dp = new int *[an + 1];
    for (int i = 0; i <= an; i++)
    {
        dp[i] = new int[bn + 1];
        dp[i][0] = 0;
        if (!i)
        {
            for (int j = 0; j <= bn; j++)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < an; i++)
    {
        for (int j = 0; j < bn; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp;
}

string findLCS(int **dp, string a, string b)
{
    string ans;
    int an = a.size(), bn = b.size();
    while (an > 0 && bn > 0)
    {
        if (dp[an][bn] == dp[an - 1][bn])
        {
            an--;
        }
        else if (dp[an][bn] == dp[an][bn - 1])
        {
            bn--;
        }
        else
        {
            ans.push_back(a[an - 1]);
            an--;
            bn--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int an = a.size(), bn = b.size();
    int **dp = countLCS(a, b);
    cout << dp[an][bn] << "\n";
    cout << findLCS(dp, a, b) << "\n";
    delete dp;
    return 0;
}