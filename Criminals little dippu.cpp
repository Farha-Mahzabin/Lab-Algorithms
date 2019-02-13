#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end)
{
    std::vector<typename It::value_type> v;
    It it_l{ begin }, it_r{ mid };
    const It it_mid{ mid }, it_end{ end };

    while (it_l != it_mid && it_r != it_end)
    {
        v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
    }   

    v.insert(v.end(), it_l, it_mid);    
    v.insert(v.end(), it_r, it_end);

    return std::move(v);
}

template<typename It>
void merge_sort(It begin, It end)
{
    auto size = std::distance(begin, end);
    if (size < 2)
        return;

    auto mid = std::next(begin, size / 2);
    merge_sort(begin, mid);
    merge_sort(mid, end);

    auto &&v = merge(begin, mid, end);
    std::move(v.cbegin(), v.cend(), begin);
}

int main()
{
    int T; 
    int N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        vector<int> ivec(N);
        for(int i = 0; i != N; i++)
        {
            cin >> ivec[i];

        }
        
       // merge_sort(ivec, 0, ivec.size() - 1);
        merge_sort(ivec.begin(), ivec.end());
        //std::sort(ivec.begin(), ivec.end());
        // for(auto& it: ivec)
        // {
        //     cout << it << " ";
        // }
        cout << endl;
        int prev_ans = 1, count = 1;

        //for(int i = ivec.size() - 1; i > 0; i--)
        for(int i = 0; i < ivec.size() - 1; i++)
        {

            if(ivec[i] == ivec[i+1])
                count++;
            else
            {
                if(count > prev_ans)
                {
                    prev_ans = count;
                }
                count = 1;
            }
        }
        if(count > prev_ans)
            prev_ans = count;
        //cout << prev_ans << endl;

    }
}