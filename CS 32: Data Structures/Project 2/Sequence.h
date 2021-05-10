//
//  Sequence.h
//  Project 2
//
//  Created by Nick Chung on 1/23/21.
//  v3

#ifndef Sequence_h
#define Sequence_h

#include <iostream>
#include <string>

using ItemType = std::string;

class Sequence {
public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& rhs);
    const Sequence& operator=(const Sequence& rhs);
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
    struct Node {
        Node* next;
        Node* previous;
        ItemType m_data;
    };
    Node* head;
    Node* tail;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
