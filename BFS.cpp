#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
void BFS(vector<vector<int>>& adjacencyMatrix, int source)
{
	vector<bool> visitedNodes(adjacencyMatrix[0].size());
	for(auto it = visitedNodes.begin(); it != visitedNodes.end(); it++)
		*it = false;
	visitedNodes[source] = true;
	int currRow = source;
	queue<int> qu;
	qu.push(source);
	while(!qu.empty())
	{
		currRow = qu.front();
		qu.pop();
		std::cout << currRow << " ";
		for(int i = 0; i != adjacencyMatrix[currRow].size(); i++)
		{
			if(!visitedNodes[i] && adjacencyMatrix[currRow][i])
			{
				visitedNodes[i] = true;
				qu.push(i);
			}
		}
	}
}

int main()
{
	int mSize;
	std::cin >> mSize;
	vector<vector<int>> adjacencyMatrix(mSize, vector<int>(mSize));

    std::cout << "Enter the adjacency matrix: " << std::endl;
    for(int i = 0; i != mSize; i++)
    {
    	for(int j = 0; j != mSize; j++)
    	{
    		std::cin >> adjacencyMatrix[i][j];
    	}
    }

    int start;
    std::cout << "Enter starting node: ";
    std::cin >> start;
 	BFS(adjacencyMatrix, start);

}