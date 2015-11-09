#ifndef CMYSTACK_H
#define CMYSTACK_H

#define MIN_SIZE 4

typedef long unsigned int uint64_t;
typedef bool bool_t;

template<class T>
class CMyStack
{
private:
    /**
     *
     */
    T* m_paItems;

    /**
     *
     */
    uint64_t m_uiArraySize;

    /**
     *
     */
    uint64_t m_uiSize;

    /**
     *
     */
    bool_t copyArray(T *a_paSource, T *a_paDest, uint64_t a_uiSize);

    /**
     *
     */
    void tryReleaseMem();

    /**
     *
     */
    uint64_t arraySize();

public:
    CMyStack();
    ~CMyStack();

    /**
     *
     */
    bool_t push(T a_oItem);

    /**
     *
     */
    bool_t pop(T &a_oItem);

    /**
     *
     */
    bool_t peek(T &a_oItem);

    /**
     *
     */
    bool_t clear();

    /**
     *
     */
    uint64_t size();

    /**
     *
     */
    bool_t getItems(T *a_atItemsArray, uint64_t a_ui64Size = 0);

    /**
     *
     */
    bool_t contains(T a_oItem);

    /**
     *
     */
    void removeDuplicates();

};

#include "CMyStack.cpp"

#endif // CMYSTACK_H
