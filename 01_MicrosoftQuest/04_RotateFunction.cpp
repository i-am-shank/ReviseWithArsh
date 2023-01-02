#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> f(n, 0); // function to be calculated
        for(int i=0; i<n; i++) {
        	sum += nums[i];
        	f[0] += (i * nums[i]);
        }
        int maxVal = f[0];
        for(int i=1; i<n; i++) {
        	// calculate f[i] from f[i-1]
        	// get a calculative expression.. from dry-run on test-case
        	f[i] = f[i-1] + (sum - (n*nums[(n-1)-(i-1)]));
        	maxVal = max(maxVal, f[i]);
        }
        // for(int i=0; i<n; i++) {
        // 	cout << f[i] << " ";
        // }
        // cout << "\n";
        return maxVal;
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
	int ans = solve.maxRotateFunction(nums);
	cout << ans << "\n";
	return 0;
}