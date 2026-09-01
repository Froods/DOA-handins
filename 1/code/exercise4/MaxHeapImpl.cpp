#include "MaxHeapImpl.h"

bool MaxHeapImpl::isEmpty() const
{
    return data.empty()
}

int MaxHeapImpl::size() const
{
    return data.size();
}

void MaxHeapImpl::insert(const int x)
{
    data.push_back(x);
}

const int MaxHeapImpl::findMax() const
{
    int max = *data.begin();
    for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}

int MaxHeapImpl::deleteMax()
{
    std::vector<int>::iterator maxIt = data.begin();
    int max = *data.begin();
    for (std::vector<int>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
            maxIt = it;
        }
    }
    data.erase(maxIt);
    return max;
}