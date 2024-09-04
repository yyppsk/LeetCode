#include <bits/bits-stdc++.h>
using namespace std;
int robotSim(vector<int> &commands, vector<vector<int>> obstacles)
{
    int startX = 0, startY = 0;
    char direction = 'N';
    int maximumDistance = INT_MIN;
    set<pair<int, int>> st;

    for (int i = 0; i < obstacles.size(); i++)
    {
        st.insert({obstacles[i][0], obstacles[i][1]});
    }

    for (int i = 0; i < commands.size(); i++)
    {
        int command = commands[i];
        if (command == -1)
        {
            if (direction == 'N')
            {
                direction = 'E';
            }
            else if (direction == 'E')
            {
                direction = 'S';
            }
            else if (direction == 'S')
            {
                direction = 'W';
            }
            else if (direction == 'W')
            {
                direction = 'N';
            }
        }
        else if (command == -2)
        {
            if (direction == 'N')
            {
                direction = 'W';
            }
            else if (direction == 'W')
            {
                direction = 'S';
            }
            else if (direction == 'S')
            {
                direction = 'E';
            }
            else if (direction == 'E')
            {
                direction = 'N';
            }
        }
        else
        {
            if (direction == 'N')
            {
                while (command--)
                {
                    if (st.find({startX, startY + 1}) != st.end())
                    {
                        break;
                    }

                    startY += 1;
                }
            }
            else if (direction == 'S')
            {
                while (command--)
                {
                    if (st.find({startX, startY - 1}) != st.end())
                    {
                        break;
                    }

                    startY -= 1;
                }
            }
            else if (direction == 'E')
            {
                while (command--)
                {
                    if (st.find({startX + 1, startY}) != st.end())
                    {
                        break;
                    }

                    startX += 1;
                }
            }
            else if (direction == 'W')
            {
                while (command--)
                {
                    if (st.find({startX - 1, startY}) != st.end())
                    {
                        break;
                    }

                    startX -= 1;
                }
            }
        }

        maximumDistance = max(startX * startX + startY * startY, maximumDistance);
    }

    return maximumDistance;
}
int main()
{
    vector<int> commands = {6, -1, -1, 6};
    cout << robotSim(commands, {});
    return 0;
}