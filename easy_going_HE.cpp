#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;
using std::cout;
using std::cin;

int main()
{
    int t;
    cin >> t;
    vector<int> ivec;

    while(t--)
    {
        ivec.clear();
        int n, m;
        cin >> n >> m;
        int size = n;
        int val;
        while(n--)
        {
            cin >> val;
            ivec.push_back(val);
        }

        sort(ivec.begin(), ivec.end());
        
        int min_sum = 0, max_sum = 0;
        m = size - m;

        for(int i = 0; i != m; i++)
        {
            min_sum += ivec[i];
            max_sum += ivec[size - 1 - i];
        }

        std::cout << max_sum - min_sum << std::endl;
    }
}