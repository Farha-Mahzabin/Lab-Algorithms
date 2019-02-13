#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using std::stack;
using std::vector;

class coord
{
public:
	coord(int x, int y): x(x), y(y) { }
	coord() = default;
	int x, y;
	bool operator < (coord b);
};

inline bool coord::operator < (coord b)
{
	if (y != b.y)
		return y < b.y;
	return x < b.x;		
}

int sqrDist(coord a, coord b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int direction(coord a, coord b, coord c) 
{
	int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (area > 0)
		return -1;
	else if (area < 0)
		return 1;
	return 0;
}

stack<coord> grahamscan(vector<coord>& coords)
{
	stack<coord> hull;
	coord pivot;
	int min = 0;
	for(int i = 1; i != coords.size(); i++)
	{
		if(coords[i] < coords[min])
			min = i;
	}

	std::swap(coords[0], coords[min]);
	pivot = coords[0];

	//sort by polar angle
	std::sort(coords.begin() + 1, coords.end(),
		[&pivot] (const coord& a, const coord& b) -> bool
		{
			int order = direction(pivot, a, b);
			if (order == 0)
				return sqrDist(pivot, a) < sqrDist(pivot, b);
			return (order == -1);
		});
	for(int i = 1; i != coords.size(); i++)
	{

	}
	if(coords.size() < 3)
		return hull;
	hull.push(coords[0]);
	hull.push(coords[1]);
	hull.push(coords[2]);
	for(int i = 3; i != coords.size(); i++)
	{
		coord top = hull.top();
		hull.pop();
		while(direction(hull.top(), top, coords[i]) != -1)
		{
			top = hull.top();
			hull.pop();
		}
		hull.push(top);
		hull.push(coords[i]);
	}
	return hull;
}

int main()
{
	int x; 
	int y;
	vector<coord> coords;
	while(std::cin >> x >> y)
	{
		coords.push_back({x, y});
	}
	stack<coord> result = grahamscan(coords);

	while(!result.empty())
	{
		coord co = result.top();
		result.pop();
		std::cout << co.x << " " << co.y << std::endl;
	}
}