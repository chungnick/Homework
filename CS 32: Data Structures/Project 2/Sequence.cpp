//
//  Sequence.cpp
//  Project 2
//
//  Created by Nick Chung on 1/23/21.
//  v3

#include "Sequence.h"

Sequence::Sequence() : head(nullptr), tail(nullptr) {}                  // initializer list sets head/tail to nullpointer

Sequence::~Sequence() {
    if (head == nullptr) {                                              // destructor checks for empty Sequence
        delete head;
        delete tail;
    } else {
        Node* p = head;
        while (p->next != nullptr) {                                    // iterate through nodes
            p = p->next;
            p->previous->next = nullptr;
            delete  p->previous;                                        // delete previous node as you go on
            p->previous = nullptr;
        }
        p->previous = nullptr;
        delete p;                                                       // delete p
        head = tail = nullptr;
    }
}

Sequence::Sequence(const Sequence& rhs) {
    if (rhs.head == nullptr)                                            // for an empty rhs sequence
        head = tail = nullptr;
    else {
        Node* p = rhs.head;
        while (p != nullptr) {
            Node* n = new Node;
            n->m_data = p->m_data;
            if (p->previous == nullptr) {                               // very first item
                n->previous = n->next = nullptr;
                head = tail = n;
            } else {                                                    // all following items behave like "last item"
                n->previous = tail;
                n->next = nullptr;
                tail->next = n;
                tail = n;
            }
            p = p->next;
        }
    }
}

const Sequence& Sequence::operator=(const Sequence& rhs) {
    if (head == nullptr) {                                              // destructor
        delete head;
        delete tail;
    } else {
        Node* p = head;
        while (p->next != nullptr) {
            p = p->next;
            p->previous->next = nullptr;
            delete  p->previous;
            p->previous = nullptr;
        }
        p->previous = nullptr;
        delete p;
        head = tail = nullptr;
    }
    if (rhs.head == nullptr)                                            // copy constructor
        head = tail = nullptr;
    else {
        Node* p = rhs.head;
        while (p != nullptr) {
            Node* n = new Node;
            n->m_data = p->m_data;
            if (p->previous == nullptr) {
                n->previous = n->next = nullptr;
                head = tail = n;
            } else {
                n->previous = tail;
                n->next = nullptr;
                tail->next = n;
                tail = n;
            }
            p = p->next;
        }
    }
    return* this;                                                       // return reference to target variable
}

bool Sequence::empty() const {
    if (head == nullptr)                                                // all empty sequences have head = nullptr
        return true;
    return false;
}

int Sequence::size() const {
    int size = 0;
    Node *p = head;
    while (p != nullptr) {                                              // simple traversal with counter variable
        p = p->next;
        size++;
    }
    return size;
}

int Sequence::insert(int pos, const ItemType& value) {
    Node* n = new Node;
    Node* p = head;
    if (pos > size())
        return -1;
    if (head == nullptr) {                                              // first and only item
        head = tail = n;
        n->next = nullptr;
        n->previous = nullptr;
    } else if (pos == 0 && size() != 0) {                               // fist but not only item
        n->previous = nullptr;
        p->previous = n;
        n->next = p;
        head = n;
    } else if (pos == size()) {                                         // last item
        n->previous = tail;
        n->previous->next = n;
        n->next = nullptr;
        tail = n;
    } else {                                                            // intermediate item
        for (int i = 0; i < pos; i++)
            p = p->next;
        p->previous->next = n;
        n->previous = p->previous;
        p->previous = n;
        n->next = p;
    }
    n->m_data = value;
    return pos;
}

int Sequence::insert(const ItemType& value) {
    int count = 0;
    Node* n = head;
    if (head == nullptr) {                                              // insert at the front
        insert(0, value);
    } else {
        while (count < size()) {
            if (value <= n->m_data){                                    // check for order
                insert(count, value);                                   // utilize original insert function
                return count;
            } else {
                count++;                                                // continue traversal
                n = n->next;
            }
        }
        insert(count, value);                                           // insert at end of the list
    }
    return count;
}

bool Sequence::erase(int pos) {
    if (size() != 0 && pos < size()) {
        Node* p = head;
        for (int i = 0; i < pos; i++)
            p = p->next;
        if (size() == 1) {                                              // only item on list
            head = tail = nullptr;
        } else if (pos == 0 && size() != 1) {                           // first but not only item
            head = p->next;
            p->next->previous = nullptr;
        } else if (pos == size() - 1) {                                 // last item on list
            tail = p->previous;
            p->previous->next = nullptr;
        } else {                                                        // intermediate item
            p->previous->next = p->next;
            p->next->previous = p->previous;
        }
        delete p;
        return true;
    }
    return false;
}

int Sequence::remove(const ItemType& value) {
    Node* p = head;
    int pos = 0, removed = 0;
    while (p != nullptr) {
        if (p->m_data == value) {
            erase(pos);                                                 // utilize erase function
            removed++;
            pos--;
        }
        p = p->next;
        pos++;
    }
    return removed;
}

bool Sequence::get(int pos, ItemType& value) const {                    // get, set follow similar algorithm
    if (pos < size() && pos >= 0) {
        Node* p = head;
        for (int i = 0; i < pos; i++)
            p = p->next;
        value = p->m_data;
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < size() && pos >= 0) {
        Node* p = head;
        for (int i = 0; i < pos; i++)
            p = p->next;
        p->m_data = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const {                       // find accounts for entire list since no pos given
    Node* p = head;
    int pos = 0;
    while (p != nullptr) {
        if (p->m_data == value)
            return pos;
        p = p->next;
        pos++;
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    Sequence copy = *this;
    *this = other;
    other = copy;
}

int subsequence(const Sequence& seq1, const Sequence& seq2) {
    if (seq1.size() >= seq2.size() && !seq2.empty() && !seq1.empty()) {
        ItemType x, y;
        seq2.get(0, y);
        int i = 0;
        while (i < seq1.size()) {
            seq1.get(i, x);
            if (x == y) {
                bool match = true;
                for (int j = 0; j < seq2.size(); j++) {
                    ItemType a, b;
                    seq2.get(j, a);
                    seq1.get(i + j, b);
                    if (a == b)
                        continue;
                    else if (a != b)
                        match = false;
                }
                if (match)
                    return i;
            }
            i++;
        }
    }
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
    for (int i = 0; i < result.size(); i++) {                           // ensure result sequence is empty
        result.erase(i);
    }
    if (seq2.empty()) {                                                 // empty sequence checks
        result = seq1;
        return;
    } else if (seq1.empty()) {
        result = seq2;
        return;
    }
    Sequence smallerSeq, largerSeq;
    if (seq1.size() <= seq2.size()) {                                    // establishing large/small for counting
        smallerSeq = seq1;
        largerSeq = seq2;
    } else {
        smallerSeq = seq2;
        largerSeq = seq1;
    }
    ItemType x, y;
    int pos = 0, p = 0;
    for (int i = 0; i < largerSeq.size(); i++) {
        seq1.get(i, x);
        seq2.get(i, y);
        result.insert(pos, x);
        pos++;
        result.insert(pos, y);
        pos++;                                                          // add element from each list
        p++;
        if (p == smallerSeq.size()) {                                   // add items from larger list once limit reached
            for (int j = 1; j < largerSeq.size() - smallerSeq.size() + 1; j++) {
                largerSeq.get(i + j, x);
                result.insert(pos, x);
                pos++;
            }
            return;
        }
    }
}

