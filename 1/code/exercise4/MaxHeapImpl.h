#include <vector>
#include "MaxHeap.h"

class MaxHeapImpl : public MaxHeap
{
public:
    // Overriding virtual functions
    bool isEmpty() const override;
    int size() override;
    void insert(const int x) override;
    const int findMax() const override;
    int deleteMax() override;

private:
    // Vector to store data
    std::vector<int> data;
};
