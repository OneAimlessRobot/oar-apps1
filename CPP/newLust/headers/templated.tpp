#include "templated.hpp"
template <typename T>

T getFilteredInput(T value, std::string query)
{
    while ((std::cout << query << std::endl) && !(std::cin >> (value)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}
