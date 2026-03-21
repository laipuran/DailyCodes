// Luogu P1002 [NOIP 2002 普及组] 过河卒

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> count;

long long getCount(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (count[y][x] == -1)
        return 0;
    return count[y][x];
}

void setControl(int x, int y)
{
    if (x < 0 || y < 0 || y >= count.size() || x >= count[0].size())
        return;
    count[y][x] = -1;
}

int main()
{
    int destX, destY, horseX, horseY;
    cin >> destX >> destY >> horseX >> horseY;
    count = vector<vector<long long>>(destY + 1, vector<long long>(destX + 1, 0));

    int delta[9][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}, {0, 0}};
    for (int i = 0; i < 9; i++)
        setControl(horseX + delta[i][0], horseY + delta[i][1]);
    if (count[0][0] == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    count[0][0] = 1;

    for (int i = 0; i <= destX; i++)
    {
        for (int j = 0; j <= destY; j++)
        {
            if (count[j][i] != 0)
                continue;
            count[j][i] = getCount(i - 1, j) + getCount(i, j - 1);
        }
    }
    cout << count[destY][destX] << endl;
}
