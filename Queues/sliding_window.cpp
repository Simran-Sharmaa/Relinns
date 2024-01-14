#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Function to find the maximum element in a sliding window
vector<int> maxSlidingWindow(const vector<int> &nums, int k)
{
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++)
    {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        // Remove elements that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // Add the current element to the deque
        dq.push_back(i);

        // Add the maximum element of the current window to the result
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    int k;
    int n;
    cout << "Enter the size of arr: ";
    cin >> n;
    cout << "Enter the value of window: ";
    cin >> k;

    vector<int> nums(n);
    cout << "Enter the elements in arr" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Input element no." << i + 1 << ": ";
        cin >> nums[i];
    }

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum elements in sliding windows: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
