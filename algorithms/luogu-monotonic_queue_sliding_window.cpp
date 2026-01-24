// Luoge P1886

#include <deque>
#include <vector>
#include <iostream>

using namespace std;

int numbers[1000005];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    // Minimum Part
    deque<int> queueValue;
    for (int i = 0; i < n; i++)
    {
        // Remember to check empty.
        while (!queueValue.empty() && queueValue.front() <= i - k)
            queueValue.pop_front();
        while (!queueValue.empty() && numbers[queueValue.back()] > numbers[i])
            queueValue.pop_back();
        queueValue.push_back(i);
        if (i >= k - 1)
            cout << numbers[queueValue.front()] << " ";
    }
    while (!queueValue.empty())
        queueValue.pop_front();
    cout << endl;
    // Maximum part
    for (int i = 0; i < n; i++)
    {
        while (!queueValue.empty() && queueValue.front() <= i - k)
            queueValue.pop_front();
        while (!queueValue.empty() && numbers[queueValue.back()] < numbers[i])
            queueValue.pop_back();
        queueValue.push_back(i);
        if (i >= k - 1)
            cout << numbers[queueValue.front()] << " ";
    }
    while (!queueValue.empty())
        queueValue.pop_front();
}