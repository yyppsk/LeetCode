#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class UndergroundSystem
{
    vector<vector<string>> tracker;
    vector<vector<string>> checKOut;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        vector<string> inputs;
        inputs.push_back(to_string(id));
        inputs.push_back(stationName);
        inputs.push_back(to_string(t));
        tracker.push_back(inputs);
    }

    void checkOut(int id, string stationName, int t)
    {
        vector<string> inputs;
        inputs.push_back(to_string(id));
        inputs.push_back(stationName);
        inputs.push_back(to_string(t));
        checKOut.push_back(inputs);
    }

    double getAverageTime(string startStation, string endStation)
    {
        vector<double> avg;
        for (int i = 0; i < tracker.size(); i++)
        {
            for (int j = 0; j < checKOut.size(); j++)
            {
                if (tracker[i][1] == startStation && checKOut[j][1] == endStation && tracker[i][0] == checKOut[j][0])
                {
                    cout << "\n"
                         << checKOut[j][2] << " " << tracker[i][2] << endl;
                    avg.push_back(stod(checKOut[j][2]) - stod(tracker[i][2]));
                }
            }
        }
        int s = accumulate(avg.begin(), avg.end(), 0);
        if (avg.size() == 1)
            return avg[0];
        else
            return s / avg.size();
    }
    void print()
    {
        for (int i = 0; i < tracker.size(); i++)
        {
            for (auto it = tracker[i].begin(); it != tracker[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
        for (int i = 0; i < checKOut.size(); i++)
        {
            for (auto it = checKOut[i].begin(); it != checKOut[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
int main()
{
    UndergroundSystem undergroundSystem = UndergroundSystem();
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem.checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    printf("%lf", undergroundSystem.getAverageTime("Paradise", "Cambridge"));
    printf("%lf", undergroundSystem.getAverageTime("Leyton", "Waterloo")); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
                                                                           // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem.checkIn(10, "Leyton", 24);
    // undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 11.00000
    printf("%lf", undergroundSystem.getAverageTime("Leyton", "Waterloo"));
    undergroundSystem.checkOut(10, "Waterloo", 38); // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    printf("%lf", undergroundSystem.getAverageTime("Leyton", "Waterloo"));
    // undergroundSystem.getAverageTime("Leyton", "Waterloo"); // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    // undergroundSystem.print();
    return 0;
}