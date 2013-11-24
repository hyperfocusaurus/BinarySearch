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
		if(start_index > end_index) return -1;
		if(start_index == end_index)
		{
			if(needle == v[start_index]) return start_index;
			else return -1;
		}
		else
		{
			int pivot = start_index + ((end_index - start_index)>>1);
			// odd-sized array handling
			if(pivot - start_index == 1)
			{
				return do_search(pivot,pivot,v);
			}
			else if(needle > v[pivot])
			{
				return do_search(pivot,end_index,v);
			}
			else
			{
				return do_search(start_index,pivot,v);
			}
		}
	}
}

#endif // BINSEARCH_H