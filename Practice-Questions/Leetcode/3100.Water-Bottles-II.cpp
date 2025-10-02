class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;

        while (numBottles >= numExchange) {
            totalDrunk += numExchange;  // drink these bottles
            numBottles -= numExchange;  // remove them
            numExchange++;              // cost increases
            numBottles++;               // get 1 new bottle
        }

        return totalDrunk + numBottles; // drink remaining bottles
    }
};
