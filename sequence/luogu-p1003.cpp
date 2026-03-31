// Luogu P1003 [NOIP 2011 提高组] 铺地毯

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> rects(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        rects[i] = {x, y, x + a, y + b};
    }

    int x, y;
    std::cin >> x >> y;

    int count = -1;
    for (int i = 0; i < n; i++)
    {
        const auto &rect = rects[i];
        if (rect[0] <= x && rect[1] <= y && rect[2] >= x && rect[3] >= y)
            count = i + 1;
    }
    std::cout << count;
}