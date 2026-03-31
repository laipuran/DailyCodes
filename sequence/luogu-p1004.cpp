// Luogu P1004 [NOIP 2000 提高组] 方格取数

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<std::vector<std::vector<int>>>> dp(n + 1, std::vector<std::vector<std::vector<int>>>(n + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0))));
    while (true)
    {
        int x, y, val;
        std::cin >> x >> y >> val;
        if (!x && !y && !val)
            break;
        graph[x][y] = val;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++)
                {
                    int max = std::max(std::max(dp[i - 1][j][k - 1][l], dp[i][j - 1][k - 1][l]), std::max(dp[i - 1][j][k][l - 1], dp[i][j - 1][k][l - 1]));
                    if (i == k && j == l)
                        dp[i][j][k][l] = max + graph[i][j];
                    else
                        dp[i][j][k][l] = max + graph[i][j] + graph[k][l];
                }

    std::cout << dp[n][n][n][n];
}