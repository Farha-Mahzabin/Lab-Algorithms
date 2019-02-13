#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::vector;
using std::pair;

class minEdge
{
public:
	int u, v, m;
	minEdge(int u, int v, int m): u(u), v(v), m(m) { }
};


int findParent(int index, vector<int>& parents)
{
	int par = index;
	while(parents[par] != -1)
	{
		par = parents[par];
		//std::cout << par << std::endl;
	}
	return par;
}

int uni(int i,int j, vector<int>& parents)
{
	std::cout << "i: " << i << " j: " << j << std::endl; 
	if(i!=j)
	{
		parents[j]=i;
		return 1;
	}
	return 0;
}

minEdge min(vector<vector<int>> &matrix, int size, vector<vector<bool>> &visited)
{
	int u, v;
	int min = INT_MAX - 100;
	for(int i = 0; i != size; i++)
	{
		for(int j = i + 1; j != size; j++)
		{
			if(matrix[i][j] && matrix[i][j] < min) //&& !visited[i][j])
			{
				min = matrix[i][j];
				u = i;
				v = j;
			}
		}
	}
	//return std::make_pair(min, std::make_pair(u, v));
	visited[u][v] = true;
	return minEdge(u, v, min);
}

int main()
{
	bool inserted;
	int size = 6;
	int num;
	int sz = 0;
	vector<vector<int>> matrix(size, vector<int>(size, false));
	vector<pair<int, int>> start_end(size);
	vector<vector<bool>> visited(size, vector<bool>(size));
	vector<int> parents(size, -1);
	std::list<int> sortedEdges;
	for(int i = 0; i != size; i++)
	{
		for(int j = i + 1; j != size; j++)
		{
			//sz++;
			std::cin >> num;
			matrix[i][j] = matrix[j][i] = num;
			/*
			if(num)
			{
				if(sortedEdges.empty())
					sortedEdges.push_front(num);
				else
				{
					for(auto it = sortedEdges.begin(); it != sortedEdges.end(); it++ )
					{
						inserted = false;
						if(*it > num)
						{
							inserted = true;
							sortedEdges.insert(it, num);
							break;
						}
					}
					if(!inserted)
						sortedEdges.push_back(num);
				}
			}
			*/
		}
	}

	for( ; sz != size; sz++)
	{
		minEdge muv = min(matrix, size, visited);  // m = minimum value, u = start index, v = end index
		//std::cout << muv.u << " - " << muv.v << " - " << muv.m << std::endl;
		int parentOfU, parentOfV;
		parentOfU = findParent(muv.u, parents);
		parentOfV = findParent(muv.v, parents);
		//if(parentOfU != parentOfV || (parentOfU == -1 && parentOfV == -1))
		if(uni(parentOfU, parentOfV, parents))
		{
			//parents[muv.v] = muv.u;
			std::cout << muv.u << " -> " << muv.v << " = " << muv.m << std::endl;
		}
		matrix[muv.u][muv.v] = INT_MAX;
	}

}




// if parent of u is notv the starting node
// then 









