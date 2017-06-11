#ifndef __BRUCEXIALIBRARY_COM_C_H_
#define __BRUCEXIALIBRARY_COM_C_H_

#include <iostream>
#include <vector>

template <typename T>
inline void PrintVector(const std::vector<T> &vec)
{
    for (auto i : vec) {
        std::cout << i << " ";
	}
	std::cout << std::endl;
}



#endif
