#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayWithGivenSum(int arr[], int n, int k) {
	unordered_map<int, int> m;
	int pre = 0, len = 0;

	for (int i = 0; i < n; i++) {
		pre += arr[i];

		if (pre == k)
		{
			len = max(len, i + 1);
		}


		if (m.find(pre) != m.end()) // if that element is already present
		{
			len = max(len, i - m[pre]);
		}

		else // first occurence of the element
		{
			m[pre] = i;
		}
	}

	return len;

}

int main() {
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int k;
	cin >> k;
	cout << longestSubarrayWithGivenSum(arr, n, k) << " ";


}