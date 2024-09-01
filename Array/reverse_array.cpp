#include <iostream>
#include <vector>
using namespace std;

// Function to reverse the array
void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Swap the elements at indices left and right
        swap(arr[left], arr[right]);
        // Move the pointers towards the center
        left++;
        right--;
    }
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
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

    cout << "Original array: ";
    displayArray(arr);

    // Reverse the array
    reverseArray(arr);

    cout << "Reversed array: ";
    displayArray(arr);

    return 0;
}
