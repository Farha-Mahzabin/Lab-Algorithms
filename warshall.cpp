#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

vector<vector<vector<int>>> warshall(vector<vector<int>>& matrix)
{
	size_t size = matrix[0].size();
	vector<vector<vector<int>>> calculated(size, vector<vector<int>>(size, vector<int>(size)));
	for(int k = 0; k != size; k++)
	{
		for(int j = 0; j != size; j++)
		{
			calculated[0][k][j] = matrix[k][j];
		}
	}

	for(int k = 1; k != size; k++)
	{
		for(int i = 0; i != size; i++)
		{
			for(int j = 0; j != size; j++)
			{
				calculated[k][i][j] = std::min(calculated[k-1][i][j], calculated[k-1][i][k] + calculated[k-1][k][j]);
			}
		}
	}

	return calculated;
}


int main()
{
	vector<vector<int>> matrix = { 
									{0,   3,  8, INT_MAX/2, -4},
    	                    		{INT_MAX/2, 0, INT_MAX/2, 1, 7},
	                        		{INT_MAX/2, 4, 0, INT_MAX/2, INT_MAX/2},
                         			{2, INT_MAX/2, -5, 0, INT_MAX/2},
                         			{INT_MAX/2, INT_MAX/2, INT_MAX/2, 6, 0}
		            			 };
	int size = matrix[0].size();
    for(int i = 0; i != size; i++)
   	{
   		for (int j = 0; j != size; ++j)
   		{
   			std::cout << matrix[i][j] << " ";
 		}	
 		std::cout << std::endl;
   	}
   	vector<vector<vector<int>>> result = warshall(matrix);
   	
   	for(int i = 0; i != size; i++)
   	{
   		for (int j = 0; j != size; ++j)
   		{
   			std::cout << result[size - 1][i][j] << " ";
 		}	
 		std::cout << std::endl;
   	}
}