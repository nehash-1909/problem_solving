/*********************************************************************************************************************************
7. Colorful Number

Given a number A, find if it is COLORFUL number or not.

If number A is a COLORFUL number return 1 else, return 0.

What is a COLORFUL Number:

A number can be broken into different consecutive sequence of digits. 
The number 3245 can be broken into sequences like 3, 2, 4, 5, 32, 24, 45, 324, 245 and 3245. 
This number is a COLORFUL number, since the product of every consecutive sequence of digits is different
*********************************************************************************************************************************/
// Solution

int Solution::colorful(int A) {
    string num = to_string(A);
    unordered_map<long,int> map;
    for(int i=0;i<num.length();i++)
    {
        long temp = 1;
        string t;
        for(int j=i;j<num.length();j++)
        {
            t += num[j];
            temp *= int(num[j]-48);
            map[temp]++;
        }
    }
    for(auto i:map)
    {
        if(i.second>1)
        {
            return false;
        }
    }
    return true;
}
