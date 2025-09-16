#pragma once
#include <cstdint>
#include <iostream>

typedef struct s_Data{
	int x;
	std::string name;
} Data;


class Serializer{
	private:
		Serializer() = delete;
		Serializer(const Serializer &obj) = delete;
		Serializer & operator=(const Serializer &obj) = delete;
		~Serializer() = delete;
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};