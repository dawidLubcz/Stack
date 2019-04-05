#include "CMyStack.h"
#include <iostream>
static const uint64_t g_uiInitalSize = 0;

//-----------------------------------------------
// copyArray
template<typename T>
bool_t CMyStack<T>::copyArray(T *a_paSource, T *a_paDest, uint64_t a_uiSize)
{
    bool_t fResult = false;

    if(0 != a_paSource && 0 != a_paDest)
    {
        for(uint64_t idx = 0; idx < a_uiSize; idx++)
        {
            if(idx < m_uiSize)
            {
                a_paDest[idx] = a_paSource[idx];
            }
            else
            {
                a_paDest[idx] = T(0);
            }
        }

        fResult = true;
    }

    return fResult;
}

//-----------------------------------------------
// arraySize
template<typename T>
uint64_t CMyStack<T>::arraySize()
{
    return m_uiArraySize;
}

//-----------------------------------------------
// constructor
template<typename T>
CMyStack<T>::CMyStack():m_paItems(new T[g_uiInitalSize]), m_uiArraySize(g_uiInitalSize), m_uiSize(0)
{

}

//-----------------------------------------------
// destructor
template<typename T>
CMyStack<T>::~CMyStack()
{
    if(0 != m_paItems)
    {
        delete[] m_paItems;
        m_paItems = 0;
        m_uiSize = 0;
    }
}

//-----------------------------------------------
// push
template<typename T>
bool_t CMyStack<T>::push(T a_oItem)
{
    bool_t fResult = false;

    //resize the array
    if(m_uiSize == m_uiArraySize)
    {
        const int newSize = m_uiSize == 0 ? MIN_SIZE : m_uiSize * 2;

        T *oldArray = m_paItems;
        T *newArray = new T[newSize];

        copyArray(oldArray, newArray, m_uiSize);

        m_paItems = newArray;
        m_uiArraySize = newSize;

        delete[] oldArray;
    }

    m_paItems[m_uiSize] = a_oItem;
    m_uiSize++;

    return fResult;
}

//-----------------------------------------------
// pop
template<typename T>
bool_t CMyStack<T>::pop(T &a_oItem)
{
    bool_t fResult = false;

    if(0 < m_uiSize)
    {
        m_uiSize--;
        a_oItem = m_paItems[m_uiSize];

        tryReleaseMem();

        fResult = true;
    }

    return fResult;
}

//-----------------------------------------------
// peek
template<typename T>
bool_t CMyStack<T>::peek(T &a_oItem)
{
    bool_t fResult = false;

    if(0 < m_uiSize)
    {
        a_oItem = m_paItems[m_uiSize - 1];

        fResult = true;
    }

    return fResult;
}

//-----------------------------------------------
// clear
template<typename T>
bool_t CMyStack<T>::clear()
{
    bool_t fResult = false;

    if(0 < m_uiSize)
    {
        T *oldArray = m_paItems;
        T *newArray = new T[g_uiInitalSize];

        m_uiArraySize = 0;
        m_uiSize = 0;

        m_paItems = newArray;
        delete[] oldArray;
    }

    return fResult;
}

//-----------------------------------------------
// size
template<typename T>
uint64_t CMyStack<T>::size()
{
    return m_uiSize;
}

//-----------------------------------------------
// getItems
template<typename T>
bool_t CMyStack<T>::getItems(T *a_atItemsArray, uint64_t a_ui64Size)
{
    bool_t fResult = false;
    if(0 == a_ui64Size)
    {
        fResult = copyArray(m_paItems, a_atItemsArray, m_uiSize);
    }
    else
    {
        fResult = copyArray(m_paItems, a_atItemsArray, a_ui64Size);
    }
    return fResult;
}

//-----------------------------------------------
// contains
template<typename T>
bool_t CMyStack<T>::contains(T a_oItem)
{
    bool_t fResult = false;

    if(0 != m_paItems && 0 < m_uiSize)
    {
        for(uint64_t idx = 0; idx < m_uiSize; idx++)
        {
            if (a_oItem == m_paItems[idx])
            {
                fResult = true;
            }
        }
    }

    return fResult;
}

//-----------------------------------------------
// removeDuplicates
template<typename T>
void CMyStack<T>::removeDuplicates()
{
    if(0 != m_paItems && 0 < m_uiSize)
    {
        for(uint64_t i = 0; i<m_uiSize - 1; i++)
        {
            for(uint64_t j = i+1; j<m_uiSize; )
            {
                if(m_paItems[j] == m_paItems[i])
                {
                    for(uint64_t k = j; k<m_uiSize - 1; k++)
                    {
                        m_paItems[k] = m_paItems[k+1];
                    }
                    m_uiSize--;

                    tryReleaseMem();
                }

                if(m_paItems[j] != m_paItems[i])
                {
                    j++;
                }
            }
        }
    }
}

//-----------------------------------------------
// tryReleaseMem
template<typename T>
void CMyStack<T>::tryReleaseMem()
{
    if(m_uiSize > 0 && MIN_SIZE < m_uiArraySize)
    {
        if(m_uiArraySize / m_uiSize == 2)
        {
            T *oldArray = m_paItems;
            T *newArray = new T[m_uiSize];

            copyArray(oldArray, newArray, m_uiSize);

            m_paItems = newArray;
            m_uiArraySize = m_uiSize;

            delete[] oldArray;
        }
    }
}
