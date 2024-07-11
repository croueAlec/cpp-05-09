#pragma once
#include <iostream>

#include <stdint.h>

struct Data;

class Serializer {
  public:
	virtual ~Serializer() = 0;

	static uintptr_t serialize(Data* ptr);

	static Data* deserialize(uintptr_t raw);
};
