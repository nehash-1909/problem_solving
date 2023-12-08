/*********************************************************************************************************************************
2. Add Binary Strings

Given two binary strings A and B. Return their sum (also a binary string).
*********************************************************************************************************************************/

// Solution

string Solution::addBinary(string A, string B) {
    // we add bits from the rightmost bit to the leftmost bit
    int n = A.length();
    int m = B.length();
    string ans = "";
    int carry = 0;
    int i=n-1,j=m-1;
    int sum = 0;

    while(i>=0 || j>=0 || carry)
    {
        sum = carry;
        if(i>=0)
        {
            sum += (A[i]-'0');
        }
        if(j>=0)
        {
            sum += (B[j]-'0');
        }
        ans.push_back((char)('0' + sum % 2));
        carry = sum/2;
        i--;
        j--;
    }

    reverse(ans.begin(),ans.end());

    return ans;


}

