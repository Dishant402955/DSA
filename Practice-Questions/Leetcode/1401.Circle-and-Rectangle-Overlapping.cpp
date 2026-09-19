class Solution {
public:

    bool checkOverlap(int r, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // 1. Traverse the bottom edge
        int x = x1;

        while (x < x2) {
            int a = xCenter - x;
            int b = yCenter - y1;

            if (a * a + b * b - r * r <= 0)
                return true;

            x++;
        }

        // 2. Traverse the right edge
        int y = y1;

        while (y < y2) {
            int a = xCenter - x2;
            int b = yCenter - y;

            if (a * a + b * b - r * r <= 0)
                return true;

            y++;
        }

        // 3. Traverse the top edge
        x = x2;

        while (x > x1) {
            int a = xCenter - x;
            int b = yCenter - y2;

            if (a * a + b * b - r * r <= 0)
                return true;

            x--;
        }

        // 4. Traverse the left edge
        y = y2;

        while (y > y1) {
            int a = xCenter - x1;
            int b = yCenter - y;

            if (a * a + b * b - r * r <= 0)
                return true;

            y--;
        }

        // 5. Check if the circle is completely inside the rectangle
        if (xCenter > x1 && xCenter < x2 &&
            yCenter > y1 && yCenter < y2) {
            return true;
        }

        return false;
    }
};
