#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void countSort(vector<int> &ivec)
{
    int max = *(max_element(ivec.begin(), ivec.end()));
    int min = *(min_element(ivec.begin(), ivec.end()));
    int n = max - min + 1;
    vector<int> aux(n, 0);

    for (int i = 0; i != ivec.size(); i++)
        aux[ivec[i] - min]++;

    vector<int> sorted = ivec;

    for (int i = 1; i < aux.size(); i++)
    {
        aux[i] += aux[i - 1];
    }

    for (int i = ivec.size() - 1; i >= 0; i--)
    {
        sorted[aux[ivec[i] - min] - 1] = ivec[i];
        aux[ivec[i] - min]--;
    }

    ivec = sorted;
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
        countSort(ivec);
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