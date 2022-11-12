class MedianFinder
{
    priority_queue<int, vector < int>, greater < int>> minheap;
    priority_queue<int> maxheap;
    public:
        MedianFinder() {}

    void addNum(int num)
    {
        if (maxheap.empty())
            maxheap.push(num);
        else
        {
            if (maxheap.size() > minheap.size())
            {
                if (num < maxheap.top())
                {
                    int a = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(a);
                }
                else minheap.push(num);
            }
            else
            {
                if (num > minheap.top())
                {
                    int a = minheap.top();
                    minheap.pop();
                    minheap.push(num);
                    maxheap.push(a);
                }
                else maxheap.push(num);
            }
        }
    }

    double findMedian()
    {
        if (minheap.size() == maxheap.size())
            return (minheap.top() + maxheap.top()) / 2.0;
        return maxheap.top();
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */