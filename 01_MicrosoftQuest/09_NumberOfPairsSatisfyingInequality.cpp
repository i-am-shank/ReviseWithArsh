#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
	ll count = 0;
	ll diff2;

	void merge(vector<ll>& arr, ll s, ll mid, ll e) {
		if(s >= e) {
			return;
		}
		ll n1=s, n2=mid+1;
		// Loop .. for counting pairs
		while(n1<=mid && n2<=e) {
			ll curr = arr[n2];
			if(arr[n1]-arr[n2] <= diff2) {
				count += ((e+1) - n2);
				// For (n1)th index, no. of pairings is above
				n1++;
			}
			else { // Move n2 .. to a bigger index
				n2++;
			}
		}
		// Loop for merging
		n1=s, n2=mid+1; // Reset values .. for merging
		ll k = s; // Index for placing elements in temp
		vector<ll> temp(e+1); // e --> max. index required
		while(n1<=mid && n2<=e) {
			if(arr[n1] <= arr[n2]) {
				temp[k++] = arr[n1++];
			}
			else {
				temp[k++] = arr[n2++];
			}
		}
		while(n1 <= mid) {
			temp[k++] = arr[n1++];
		}
		while(n2 <= e) {
			temp[k++] = arr[n2++];
		}
		for(ll i=s; i<=e; i++) {
			arr[i] = temp[i]; // storing back to original array
		}
		// Now, the array arr is sorted
		return;
	}

	void mergeSort(vector<ll>& arr, ll s, ll e) {
		if(s >= e) {
			return;
		}
		ll mid = s + ((e-s)/2);
		mergeSort(arr, s, mid);
		mergeSort(arr, mid+1, e);
		merge(arr, s, mid, e);
		return;
	}

public:
    ll numberOfPairs(vector<ll>& nums1, vector<ll>& nums2, ll diff) {
        ll n = nums1.size();
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) {
        	arr[i] = (nums1[i]-nums2[i]);
        }
        diff2 = diff;
        mergeSort(arr, 0, n-1);
        return count;
    }
};

int main() {
	Solution solve;
	ll n, diff;
	cin >> n >> diff;
	vector<ll> nums1(n), nums2(n);
	for(ll i=0; i<n; i++) {
		cin >> nums1[i];
	}
	for(ll i=0; i<n; i++) {
		cin >> nums2[i];
	}
	ll ans = solve.numberOfPairs(nums1, nums2, diff);
	cout << ans << "\n";
	return 0;
}