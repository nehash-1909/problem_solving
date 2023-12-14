/*********************************************************************************************************************************
16. Number Of Open Doors
Given an integer A, which denotes the number of doors in a row numbered 1 to A. All the doors are closed initially.

A person moves to and fro, changing the states of the doors as follows: the person opens a door that is already closed and closes a door that is already opened.

In the first go, he/she alters the states of doors numbered 1, 2, 3, … , A.
In the second go, he/she alters the states of doors numbered 2, 4, 6 ….
In the third go, he/she alters the states of doors numbered 3, 6, 9 …
This continues till the A'th go in, which you alter the state of the door numbered A.

Find and return the number of open doors at the end of the procedure.
*********************************************************************************************************************************/

// Solution

int Solution::solve(int A) {
    /*
    If the number of factors is even, then the door will be closed; else, it will be open.
    
    only the number which is perfect square has an odd number of factors.

    the number of perfect squares between 1 and A, and that will be sqrt(A).
    */
    return sqrt(A);
}
