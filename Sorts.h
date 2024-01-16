/*
 * Name:            Noah Nininger
 * Date Submitted:  02/23/23
 * Lab Section:     001
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

template<typename T>
void merge(std::vector<T>&data, int start, int end)
{
	int x, y, z, mid;
	std::vector<T> temp(end - start + 1);
	mid = (start + end) / 2;

	x = start;		// start index of first half [start, mid]
	y = mid + 1;	// start index of second half [mid+1, end]
	z = 0;			// start index of temp

	while (x <= mid && y <= end)
	{
		if (data[x] < data[y])
		{
			temp[z] = data[x];
			++x, ++z;
		}
		else
		{
			temp[z] = data[y];
			++y, ++z;
		}
	}

	while (x <= mid)
	{
		temp[z] = data[x];
		++x, ++z;
	}

	while (y <= end)
	{
		temp[z] = data[y];
		++y, ++z;
	}

	// write the merged sequence back to the original vector
	for (int i = start; i <= end; ++i)
		{ data[i] = temp[i - start]; }
}

// wrapper function that performs merge sort on vector data (recursive)
template<typename T>
void mergeWrap(std::vector<T>&data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

	 // uses wrapper functions to perform operations
		mergeWrap(data, start, mid);
		mergeWrap(data, mid + 1, end);

		merge(data, start, end);   // merge the above 2 componenets
	}
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
    std::vector<T> v = lst;
	mergeWrap(v, 0, v.size() - 1);
	return v;
}

template <typename T>
void swap(T* a, T* b) 	// swaps two elements
{ 
        T t = *a; 
        *a = *b; 
        *b = t; 
} 

template <typename T>
int partition(std::vector<T> &data, int start, int end)
{

	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) 
	{
		if (data[i] < data[pivot]) 
		{
			swap(&data[i], &data[j]);
			++j;
		}
	}
	swap(&data[j], &data[pivot]);
	return j;
}

// wrapper function that performs quick sort on vector data (recursive)
template <typename T>
void quickWrap(std::vector<T> &data, int start, int end )
{

	if (start < end) 
	{
		int p = partition(data, start, end);
		quickWrap(data, start, p - 1);
		quickWrap(data, p + 1, end);
	}
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
	std::vector<T> v = lst;
	quickWrap(v, 0, v.size() - 1);
	return v;
}
