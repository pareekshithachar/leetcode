class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deghs = 360/ (12*3600);
        double degms = 360/ (3600);
        
        double degh = deghs * (hour);
        double minuteangle = 6 * minutes;
        double hourangle = minuteangle/12;
        hourangle += 30*(hour%12);
        
       double ans = min(abs(hourangle - minuteangle),360 - abs(hourangle-minuteangle));
        return ans;
    }
};


             