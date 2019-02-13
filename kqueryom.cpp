#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::merge;
using std::cin;
using std::cout;
using std::upper_bound;

std::vector<int> v[100005];

void build(vector<int>& ar, int id ,int l ,int r )
{
	if(r == l )
	{
		v[id].push_back(ar[l]);
		return ;
	}
	int mid = (l + r) / 2;
	build(ar, 2 * id, l, mid);
	build(ar, 2 * id + 1, mid + 1, r);
	merge(v[2 * id].begin(), v[2 * id].end(), v[2 * id + 1].begin(), v[2 * id + 1].end(), std::back_inserter(v[id]));
}

int query(int x, int y, int k, int id, int l, int r)
{
	
	if(x > r || l > y)
		return 0;
	if(x <= l && r <= y)
	{	
		return v[id].size() - (upper_bound(v[id].begin(), v[id].end(), k) - v[id].begin());
	}	
	int mid = (l + r) / 2;
	
	return query(x, y, k, 2 * id, l, mid) + query(x, y, k, 2 * id + 1, mid + 1, r) ;
}


int main()
{
    int n, q;
    
    cin >> n;
    vector<int> ar(30005);
    for(int i = 0; i != n; i++)
        cin >> ar[i];
    cin >> q;
	build(ar, 1, 0, ar.size() - 1);
    for(auto &it: v[0])
        cout << it << " ";
    cout << std::endl;

	int prev = 0;
	while(q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a = a ^ prev;
        b = b ^ prev;
        c = c ^ prev;
        prev = query(a -  1, b - 1, c, 1 , 0, ar.size() - 1);

		cout << prev << std::endl;
	}		
	return 0;
}