//calculate total sum of subset whose sums are distinct

#include <iostream>
#include <vector>

using namespace std;

int subsetSum(vector<int> &ivec, int n, int sum)
{
    vector<vector<bool>> mat(n + 1, vector<bool>(sum + 1, false));   
    for (int i = 0; i <= n; i++)
        mat[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < ivec[i - 1])
                mat[i][j] = mat[i - 1][j];
            if (j >= ivec[i - 1])
                mat[i][j] = mat[i - 1][j] || mat[i - 1][j - ivec[i - 1]];
        }
    }

    //
    int maxSum = 0;
    for (int j = 0; j <= sum; j++)
    {
        if (mat[n][j])
            maxSum += j;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return maxSum;
}

int main()
{
    vector<int> ivec;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ivec.clear();
        ivec.resize(n);
        int sum = 0;
        for (int i = 0; i != n; i++)
        {
            cin >> ivec[i];
            sum += ivec[i];
        }

        cout << subsetSum(ivec, n, sum) << endl;
    }
}