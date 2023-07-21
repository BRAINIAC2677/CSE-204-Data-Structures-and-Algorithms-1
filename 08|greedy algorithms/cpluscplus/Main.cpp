#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end());
    long long int cost = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cost += (prices[i] * ((n - 1 - i) / k + 1));
    }
    cout << cost << "\n";
    return 0;
}