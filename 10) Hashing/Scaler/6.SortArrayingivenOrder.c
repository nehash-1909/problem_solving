/*********************************************************************************************************************************
6. Sort Array in given Order

Given two arrays of integers A and B, Sort A in such a way that the relative order among the elements will be the same as those are in B.
For the elements not present in B, append them at last in sorted order.

Return the array A after sorting from the above method.

NOTE: Elements of B are unique.
*********************************************************************************************************************************/
// Solution

unordered_map<int,int> mp;
bool comp(int a,int b)
{
    bool find_a = (mp.find(a)!=mp.end());
    bool find_b = (mp.find(b)!=mp.end());

    if(find_a == true && find_b==false)
        return true; // a will come first
    else if(find_a == false && find_b==true)
        return false; // b will come first
    else if(find_a == false && find_b==false)
        return a<b; // whichever is smallest

    return mp[a] < mp[b];  
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    mp.clear();
    for(int i=0;i<B.size();i++)
    {
        mp[B[i]] = i;
    }
    sort(A.begin(),A.end(),comp);
    return A;
}
