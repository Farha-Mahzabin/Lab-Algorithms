#include <vector>
#include <string>
#include <iostream>
using namespace std;


vector<int> KMP_INIT(string ptrn)
{
    vector<int> lps(ptrn.size(), 0);
    int prevLongest = 0;
    for(int i = 1; i != ptrn.size(); )
    {
        if(ptrn[i] == ptrn[prevLongest])
        {
            lps[i++] = ++prevLongest;
        }
        else
        {
            if(prevLongest)
            {
                prevLongest = lps[prevLongest - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string ptrn)
{
    vector<int> indices;
    vector<int> lps = KMP_INIT(ptrn);
    int i = 0, j = 0;
    while(i < text.size())
    {
        if(text[i] == ptrn[j])
        {
            i++;
            j++;
        }
        if(j == ptrn.size())
        {
            indices.push_back((i - j) + 1);
            j = lps[j - 1];
        }

        else if ( i < text.size() && ptrn[j] != text[i])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return indices;
    
}

  
int main() 
{
    freopen("inp.txt", "r", stdin);
    int T;
    cin >> T;
    int t = 0;
    while(t++ != T)
    {
        string text;
        string ptrn;
        cin >> text >> ptrn;
        vector<int> indices = KMP(text, ptrn); 
        if(indices.size() == 0)
        {
            cout << "Not Found" << endl;
        }
        else 
        {
            cout << indices.size() << endl;
            for(auto &it : indices)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
} 