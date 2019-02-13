#include <iostream>
#include <vector>
using std::vector;

void input(vector<vector<int>>& adjacencyMatrix, int mSize)
{
	for(int i = 0; i != mSize; i++)
    {
    	for(int j = 0; j != mSize; j++)
    	{
    		std::cin >> adjacencyMatrix[i][j];
    	}
    }
}
void DFS(int start, vector<vector<int>>& adjacencyMatrix, vector<bool>& visitedNodes)
{
	visitedNodes[start] = true;
	std::cout << start << " ";
	for(int i = 0; i != adjacencyMatrix[start].size(); i++)
	{
		if(!visitedNodes[i] && adjacencyMatrix[start][i])
			DFS(i, adjacencyMatrix, visitedNodes);
	}
}

void DFSUtilize(int start, vector<vector<int>>& adjacencyMatrix)
{
	vector<bool> visitedNodes(adjacencyMatrix[0].size());
	for(auto it = visitedNodes.begin(); it != visitedNodes.end(); it++)
		*it = false;
	DFS(start, adjacencyMatrix, visitedNodes);
}

int main()
{
	int mSize;
	std::cin >> mSize;
	vector<vector<int>> adjacencyMatrix(mSize, vector<int>(mSize));
	std::cout << "Enter the adjacency matrix: " << std::endl;
	input(adjacencyMatrix, mSize);
	int start;
	std::cout << " enter starting to node to perfrom dfs from: ";
	std::cin >> start;
	DFSUtilize(start, adjacencyMatrix);
}