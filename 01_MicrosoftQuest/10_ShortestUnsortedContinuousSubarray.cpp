#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxEle=INT_MIN, s=-1, e=-1, maxIdx=-1;
        int minEle=INT_MAX;
        for(int i=0; i<n; i++) {
        	if(maxEle > nums[i]) {
        		// A contradiction to sorted array
        		minEle = min(minEle, nums[i]);
        		if(s == -1) { // Still hasn't started
        			s=maxIdx, e=i;
        		}
        		else {
        			e = i; // Ending is here (till here needs a sort)
        		}
        	}
        	else if(maxEle < nums[i]) { // Update maxEle
        		maxEle = nums[i];
        		maxIdx = i;
        	}
        }
        // cout << s << " " << e << "\n";
        if(s == -1) {
        	return 0;
        }
        int minStart=s;
        for(int i=s-1; i>=0; i--) {
        	if(nums[i] > minEle) {
        		minStart = i;
        	}
        }
        return (e-minStart+1);
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
	int ans = solve.findUnsortedSubarray(nums);
	cout << ans << "\n";
	return 0;
}