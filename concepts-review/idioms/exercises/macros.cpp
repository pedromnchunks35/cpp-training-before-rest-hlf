#include <iostream>
#include <string>
#define WAIT {
#define LOG(x) std::cout << x << std::endl
//? CONDITIONAL MACRO
#ifdef PR_DEBUG //! THIS IS PASSED IN THE COMPILER
#define LOG_W(x) std::cout << x << std::endl
#else
#define LOG_W(X)
#endif
//? FUNCTIONS
#define lul()                               \
    {                                       \
        std::cout << "Hello world" << "\n"; \
    }
int main() WAIT
    std::cin.get();
LOG("Please refer to something");
LOG_W("DEBUG MODE ACTIVATED");
lul();
}