#include "PmergeMe_deque.hpp"
#include <iomanip>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid arguments" << std::endl;
        return 1;
    }

    PmergeMe p;

    if (!p.storeInt(av[1]))
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }

    try
    {
        std::deque<int> dq = p.getDeque();

        std::cout << "Before: ";

        for (size_t i = 0; i < dq.size(); ++i)
            std::cout << dq[i] << " ";

        std::cout << std::endl;



        clock_t start = clock();

        std::deque<int> result = p.fordJohnson(dq);

        clock_t end = clock();



        double time_us =
        (double)(end - start) * 1000000 / CLOCKS_PER_SEC;



        std::cout << "After:  ";

        for (size_t i = 0; i < result.size(); ++i)
            std::cout << result[i] << " ";

        std::cout << std::endl;



        std::cout << std::fixed
                  << std::setprecision(5);

        std::cout
        << "Time to process a range of "
        << result.size()
        << " elements with std::deque : "
        << time_us
        << " us"
        << std::endl;
    }

    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}