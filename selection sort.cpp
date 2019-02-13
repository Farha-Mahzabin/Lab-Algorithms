#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::vector;

void selectionSort(vector<int> &ivec)
{
	int i = 0;
	//std::cout << ivec.size();
	while(i != ivec.size() - 1)
	{
		int smallest = i;
		for(int j = i+1; j <= ivec.size() - 1; j++)
		{
			if(ivec[j] < ivec[smallest])
				smallest = j;
		}
		int temp = ivec[smallest];
		ivec[smallest] = ivec[i];
		ivec[i++] = temp;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	vector<int> ivec;
	for(int i = 0; i != 10; i++)
		ivec.push_back(rand());
	for(auto it : ivec)
		std::cout << it <<" ";
	std::cout << std::endl;
	selectionSort(ivec);
	for(auto it : ivec)
		std::cout << it <<" ";
}