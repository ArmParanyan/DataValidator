#include <iostream>

#include "../header/DataValidator.h"

int main()
{
    DataValidator obj;
    std::string url = "https://www.youtube.com/watch?v=DuTnCf016MQ";
    std::cout << std::boolalpha << obj.is_valid_url(url);
}