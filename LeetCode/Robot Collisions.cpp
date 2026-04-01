#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct Robot{
    int position;
    int health;
    char direction;
    int index;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> res;
        stack<int> s;
        vector<Robot> robot;

        // Combine related data
        for(int i = 0; i<positions.size(); i++)
        {
            robot.push_back({positions[i], healths[i], directions[i], i});
        }
        // Sort based on positions vector
        sort(robot.begin(), robot.end(), [](Robot a, Robot b){
            return a.position < b.position;
        });

        for(int i = 0; i<robot.size(); i++)
        {
            if(robot[i].direction == 'R')
            {
                s.push(i);

            }else
            {
                while (!s.empty() && robot[i].health > 0)
                {
                    int j = s.top();

                    if(robot[j].health == robot[i].health)
                    {
                        robot[i].health = 0;
                        robot[j].health = 0;
                        s.pop();
                        break;
                    }
                    else if(robot[j].health > robot[i].health)
                    {
                        // Remove the health of the left robot and decrease the health of the robot moving right by 1
                        robot[i].health = 0;
                        robot[j].health--;
                        break;
                    }
                    else
                    {
                        robot[i].health--;
                        robot[j].health = 0;
                        s.pop();
                    }
                }
            }
        }

        // Restore original order
        sort(robot.begin(), robot.end(), [](Robot a, Robot b){
            return a.index < b.index;
        });

        for (auto r: robot)
        {
            if(r.health)
            res.push_back(r.health);
        }

        return res;
    }
};
