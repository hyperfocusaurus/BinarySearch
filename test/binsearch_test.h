#ifndef BINSEARCH_TEST_H
#define BINSEARCH_TEST_H

#include <vector>
#include "binsearch.h"

#define SMALL_SIZE 5
#define BIG_SIZE 1024

#define FIRST_ELEMENT 16
#define SECOND_ELEMENT 124

#define NOT_IN_SMALL 64
#define NOT_IN_BIG 65123
#define NOT_IN_TWO_ELEMENT 1209

class BinarySearchTest 
:public ::testing::Test 
{
protected:
	virtual void SetUp() {
		for(int i = 0; i < SMALL_SIZE; i++) {
			test_array_small[i] = i;
			test_vector_small.push_back(i);
			test_stdarray_small[i] = i;
		}
		for(int i = 0; i < BIG_SIZE; i++) {
			test_array_big[i] = i;
			test_vector_big.push_back(i);
			test_stdarray_big[i] = i;
		}
		test_array_two[0] = FIRST_ELEMENT;
		test_vector_two.push_back(FIRST_ELEMENT);
		test_stdarray_two[0] = FIRST_ELEMENT;
		test_array_two[1] = SECOND_ELEMENT;
		test_vector_two.push_back(SECOND_ELEMENT);
		test_stdarray_two[1] = SECOND_ELEMENT;
	}

	BinarySearch::Searcher<int> int_searcher;
	int test_array_zerolength[0];
	int test_array_two[2];
	int test_array_small[SMALL_SIZE];
	int test_array_big[BIG_SIZE];
	std::vector<int> test_vector_zerolength;
	std::vector<int> test_vector_two;
	std::vector<int> test_vector_small;
	std::vector<int> test_vector_big;
	std::array<int,0> test_stdarray_zerolength;
	std::array<int,2> test_stdarray_two;
	std::array<int,SMALL_SIZE> test_stdarray_small;
	std::array<int,BIG_SIZE> test_stdarray_big;
};

#endif