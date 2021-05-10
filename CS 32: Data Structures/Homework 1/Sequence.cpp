//
//  Sequence.cpp
//  Homework 1
//
//  Created by Nick Chung on 1/17/21.
//bababooey

#include "Sequence.h"
#include <iostream>

Sequence::Sequence() : m_size(0) {
    s = new ItemType[DEFAULT_MAX_ITEMS];
}

bool Sequence::empty() const {
    if (size() == 0)
        return true;
    else
        return false;
}

int Sequence::size() const {
    return m_size;
}

int Sequence::insert(int pos, const ItemType &value) {
    if (size() == DEFAULT_MAX_ITEMS)
        return -1;
    else {
        if (pos >= 0 && pos <size()) {
            for (int i = size(); i > pos; i--)
                s[i] = s[i - 1];
            s[pos] = value;
            m_size++;
            return pos;
        } else if ( pos >= 0 && pos == size()) {
            s[pos] = value;
            m_size++;
            return pos;
        } else
            return -1;
    }
}

int Sequence::insert(const ItemType &value) {
    int p = 0;
    bool stop = false;
    if (size() == 0) {
        return insert(p, value);
    } while (p < size() && stop == false) {
        if (value <= s[p])
            stop = true;
        else {
            p++;
        }
    }
    return insert(p, value);
}

bool Sequence::erase(int pos) {
    if (pos >= size() || pos < 0)
        return false;
    else {
        for (int i = pos; i < size(); i++) {
            s[i] = s[i + 1];
        }
    }
    m_size--;
    return true;
}

int Sequence::remove(const ItemType &value) {
    int removed = 0, i = 0;
    while (i < size()) {
        if (s[i] == value) {
            erase(i);
            removed++;
        } else
            i++;
    }
    return removed;
}

bool Sequence::get(int pos, ItemType &value) const {
    if (pos >= size() || pos < 0)
        return false;
    else {
        value = s[pos];
        return true;
    }
}

bool Sequence::set(int pos, const ItemType &value) {
    if (pos >= size() || pos < 0)
        return false;
    else {
        s[pos] = value;
        return true;
    }
}

int Sequence::find(const ItemType &value) const {
    int p = -1;
    for (int i = 0; i < size(); i++) {
        if (s[i] == value) {
            p = i;
            break;
        }
    }
    return p;
}

void Sequence::swap(Sequence &other) {
    int thisSize = size();
    int otherSize = other.size();
    Sequence temp;
    for (int i = 0; i < thisSize; i++) {
        temp.insert(i, s[i]);
    }
    for (int j = 0; j < otherSize; j++) {
        insert(j, other.s[j]);
    }
    for (int k = 0; k < thisSize; k++) {
        other.insert(k, temp.s[k]);
    }
    for (int a = 0; a < thisSize + otherSize; a++) {
        erase(otherSize);
    }
    for (int b = 0; b < thisSize + otherSize; b++) {
        other.erase(thisSize);
    }

}
