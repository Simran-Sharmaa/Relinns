# Algorithm for finding the Longest Common Subsequence

- Initialize a 2D vector dp of size (n+1) x (m+1) to store the lengths of LCS, where n and m are the lengths of s1 and s2, respectively.

- Set the base cases: dp[i][0] = dp[0][i] = 0 for all i from 0 to n and m.

- Start filling the dp table using a bottom-up approach:

    - a. For each pair of indices (ind1, ind2), if s1[ind1-1] == s2[ind2-1], increment the LCS length by 1: dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1].

    - b. If the characters don't match, take the maximum of LCS without considering one character: dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]).

- Backtrack through the dp table to construct the LCS string:

    - a. Initialize i and j to the lengths of s1 and s2 respectively.

    - b. While i and j are greater than 0, compare characters:

       - If s1[i-1] == s2[j-1], add the character to the LCS and move diagonally in the dp table.
       - If s1[i-1] > s2[j-1], move to the left in the dp table.
       - If s1[i-1] < s2[j-1], move upwards in the dp table.
       - Print the constructed LCS string.


# Instructions for running the matrix multiplication program

- Compile the code
- Input the number of rows and columns of the matrix 1
- Input the number of rows and columns of the matrix 2
- The number of columns of matrix 1 should be equal to the number of row of matrix 2.
- (n X m) * (m X p) = (n X p)
- Input elements for matrix 1 
- Input elements for matrix 2
