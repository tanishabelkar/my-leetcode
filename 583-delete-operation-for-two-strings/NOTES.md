Used dp to find the longest common substring and subtracted the length of that from the original strings
​
```
if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1
else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```