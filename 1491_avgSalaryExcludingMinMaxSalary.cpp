#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
double average(vector<int> &salary)
{
    int s = 0;
    return (accumulate(salary.begin(), salary.end(), s) - (*max_element(salary.begin(), salary.end()) + *min_element(salary.begin(), salary.end()))) / (salary.size() - 2);
};
int main()
{
    vector<int> v;
    v = {1000, 2000, 3000};
    cout << average(v);
    return 0;
}