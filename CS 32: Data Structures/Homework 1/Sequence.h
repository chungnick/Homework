//
//  Sequence.h
//  Homework 1
//
//  Created by Nick Chung on 1/17/21.
//bababooey

#ifndef Sequence_h
#define Sequence_h

#include <iostream>

using ItemType = unsigned long;

class Sequence {
public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
private:
    ItemType* s;
    int m_size;
    const int DEFAULT_MAX_ITEMS = 150;
};

#endif /* Sequence_h */
