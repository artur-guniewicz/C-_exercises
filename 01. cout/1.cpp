/* Pierwszy program w C++, wypisywanie tekstu na ekran */

#include <cstdio>
#include <iostream>

// using namespace std; po wpisaniu tego nie trzeba pisać przedrostków std:: w kodzie

int main()
{
    printf("Pierwszy program w C++\n");
    std::cout << "Takie bajery\n";
    std::cout << "Czy ";
    std::cout << 3+4;
    std::cout << " jest większe od ";
    std::cout << "siedem\n";

    std::cout << "Można " << "zapisywać " << "też " <<"tak!\n\n";

    std::cout << "==============\n"
              << "= To proste! =\n"
              << "==============\n"
              << "\t A jak to zrobić?" << std::endl;
    std::cout << "Koniec!" << std::endl;

    return 0;
}