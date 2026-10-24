
class Solution {
private:
    int convert(string date) {
         int days[] = {
    0,    // before January
    31,   // before February
    59,   // before March
    90,   // before April
    120,  // before May
    151,  // before June
    181,  // before July
    212,  // before August
    243,  // before September
    273,  // before October
    304,  // before November
    334   // before December
};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return days[month - 1] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int aliceStart = convert(arriveAlice);
        int aliceEnd = convert(leaveAlice);

        int bobStart = convert(arriveBob);
        int bobEnd = convert(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if (start > end)
            return 0;

        return end - start + 1;
    }
};