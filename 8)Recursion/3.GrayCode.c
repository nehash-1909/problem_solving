/*********************************************************************************************************************************
3. Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer A representing the total number of bits in the code, print the sequence of gray code.

A gray code sequence must begin with 0.
*********************************************************************************************************************************/

// Solution

vector<string> gengrayCode(int A) {
    if(A==1)
    {
        return {"0","1"};
    }
    /*
    for A = 2 the gray code sequence is:
        00 - 0
        01 - 1
        11 - 3
        10 - 2

    A = 1 ==> temp = {0,1}

    now for A =2 there will be 4 values,
    add 0 in front of temp i.e., 0+0,0+1 ==> {00,01}
    add 1 in front of reverse temp array i.e., 1+1,1+0 ==> {11,10}
    as not reversing will give 10, 11
    which means there will be 2 bit change from 01 --> 10

    */
    vector<string> temp = gengrayCode(A-1);
    vector<string> ans;
    for(int i=0;i<temp.size();i++)
    {
        ans.push_back("0"+temp[i]);
    }

    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back("1"+temp[i]);
    }

    return ans;

}
vector<int> Solution::grayCode(int A) {
    vector<string> tempAns =  gengrayCode(A);
    vector<int> ans;

    for(int i=0;i<tempAns.size();i++)
    {
        ans.push_back(stoi(tempAns[i],0,2));
    }

    return ans;
}
