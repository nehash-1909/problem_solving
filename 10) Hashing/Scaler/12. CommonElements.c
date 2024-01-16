/*********************************************************************************************************************************
12. Common Elements

Given two integer arrays, A and B of size N and M, respectively. Your task is to find all the common elements in both the array.

NOTE: Each element in the result should appear as many times as it appears in both arrays.
The result can be in any order
*********************************************************************************************************************************/

// Solution

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    unordered_map<int,int> map_a;
    vector<int> ans;

    for(auto i:A)
    {
        map_a[i]++;
    }
    for(auto i:B)
    {
        if(map_a[i]>0){
            ans.push_back(i);
        }
        map_a[i]--; 
    }
    return ans;
}

