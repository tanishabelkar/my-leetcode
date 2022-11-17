class Solution
{
    public:
        int calcOverlap(int a1, int a2, int b1, int b2)
        {
            int overlap = min(a2, b2) - max(a1, b1);
            return overlap > 0 ? overlap : 0;
        }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int a = (ax2 - ax1) *(ay2 - ay1), b = (bx2 - bx1) *(by2 - by1);
        int overlap = calcOverlap(ax1, ax2, bx1, bx2) *calcOverlap(ay1, ay2, by1, by2);

        return a + b - overlap;
    }
};