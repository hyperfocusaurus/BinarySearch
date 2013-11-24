#ifndef BINSEARCH_H
#define BINSEARCH_H

#include <vector>
#include <array>

namespace BinarySearch
{
	template<class ElementType>
	class Searcher
	{
	public:
		int search(ElementType needle,std::vector<ElementType> haystack);
		template<int array_size>
		int search(ElementType needle,std::array<ElementType,array_size> haystack);
		int search(ElementType needle,ElementType haystack[],int array_size);
	private:
		int do_search(int start_index,int end_index, std::vector<ElementType> v);
		ElementType needle;
	};
	template<class ElementType>
	int Searcher<ElementType>::search(ElementType needle,std::vector<ElementType> haystack)
	{
		this->needle = needle;
		return do_search(0,haystack.size()-1,haystack);
	}
	template<class ElementType>
	template<int array_size>
	int Searcher<ElementType>::search(ElementType needle,std::array<ElementType,array_size> haystack)
	{
		this->needle = needle;
		std::vector<ElementType> v;
		v.assign(haystack.data(),haystack.data()+array_size);
		return do_search(0,array_size-1,v);
	}
	template<class ElementType>
	int Searcher<ElementType>::search(ElementType needle,ElementType haystack[],int array_size)
	{
		this->needle = needle;
		std::vector<ElementType> v;
		v.assign(haystack,haystack+array_size);
		return do_search(0,array_size-1,v);
	}
	template<class ElementType>
	int Searcher<ElementType>::do_search(int start_index,int end_index, std::vector<ElementType> v)
	{
		// start_index > end_index is an error
		if(start_index > end_index) return -1;
		if(start_index == end_index)
		{
			if(v[start_index] == needle) return start_index;
			else return -1;
		}
		// handle the case where we only have two elements to choose between
		if(end_index - start_index == 1)
		{
			if(v[start_index] == needle) return start_index;
			else if(v[end_index] == needle) return end_index;
			else return -1; // we only have two elements left and we know it's neither of them
		}

		// getting the midpoint of two integers can easily be done by adding them and dividing by two
		// NOTE: rounds down
		int pivot = (start_index + end_index) >> 1;

		// first, handle the case that we found it already by sheer luck
		if(v[pivot] == needle) return pivot;
		
		// next, recurse
		if(v[pivot] > needle)
		{
			return do_search(start_index,pivot,v);
		}
		else
		{
			return do_search(pivot,end_index,v);
		}

	}
}

#endif // BINSEARCH_H