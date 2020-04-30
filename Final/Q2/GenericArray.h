#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>


template <typename T>
class GenericArray
{
private:
    T **values;
    int count;
    int maxSize;

public:
    GenericArray(int _size);
    GenericArray(const GenericArray &ObjToCopy);
    const GenericArray &operator=(const GenericArray &RHSObj);
    void push_back(const T &Element);
    void pop_back();
    void print() const;
    const T &at(int pos) const;
    int size() const;
    int nElems() const;
    ~GenericArray();
};

template <typename T>
GenericArray<T>::GenericArray(int _size)
{
    maxSize = _size;
    count = 0;
    values = new T *[maxSize];
    for (int i = 0; i < maxSize; i++)
        values[i] = nullptr;
}

template <typename T>
GenericArray<T>::GenericArray(const GenericArray &ObjToCopy)
{
    maxSize = ObjToCopy.maxSize;
    count = ObjToCopy.count;
    values = new T *[maxSize];
    for (int i = 0; i < maxSize; i++)
    {
        if (ObjToCopy.values[i] != nullptr)
        {
            values[i] = new T;
            *values[i] = *ObjToCopy.values[i];
        }
        else
            values[i] = nullptr;
    }
}

template <typename T>
const GenericArray<T> & GenericArray<T>::operator=(const GenericArray &RHSObj)
{
    if (this != &RHSObj)
    {
        maxSize = RHSObj.maxSize;
        count = RHSObj.count;
        delete[] values;
        values = new T *[maxSize];
        for (int i = 0; i < maxSize; i++)
            values[i] = nullptr;
        for (int i = 0; i < maxSize; i++)
        {
            if (RHSObj.values[i] != nullptr)
            {
                values[i] = new T;
                *values[i] = *RHSObj.values[i];
            }
            else
                values[i] = nullptr;
        }
    }
    return *this;
}
template <typename T>
void GenericArray<T>::push_back(const T &Element)
{
    if (count == maxSize)
    {
        std::cout << "Array is full";
    }
    else
    {
        values[count] = new T;
        *values[count] = Element;
        count++;    
    }
    
}

template <typename T>
void GenericArray<T>::pop_back()
{
    if(count == 0)
    {
        std::cout << "Array is empty";
    }
    else
    {
        delete values[count-1];
        values[count-1] = nullptr;
        count--;
    }
    
}
template <typename T>
const T & GenericArray<T>::at(int pos) const
{
    if (pos < 0 || pos >= count)
    {
        std::cout << "Invalid position";
        exit(0);
    }
    else
        return *values[pos];
}

template <typename T>
void GenericArray<T>::print() const
{
    for (int i=0;i<count;i++)
        std::cout << *values[i] << " ";
    std::cout << std::endl;
}

template <typename T>
int GenericArray<T>::size() const
{
    return maxSize;
}

template <typename T>
int GenericArray<T>::nElems() const
{
    return count;
}

template <typename T>
GenericArray<T>::~GenericArray()
{
    for(int i = 0;i<maxSize;i++)
        if (values[i]!=nullptr)
        {
            delete values[i];
            values[i]=nullptr;
        }
    delete [] values;
    values = nullptr;
}

#endif
