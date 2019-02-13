#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;



int partition(vector<long int>& ivec, int low, int high)
{
	int pivElement = ivec[high];
	int backInd = low - 1;
	for(int ind = low; ind != high; ind++)
	{
		if(ivec[ind] <= pivElement)
		{
			backInd++;
			std::swap(ivec[backInd], ivec[ind]);
		}
	}
	std::swap(ivec[backInd + 1], ivec[high]);
	return backInd + 1;
}

void quickSort(vector<long int> &ivec, int low, int high)
{
	if(low < high)
	{
		int piv = partition(ivec, low, high);
		quickSort(ivec, low, piv - 1);
		quickSort(ivec, piv + 1, high);
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
        vector<long int> ivec(sz);
        for (int i = 0; i != sz; i++)
            cin >> ivec[i];
        quickSort(ivec, 0, ivec.size() - 1);

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