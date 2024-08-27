#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<vector<int>> stickers(2, vector<int>(n));

        // first가 있을 때, second가 없을 때
        vector<vector<pair<int,int>>> dp(2, vector<pair<int,int>>(n));

        for (int row = 0; row < 2; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                int input;
                cin >> input;

                stickers[row][col] = input;

               
            }
        }
        for (int col = 0; col < n; ++col)
        {
            for (int row = 0; row < 2; ++row)
            {

                if (col - 2 >= 0)
                {
                    if (row == 0)
                    {
                        stickers[row][col] += max(stickers[row + 1][col - 2], stickers[row + 1][col - 1]);
                    }
                    else
                    {
                        stickers[row][col] += max(stickers[row - 1][col - 2], stickers[row - 1][col - 1]);

                    }
                }
                else if (col - 1 >= 0)
                {
                    if (row == 0)
                    {
                        stickers[row][col] += stickers[row + 1][col - 1];
                    }
                    else
                    {
                        stickers[row][col] += stickers[row - 1][col - 1];

                    }

                }
               /* dp[row][col].first = stickers[row][col];

                int tmp;
                if (row == 0)
                {
                    dp[row + 1][col].second += stickers[row][col];
                    tmp = dp[row + 1][col].first;
                }
                else
                {
                    dp[row - 1][col].second += stickers[row][col];
                    tmp = dp[row - 1][col].first;
                }
                if (col != 0)
                {
                    dp[row][col].second = max(dp[row][col - 1].first, max(dp[row][col - 1].second,tmp));
                    dp[row][col].first += dp[row][col - 1].second;
                }*/
            }
        }
        //cout << "ans" << endl;
        //for (int row = 0; row < 2; ++row)
        //{
        //    for (int col = 0; col < n; ++col)
        //    {
        //       // cout << dp[row][col].first << ", " << dp[row][col].second << " ";
        //        cout << stickers[row][col] << " ";
        //    }
        //    cout << endl;
        //}

        cout << max(stickers[0].back(), stickers[1].back()) << endl;
    }    

}