#include <bits/stdc++.h>

using namespace std;
// Function to find the Longest Common Subsequence

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();
  // Create a 2D vector to store the lengths of LCS for subproblems

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }
  // Fill the dp table in a bottom-up manner

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
       // If the characters match, extend the LCS by 1
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
      // If characters don't match, take the maximum of LCS without considering one character
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
    str += "$"; // dummy string
  }
  // printing the string

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}

int main() {

  string str1,str2;
  cout<<"Enter the string 1:";
  cin>>str1;
  cout<<"Enter the string 2: ";
  cin>>str2;
  cout << "The Longest Common Subsequence is ";
  lcs(str1, str2);
}