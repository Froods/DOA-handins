#include <vector>
#include <iostream>

//Counting sort function written after the Wikipedia template
std::vector<int> counting_sort(std::vector<int> A, int k)
{
    std::vector<int> count(k + 1, 0);
    std::vector<int> output(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        int j = A[i];
        count[j] = count[j] + 1;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; i--)
    {
        int j = A[i];
        count[j] = count[j] - 1;
        output[count[j]] = A[i];
    }
    return output;
}

//Testing in main
int main()
{
    std::vector<int> test{0,2,5,5,7,2,0}; //Test vector

    std::vector<int> after_count = counting_sort(test, test.size()); //Vector after running function

    std::cout << "Before counting sort function: \n";

    for (auto x : test) {
        std::cout << x << ", ";
    }

    std::cout << "\nAfter counting sort function: \n";

    for (auto x : after_count) {
        std::cout << x << ", ";
    }



    return 0;
}