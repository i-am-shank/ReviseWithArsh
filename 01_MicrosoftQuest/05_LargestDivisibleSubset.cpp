#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1); // Initially all subsets have length 1
        unordered_map<int,int> mapPrev; // Previous divisor.. in subset
        int maxLen=1; // initially
        int maxEnd=0; // Ending index of maxLen-subset
        for(int i=0; i<n; i++) {
        	for(int j=0; j<i; j++) {
        		if((nums[i]%nums[j]==0) && (dp[i]<1+dp[j])) {
        			// Divisible.. & a better answer possible
        			dp[i] = 1+dp[j];
        			mapPrev[nums[i]] = nums[j];
        		}
        	}
        	// dp[i] has been calculated
        	if(dp[i] > maxLen) {
        		maxLen = dp[i];
        		maxEnd = i;
        	}
        }
        vector<int> ans;
        int currEle = nums[maxEnd]; // Current-element (starting from that at maxEnd-index)
        ans.push_back(currEle);
        while(mapPrev.find(currEle) != mapPrev.end()) {
        	ans.push_back(mapPrev[currEle]);
        	currEle = mapPrev[currEle]; // next iteration
        	// Keep going to previous divisor
        }
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
		cin >> nums[i];
	}
	Solution solve;
	vector<int> ans = solve.largestDivisibleSubset(nums);
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}