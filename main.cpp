#define OPTION 0

#if OPTION == 0
#include "Comparator.h"
#include "Comparator_strings.h"


namespace fs = std::filesystem;

int RULE()
{
    if (sizeof(fs::path) > sizeof(std::string)) {
        return comparator_string::my_program_main();
    }
    else {
        return comparator_filesystem::my_program_main();
    }
}

#elif OPTION == 1
#include <iostream>
int RULE()
{
    std::cout << "RULE" << std::endl;
    return 0;
}

#endif

int main() { return RULE(); }