/*********************************************************************************************************************************
1. Peak Index in a Mountain Array

An array arr is a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
*********************************************************************************************************************************/

//Solution

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int l = 0;
        int r = arr.size()-1;

        while(l<=r)
        {
            int m = (l+r)/2;
            //cout<<" mid is "<<arr[m]<<" ";
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1])
            {
                return m;
            }
            else if(arr[m]>arr[m-1])
            {
                l = m;
            }
            else if(arr[m]>arr[m+1])
            {
                r = m;
            }
        }
        return 0;
    }
};
