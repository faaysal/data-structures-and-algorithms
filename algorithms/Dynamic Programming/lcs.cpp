#include <iostream>
using namespace std;

string s1, s2;
int dp[1000][1000];

int lcs(int i, int j) {
  if (i == s1.length() or j == s2.length()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if (s1[i] == s2[j]) {
    ans = 1 + lcs(i + 1, j + 1);
  }
  else {
    int ans1 = lcs(i + 1, j);
    int ans2 = lcs(i, j + 1);
    ans = max(ans1, ans2);
  }
  dp[i][j] = ans;
  return ans;
}

void lcs_print(int i, int j) {
  if (i == s1.length() or j == s2.length()) return;
  if (s1[i] == s2[j]) {
    cout << s1[i];
    return lcs_print(i + 1, j + 1);
  }
  else {
    int ans1 = lcs(i + 1, j);
    int ans2 = lcs(i, j + 1);
    if (ans1 > ans2) return lcs_print(i + 1, j);
    else return lcs_print(i, j + 1);
  }
}

int main() {
  cout << "Enter 2 string (separated by space or line):\n";
  cin >> s1 >> s2;

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      dp[i][j] = -1;
    }
  }
  int max_len = lcs(0, 0);
  cout << "Longest common subsequence length: " << max_len << '\n';
  cout << "Longest common subsequence: ";
  lcs_print(0, 0);
  cout << '\n';

  return 0;
}