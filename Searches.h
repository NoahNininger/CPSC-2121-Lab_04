/*
 * Name:            Noah Nininger
 * Date Submitted:  02/23/23
 * Lab Section:     001
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
    int n = data.size();
    int index= -1;

    for(int i = 0; i < n; i++)
    {
        if(data[i] == target)
        {
            index = i;
            break;
        }
    }

    return index;
}

// wrapper function to perform binary search on vector data (recursive)
template <class T>
int binaryWrap(std::vector<T> data, T target, int l, int r) 
{ 
    if(r >= l)
    { 
        int mid = l + (r - l) / 2; 

        // if element is present at the middle
        if (data[mid] == target) 
            { return mid; }

        // if target can only be present in left subarray 
        if (data[mid] > target) 
            { return binaryWrap(data, target, l, mid - 1); } 
        return binaryWrap(data, target, mid + 1, r); 
    } 

 // if target not present in vector
    return -1; 
}

template <class T>
int binarySearch(std::vector<T> data, T target)
    { return binaryWrap(data, target, 0, data.size()-1); }
