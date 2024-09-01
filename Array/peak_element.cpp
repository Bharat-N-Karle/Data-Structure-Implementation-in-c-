/*Given an 0-indexed array of integers arr[] of size n, 
find its peak element and return it's index. 
An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist).
Note: The output will be 1 if the index returned by your function is correct; otherwise, it will be 0.
Your Task:
You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size n as input parameters and returns the index of the peak element.

Expected Time Complexity: O( log(n) ).
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find the peak element index in the array
int findPeakElement(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is less than its next element, then the peak is on the right side
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            // If mid element is greater than or equal to its next element, then the peak is on the left side
            right = mid;
        }
    }

    // Left or right will eventually point to the peak element
    return left;
}

// Function to verify if the index is a peak element
bool isPeakCorrect(const vector<int>& arr, int index) {
    int n = arr.size();
    // Check if the found index is within the valid range
    if (index < 0 || index >= n) return false;

    // Check if arr[index] is greater than or equal to its neighbors
    if ((index == 0 || arr[index] >= arr[index - 1]) &&
        (index == n - 1 || arr[index] >= arr[index + 1])) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Find the peak element index
    int peakIndex = findPeakElement(arr);

    // Verify if the peak element index is correct
    if (isPeakCorrect(arr, peakIndex)) {
        cout << "1" << endl; // Output is 1 if the index is correct
    } else {
        cout << "0" << endl; // Output is 0 if the index is not correct
    }

    return 0;
}

