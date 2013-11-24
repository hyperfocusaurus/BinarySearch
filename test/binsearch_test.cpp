#include <limits.h>
#include "gtest/gtest.h"
#include "binsearch_test.h"

TEST_F(BinarySearchTest, EmptyHaystacks)
{
	EXPECT_EQ(-1,int_searcher.search(3,test_array_zerolength,0));
	EXPECT_EQ(-1,int_searcher.search(3,test_vector_zerolength));
	EXPECT_EQ(-1,int_searcher.search<0>(3,test_stdarray_zerolength));
}

TEST_F(BinarySearchTest, SmallHaystacksBadElement)
{
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_SMALL,test_array_small,SMALL_SIZE));
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_SMALL,test_vector_small));
	EXPECT_EQ(-1,int_searcher.search<SMALL_SIZE>(NOT_IN_SMALL,test_stdarray_small));
}

TEST_F(BinarySearchTest, LargeHaystacksBadElement)
{
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_BIG,test_array_big,BIG_SIZE));
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_BIG,test_vector_big));
	EXPECT_EQ(-1,int_searcher.search<BIG_SIZE>(NOT_IN_BIG,test_stdarray_big));
}

TEST_F(BinarySearchTest, SmallHaystacksGoodElement)
{
	EXPECT_EQ(3,int_searcher.search(3,test_array_small,SMALL_SIZE));
	EXPECT_EQ(3,int_searcher.search(3,test_vector_small));
	EXPECT_EQ(3,int_searcher.search<SMALL_SIZE>(3,test_stdarray_small));
}

TEST_F(BinarySearchTest, LargeHaystacksGoodElement)
{
	EXPECT_EQ(BIG_SIZE/2,int_searcher.search(BIG_SIZE/2,test_array_big,BIG_SIZE));
	EXPECT_EQ(BIG_SIZE/2,int_searcher.search(BIG_SIZE/2,test_vector_big));
	EXPECT_EQ(BIG_SIZE/2,int_searcher.search<BIG_SIZE>(BIG_SIZE/2,test_stdarray_big));
}

TEST_F(BinarySearchTest, TwoElementsFirstElement)
{
	EXPECT_EQ(0,int_searcher.search(FIRST_ELEMENT,test_array_two,2));
	EXPECT_EQ(0,int_searcher.search(FIRST_ELEMENT,test_vector_two));
	EXPECT_EQ(0,int_searcher.search<2>(FIRST_ELEMENT,test_stdarray_two));
}

TEST_F(BinarySearchTest, TwoElementsSecondElement)
{
	EXPECT_EQ(1,int_searcher.search(SECOND_ELEMENT,test_array_two,2));
	EXPECT_EQ(1,int_searcher.search(SECOND_ELEMENT,test_vector_two));
	EXPECT_EQ(1,int_searcher.search<2>(SECOND_ELEMENT,test_stdarray_two));
}

TEST_F(BinarySearchTest, TwoElementsFail)
{
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_TWO_ELEMENT,test_array_two,2));
	EXPECT_EQ(-1,int_searcher.search(NOT_IN_TWO_ELEMENT,test_vector_two));
	EXPECT_EQ(-1,int_searcher.search<2>(NOT_IN_TWO_ELEMENT,test_stdarray_two));
}