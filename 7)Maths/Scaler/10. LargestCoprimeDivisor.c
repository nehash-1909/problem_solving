/*********************************************************************************************************************************
10. Largest Coprime Divisor
You are given two positive numbers A and B . You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
*********************************************************************************************************************************/

// Solution

int Solution::cpFact(int A, int B) {
    /*
    let x be the ans, so A = KX (as it is a factor)
    and B%X = 0
    */
    while(__gcd(A,B)!=1)
    {
        // gcd(a,b)   ==> common divisors of a & b
        // A/gcd(a,b) ==> factor a not in b
        // 30 = 1, 2, 3, 5, 6, 15, 30
        // 12 = 1, 2, 3, 4, 6, 12
        A = A/__gcd(A,B);
    }
    return A;
}

