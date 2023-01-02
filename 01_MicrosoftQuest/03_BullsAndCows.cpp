#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        // First calculate bulls .. mark visited
        // From non-visited .. calculate cows (maintain count in map)
        int n=secret.size(), bulls=0, cows=0;
        unordered_map<char,int> freq;
        for(int i=0; i<n; i++) {
            freq[secret[i]]++;
        }
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                visited[i] = true;
                freq[secret[i]]--;
                bulls++;
            }
        }
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                if(freq[guess[i]] > 0) {
                    freq[guess[i]]--;
                    cows++; // present in secret.. with >0 frequency
                }
            }
        }
        string b=to_string(bulls);
        string c=to_string(cows);
        string ans = b + "A" + c + "B";
        return ans;
    }
};

int main() {
    string secret, guess;
    cin >> secret >> guess;
    Solution solve;
    string ans = solve.getHint(secret, guess);
    cout << ans << "\n";
    return 0;
}