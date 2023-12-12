/*********************************************************************************************************************************
3. Angle Between Hands of a Clock

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    double angleClock(int hour, int minutes) {
        /*
            12 hr = 360 degree
            1 hr = 360/12 = 30 degree
            60 min = 360 degree
            1 min = 360/60 = 6 degree

            totalHour = (12 + 30/60)*30 = 375
            totalMin = 30*6 = 180

        */

        double totalHour = ((double)hour + ((double)minutes/60))*30;
        double totalMin  = (minutes)*6;
        double totalDegree = abs(totalHour-totalMin);

        if(totalDegree > 180)
        {
            return 360-totalDegree;
        }
        return totalDegree;
        
    }
};
