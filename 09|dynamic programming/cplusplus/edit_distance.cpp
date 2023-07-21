#include <bits/stdc++.h>
using namespace std;

int main()
{
    // converting cost of a to b by insert, remove and replace operations in string s
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    int dp[2][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i % 2][j] = j;
            }
            else if (j == 0)
            {
                dp[i % 2][j] = i;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
            }
            else
            {
                dp[i % 2][j] = 1 + min({dp[i % 2][j - 1], dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - 1]});
            }
        }
    }
    cout << dp[m % 2][n] << "\n";
    return 0;
}