#include "PmergeMe_vector.hpp"
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
        std::vector<int> vct = p.getVector();

        std::cout << "Before: ";

        for (size_t i = 0; i < vct.size(); ++i)
            std::cout << vct[i] << " ";

        std::cout << std::endl;



        clock_t start = clock();

        std::vector<int> result = p.fordJohnson(vct);

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
        << " elements with std::vector : "
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