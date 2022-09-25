#include <iostream>
#include <string>
#include <unordered_map>
class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> checkingIn; //{stationName,time total}
    unordered_map<string, pair<int, int>> route;      // {totaltime,count}
    UndergroundSystem()
    {
    }
    void checkIn(int id, string stationName, int t)
    {
        checkingIn[id] = {stationName, t};
    }
    void checkOut(int id, string stationName, int t)
    {
        auto f = checkingIn[id];
        checkingIn.erase(id);
        string routeName = f.first + "_" + stationName;
        route[routeName].first += t - f.second;
        route[routeName].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string routeName = startStation + "_" + endStation;
        auto &routeN = route[routeName];
        return (double)routeN.first / routeN.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
using namespace std;
int main()
{
    UndergroundSystem undergroundSystem = UndergroundSystem();
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    undergroundSystem.checkIn(10, "Leyton", 24);
    undergroundSystem.checkOut(10, "Waterloo", 38);
    return 0;
}