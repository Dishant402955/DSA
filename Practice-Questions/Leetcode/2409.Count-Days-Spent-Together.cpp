class Solution {
public:
    int getNumber(string& s) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = stoi(s.substr(0, 2));
        int date = stoi(s.substr(3, 2));

        for (int i = 0; i < month - 1; i++) {
            date += days[i];
        }

        return date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int startA = getNumber(arriveAlice);
        int startB = getNumber(arriveBob);
        int endA = getNumber(leaveAlice);
        int endB = getNumber(leaveBob);

        

        int l = max(startA,startB);
        int r = min(endA,endB);

        int ans = r-l+1;

        return max(0,ans);

    }
};
