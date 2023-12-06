/*********************************************************************************************************************************
10. Pairs of Songs With Total Durations Divisible by 60

You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<long long> rem_freq(60,0);

        for(int i=0;i<time.size();i++)
        {
            int rem = time[i]%60;
            rem_freq[rem]++;
        }

        res += (rem_freq[0]*(rem_freq[0]-1))/2;
        res += (rem_freq[30]*(rem_freq[30]-1))/2;

        for(int i=1;i<=29;i++)
        {
            res += rem_freq[i] * rem_freq[60-i];
        }
        return res;
    }
};
