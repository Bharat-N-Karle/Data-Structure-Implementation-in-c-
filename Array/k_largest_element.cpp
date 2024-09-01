/*Problem statement
    You are given an unsorted array containing ‘N’ integers.You need to find ‘K’ largest elements from the given array.Also,
    you need to return the elements in non - decreasing order.
Constraints:
    1 <= T <= 100
    1 <= N <= 10^4  
    1<= K <= N  
    -10^9 <= ARR[i] <= 10^9

    Where ‘T’ is the number of test cases, ‘N’ is the size of the array, ‘K’ is the number of elements you need to return as an answer and ARR[i] is the size of the array of elements.

    Time Limit: 1 sec
*/
#include <iostream>
#include <vector>
#include <queue>   // For priority_queue
#include <algorithm>  // For sort
using namespace std;

// Function to find K largest elements from the array
vector<int> findKLargestElements(const vector<int>& arr, int K) {
    // Min-heap to store the K largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Traverse the array
    for (int num : arr) {
        // Push the current element into the min-heap
        minHeap.push(num);

        // If the heap size exceeds K, remove the smallest element
        if (minHeap.size() > K) {
            minHeap.pop();
        }
    }

    // Extract elements from the heap and store them in a result vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Sort the result vector in non-decreasing order
    sort(result.begin(), result.end());

    return result;
}

int main() {
    int N, K;
    cout << "Enter the number of elements in the array: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> K;

    if (K > N) {
        cout << "K cannot be larger than the number of elements in the array." << endl;
        return 1;
    }

    // Find the K largest elements in non-decreasing order
    vector<int> result = findKLargestElements(arr, K);

    // Display the result
    cout << "The " << K << " largest elements in non-decreasing order are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
