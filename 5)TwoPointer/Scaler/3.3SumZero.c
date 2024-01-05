/*********************************************************************************************************************************
3. 3 Sum Zero

Jerry is excited about an array that Tom gave him. The array A consists of N integers.

Tom challenges Jerry to find all such unique triplets a, b, c in A such that a + b = - c.

Note:
Elements in a triplet (a,b,c) must be in non-decreasing order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
*********************************************************************************************************************************/
// Solution
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    int n = A.size()-1;
    for(int i=0;i<A.size();i++)
    {
        int l = i+1;
        int r = n;
        while(l<r)
        {
            long long sum = A[l]+A[r];
            if(sum+A[i]==0)
            {
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[l]);
                temp.push_back(A[r]);
                if(std::find(ans.begin(), ans.end(), temp) == ans.end())
                    ans.push_back(temp);
                r--;
                l++;
            }
            else if(sum+A[i]>0)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return ans;
}
