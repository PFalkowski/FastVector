#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <vector>
#include "Arr.h"
#include "TimeMeasurment.h"

template<class T>
class Test
{
public:
	static void Allocation(size_t how_many = 100000000)
	{
		try
		{
			time_count timer;
			timer.start();

			Arr<T> t(how_many);
			timer.stop();

			std::cout << "Allocated memory = " << AsMemory(sizeof(T) * how_many) << std::endl;
			std::cout << timer;
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
	}
	static void Reserving(size_t how_many = 100000000)
	{
		try
		{
			time_count timer;
			timer.start();

			Arr<T> t;
			t.reserve(how_many);
			timer.stop();

			std::cout << "Allocated memory = " << AsMemory(sizeof(T) * how_many) << std::endl;
			std::cout << timer;
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
	}
	static void Adding(size_t how_many = 100000000)
	{
		try
		{
			time_count timer;
			timer.start();

			Arr<T> t(256);
			for (size_t i = 0; i < how_many; ++i)
				t.add(i);
			std::cout << "Allocated elem = " << how_many << std::endl;
			std::cout << "Allocated memory = " << AsMemory(sizeof(T) * how_many) << std::endl;
			timer.stop();
			std::cout << timer;
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
	}
	static void STDvectorAdding(size_t how_many = 100000000)
	{
		try
		{
			time_count timer;
			timer.start();

			std::vector<T> t;
			for (size_t i = 0; i < how_many; ++i)
				t.push_back(i);
			std::cout << "Allocated elem = " << how_many << std::endl;
			std::cout << "Allocated memory = " << AsMemory(sizeof(T) * how_many) << std::endl;
			timer.stop();
			std::cout << timer;
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
	}
};
#endif//TEST_H_INCLUDED