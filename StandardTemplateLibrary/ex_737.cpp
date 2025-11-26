#include <iostream>
#include <algorithm>
#include <cstring>

int arr[] = {45, 2, 22, -17, -30, 25, 55};

int main() {

    // -- sort
    std::sort(arr, arr + 7);

    for (int i = 0; i < 7; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // -- search (integers)

    int source[] = {11, 44, 33, 11, 22, 33, 11, 22, 44};
    int pattern[] = {11, 22, 44};

    int* ptr = std::search(source, source + 9, pattern, pattern + 3);

    if (ptr == source + 9) {
        std::cout << "no match found" << std::endl;
    } else {
        std::cout << "match at index: " << ptr - source << std::endl;
    }

    // -- search (C-strings)

    char str[] = "Hello World!";
    char substr[] = "World";


    // .. read beyond the last element
    char* ptr2 = std::search(str, str + 12, substr, substr + 5);

    if (ptr2 == str + 12) {
        std::cout << "no matching substring found" << std::endl;
    } else {
        std::cout << "substring match starts at: " << ptr2 - str << std::endl;
    }

    return 0;
}

