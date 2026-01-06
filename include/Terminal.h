#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>

#define RESET "[0m"
#define RED "[31m"
#define GREEN "[32m"
#define YELLOW "[33m"
#define CYAN "[36m"
#define BOLD "[1m"

inline void clear() {
    std::cout << "[2J[H";
}

#endif