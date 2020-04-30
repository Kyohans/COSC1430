#include "GenericArray.h"

template <typename T>
GenericArray<T> concatenate (const GenericArray<T> arr1, GenericArray<T> arr2)
{
    int size = arr1.nElems() + arr2.nElems();
    GenericArray<T> newArr(size);

    // Push back arr1's elements into newArr
    for(int i = 0; i < arr1.nElems(); i++)
        newArr.push_back(arr1.at(i));

    // Then push back arr2's elements into newArr
    for(int i = 0; i < arr2.nElems(); i++)
        newArr.push_back(arr2.at(i));
    
    return newArr;
}

template <typename T>
GenericArray<T> replicate (const GenericArray<T> arr1, int mul)
{
    int size = arr1.nElems() * mul;
    GenericArray<T> newArr(size);

    int count = 0;
    while(count < mul)
    {
        for(int i = 0; i < arr1.nElems(); i++)
        {
            newArr.push_back(arr1.at(i));
        }
        count++;
    }

    return newArr;
}

template <typename T>
GenericArray<T> reduce (const GenericArray<T> arr1, int sub)
{
    if(sub >= arr1.nElems())
    {
        GenericArray<T> empty(0);
        return empty;
    }

    int size = arr1.nElems() - sub;
    GenericArray<T> newArr(size);

    for(int i = 0; i < newArr.size(); i++)
        newArr.push_back(arr1.at(i));

    return newArr;
}