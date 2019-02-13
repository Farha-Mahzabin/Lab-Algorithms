//bfs

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int main()
{
    const int size = 20005;
    vector<list<int>> adj(size);
    vector<int> visited(size);
    long sum = 0;
    int T;
    cin >> T;
    int t = 0;
    while(T--)
    {
        int n;
        cin >> n;
        adj.clear();
        visited.clear();
        visited.resize(size, 0); // 0 not yet visited, 1 lyka, 2 vamps
        adj.resize(size);
        sum = 0;

        int x, y;
        while(n--)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 0; i < size; i++)
        {
            if(visited[i] == 0 && !adj[i].empty())
            {
                int lyka = 0;
                int vamps = 0;
                queue<int> que;
                que.push(i);
                visited[i] = 1;
                lyka++;
                int curr;

                while(!que.empty())
                {
                    curr = que.front();
                    que.pop();
                    for(auto &it: adj[curr])
                    {
                        if(visited[it] == 0)
                        {
                            que.push(it);
                            if(visited[curr] == 1)
                            {
                                visited[it] = 2;
                                vamps++;
                            }
                            else 
                            {
                                visited[it] = 1;
                                lyka++;
                            }
                        }
                    }
                }
                sum += max(lyka, vamps);
            }
        }
        cout << "Case " << ++t << ": " << sum << endl;
    }
}