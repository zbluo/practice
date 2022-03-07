//
// Created by Zhong Bing on 2019-08-31.
//

#ifndef LZB_DEBUG_H
#define LZB_DEBUG_H

#include <queue>

int minCut(string s) {
    int len = s.size();
    vector<int> dp(len, len - 1);
    vector<vector<bool>> palindrome(len, vector<bool>(len, false));
    for(int i = len - 1; i >= 0; i--)
        for(int j = i; j < len; j++) {
            if(dp[i] == dp[j] && (j - i < 2 || palindrome[i+1][j-1])) {
                palindrome[i][j] = true;
                if(j == len - 1)
                    dp[i] = 0;
                else
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }

    return dp[0];
}


#endif //LZB_DEBUG_H
