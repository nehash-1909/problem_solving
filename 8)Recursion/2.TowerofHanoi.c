/*********************************************************************************************************************************
2. Tower of Hanoi
In the classic problem of the Towers of Hanoi, you have 3 towers numbered from 1 to 3 (left to right) and A disks numbered from 1 to A (top to bottom) of different sizes which can slide onto any tower.
The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).
You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one tower onto another tower.
A disk cannot be placed on top of a smaller disk.
You have to find the solution to the Tower of Hanoi problem.
You have to return a 2D array of dimensions M x 3, where M is the minimum number of moves needed to solve the problem.
In each row, there should be 3 integers (disk, start, end), where:

disk - number of the disk being moved
start - number of the tower from which the disk is being moved
end - number of the tower to which the disk is being moved
*********************************************************************************************************************************/

// Solution

void toi(int s, int d, int a, int N,vector<vector<int> > &ans)
{
    /*
    The minimum number of moves to solve the problem with A disks is 2A - 1.
    We can find the optimal solution using recursion easily.

    We derive the solution intuitevly from 2 disks.
    For 2 disks, the move sequence is:
    [1, 1, 2]
    [2, 1, 3]
    [1, 2, 3]
    */
    
    if(N==0)
    {
        return;
    }
    toi(s, a, d, N-1,ans);
    vector<int> temp;
    temp.push_back(N);
    temp.push_back(s);
    temp.push_back(d);
    ans.push_back(temp);
    toi(a, d, s, N-1,ans);
}
vector<vector<int> > Solution::towerOfHanoi(int A) {
    vector<vector<int>> ans;
    toi(1, 3, 2, A,ans);
    return ans;
}
