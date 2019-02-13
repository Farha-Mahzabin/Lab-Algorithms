#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void selectionSort(vector<int>& ivec)
{
    int sz = ivec.size();
    for(int i = 0; i != sz; i++)
    {
        int indexMin = i;
        for(int j = i + 1; j != sz; j++)
        {
            if(ivec[j] < ivec[indexMin])
                indexMin = j;
        }
        std::swap(ivec[i], ivec[indexMin]);
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int sz;
        cin >> sz;
        vector<int> ivec(sz);
        for (int i = 0; i != sz; i++)
            cin >> ivec[i];
        selectionSort(ivec);

        int count = 0;
        int i = 0;
        int j = 0;
        while (i < ivec.size() && j < ivec.size())
        {
            if (ivec[i] == ivec[j])
                count += j - i;
            else
                i = j;
            j++;
        }
        cout << count + ivec.size() << endl;
    }
}