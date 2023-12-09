/*********************************************************************************************************************************
8. Reverse Bits
Reverse the bits of an 32 bit unsigned integer A.
*********************************************************************************************************************************/

// Solution

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    int reverse_number=0;
    int counter=31;
    while(A)
    {
        reverse_number+=(A&1)<<counter;
        counter-=1;
        A=A>>1;
    }
    return reverse_number;
}
