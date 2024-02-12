#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int calculateMinimumThrows(int numPlayers, vector<int> &playerPositions)
{
    map<int, int> snakes, ladders;

    for (int i = 0; i < 2 * numPlayers; i += 2)
    {
        if (playerPositions[i] < playerPositions[i + 1])
        {
            ladders[playerPositions[i] - 1] = playerPositions[i + 1] - 1;
        }
        else
        {
            snakes[playerPositions[i] - 1] = playerPositions[i + 1] - 1;
        }
    }

    queue<pair<int, int>> q;
    vector<bool> visited(30, false);
    visited[0] = true;
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if (current.first == 29)
        {
            return current.second;
        }
        for (int currentPosition = current.first + 1; currentPosition <= min(current.first + 6, 29); currentPosition++)
        {
            int newPosition = currentPosition;
            if (ladders.count(newPosition))
            {
                newPosition = ladders[newPosition];
            }
            else if (snakes.count(newPosition))
            {
                newPosition = snakes[newPosition];
            }
            if (!visited[newPosition])
            {
                visited[newPosition] = true;
                q.push({newPosition, current.second + 1});
            }
        }
    }
}

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    
        int numPlayers;
        cin >> numPlayers;
        vector<int> playerPositions(2 * numPlayers);
        for (int i = 0; i < 2 * numPlayers; i++)
        {
            cin >> playerPositions[i];
        }
        cout << "Minimum number of throws is: " << calculateMinimumThrows(numPlayers, playerPositions) << endl;
    
    return 0;
}