#pragma once

#include <iostream>

template <typename T>
void iter(T* array, size_t size, void (*f)(T));
