// @leet start
class Solution {
public:
    int leapCalc(int year) {
        if(year == 1700 || year == 1800 || year == 1900 || year == 2100) return 28;
        return year % 4 == 0 ? 29 : 28;
    }

    int numberOfDays(int year, int month) {
        switch(month) {
            case 1:
                return 31;
            case 2:
                return leapCalc(year);
            case 3:
                return 31;
            case 4:
                return 30;
            case 5:
                return 31;
            case 6:
                return 30;
            case 7:
                return 31;
            case 8:
                return 31;
            case 9:
                return 30;
            case 10:
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
            default:
                return -1;
        }
    }
};
// @leet end
