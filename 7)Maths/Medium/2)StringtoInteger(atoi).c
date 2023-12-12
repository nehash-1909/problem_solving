/*********************************************************************************************************************************
2. String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int sign = 0;
        int j = 0; 
        while((j<s.length())&&(s[j]==' '))
        {
            j++;
        }
        if(s[j]=='-')
        {
            sign = 1;
            j++;
        }
        else if(s[j]=='+')
        {
            sign = 0;
            j++;
        }
        for(int i=j;i<s.length();i++)
        {
            if(s[i]<'0' || s[i]>'9')
            {
                break;
            }
            ans = ans*10 + (s[i]-'0');
            if(sign==1 && -1*ans<INT_MIN)
            {
                return INT_MIN;
            }
            if(sign==0 && 1*ans>INT_MAX)
            {
                return INT_MAX;
            }

        }
        if(sign == 1)
        {
            return ans*-1;
        }
        return ans;
        
    }
};
