class ProductOfNumbers
{
    vector < long int > pr;
    public:
    ProductOfNumbers()
    {
        pr.push_back(1);
    }

        void add(int num)
        {
            if (num == 0)
            {
                pr.clear();
                pr.push_back(1);
                return;
            }
            else if (pr.empty())
            {
                pr.push_back(num);
                return;
            }
            pr.push_back(pr.back() *num);
        }

    int getProduct(int k)
    {
        if (pr.empty())
            return 0;

        int n = pr.size() - 1;
        if (n - k >= 0)
            return pr[n] / pr[n - k];
        else
            return 0;
    }
};

/**
 *Your ProductOfNumbers object will be instantiated and called as such:
 *ProductOfNumbers* obj = new ProductOfNumbers();
 *obj->add(num);
 *int param_2 = obj->getProduct(k);
 */