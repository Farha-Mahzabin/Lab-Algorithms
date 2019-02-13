#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


class Point
{
public:
    double x, y;
    Point(int x, int y) : x(x), y(y) { }
};

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        vector<Point> pvec;
        int n;
        cin >> n;
        int x, y;
        while(n--)
        {
            cin >> x >> y;
            pvec.emplace_back(Point(x, y));
        }
        sort(pvec.begin(), pvec.end(), ;
        int i = pvec.size() - 1;
        int prev_x = pvec[i].x;
        int prev_y = pvec[i].y;
        int top = y;

        int length = 0;
        for(int i = pvec.size() - 1; i >= 0; i--)
        {
            if(pvec[i].y > top)
            {
                length += sqrt(pow(pvec[i].x - prev_x, 2) +  pow(pvec[i].y - prev_y, 2)) * ((pvec[i].y - top) /(double) (pvec[i].y - prev_y));  
                top = pvec[i].y;
            }
            prev_x = pvec[i].x;
            prev_y = pvec[i].y;
        }
        cout << fixed << setprecision(2) << length << endl;
    }
}