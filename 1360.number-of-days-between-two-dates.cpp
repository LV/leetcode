// @leet start
class Solution {
public:
    int daysInYear(int year) {
        if(year % 4 == 0 && year != 2100) return 365;
        return 366;
    }

    int daysInMonth(int year, int month) {
        switch(month) {
            case 1:
                return 31;
            case 2:
                return daysInYear(year) == 365 ? 29 : 28;
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
                return 31;
            case 12:
                return 31;
            default:
                return -1;
        }
    }

    int daysUntilEndOfYear(int year, int month, int day) {
        int days = 0;
        for(int i=month+1; i<=12; i++) days += daysInMonth(year, i);
        days += daysInMonth(year, month) - day + 1; // Dec 31 should be 1 day
        return days;
    }

    int daysFromBeginningOfYear(int year, int month, int day) {
        int days = 0;
        for(int i=1; i<month; i++) days += daysInMonth(year, i);
        days += day-1; // Jan 1 should be 0 days
        return days;
    }

    int daysBetweenYears(int yearA, int yearB) {
        // Assumes yearA < yearB
        // Get the number of days from Jan 1 of YearA until Jan 1 of yearB
        if(yearA == yearB) return 0;
        int days = 0;
        for(int i=yearA; i<yearB; i++) days += daysInYear(i);
        return days;
    }

    int daysBetweenDates(string date1, string date2) {
        int date1_Year = stoi(date1.substr(0, 4));
        int date2_Year = stoi(date2.substr(0, 4));
        int date1_Month = stoi(date1.substr(5, 2));
        int date2_Month = stoi(date2.substr(5, 2));
        int date1_Day = stoi(date1.substr(8, 2));
        int date2_Day = stoi(date2.substr(8, 2));

        bool smallestIsFirst;

        if(date1_Year < date2_Year) smallestIsFirst = true;
        else if(date2_Year < date1_Year) smallestIsFirst = false;
        else {
            if(date1_Month < date2_Month) smallestIsFirst = true;
            else if(date2_Month < date1_Month) smallestIsFirst = false;
            else {
                if(date1_Day < date2_Day) smallestIsFirst = true;
                else if(date2_Day < date1_Day) smallestIsFirst = false;
                else return 0;
            }
        }

        int smallYear;
        int smallMonth;
        int smallDay;
        int largeYear;
        int largeMonth;
        int largeDay;

        if(smallestIsFirst) {
            smallYear = date1_Year;
            smallMonth = date1_Month;
            smallDay = date1_Day;
            largeYear = date2_Year;
            largeMonth = date2_Month;
            largeDay = date2_Day;
        } else {
            smallYear = date2_Year;
            smallMonth = date2_Month;
            smallDay = date2_Day;
            largeYear = date1_Year;
            largeMonth = date1_Month;
            largeDay = date1_Day;
        }

        int numOfDays = 0;
        if(largeYear - smallYear >= 1) {
            numOfDays += daysUntilEndOfYear(smallYear, smallMonth, smallDay);
            numOfDays += daysBetweenYears(smallYear+1, largeYear);
            numOfDays += daysFromBeginningOfYear(largeYear, largeMonth, largeDay);
        } else {
            if(smallMonth < largeMonth) {
                numOfDays += daysInMonth(smallYear, smallMonth) - smallDay + 1;
                for(int i=smallMonth+1; i<largeMonth; i++) numOfDays += daysInMonth(largeYear, i);
                numOfDays += largeDay - 1;
            } else {
                return largeDay - smallDay;
            }
        }

        return numOfDays;
    }
};
// @leet end
