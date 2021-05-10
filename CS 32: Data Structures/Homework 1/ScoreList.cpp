//
//  ScoreList.cpp
//  Homework 1
//
//  Created by Nick Chung on 1/19/21.
//bababooey

#include "ScoreList.h"

ScoreList::ScoreList() {}

bool ScoreList::add(unsigned long score) {
    if (score >= 0 && score <= 100) {
        m_list.insert(score);
        return true;
    } else
        return false;
}

bool ScoreList::remove(unsigned long score) {
    int pos = m_list.find(score);
    if (pos == -1)
        return false;
    else {
        m_list.erase(pos);
        return true;
    }
}

int ScoreList::size() const {
    return m_list.size();
}

unsigned long ScoreList::minimum() const {
    ItemType min = 100, x = 0;
    if (m_list.empty())
        return NO_SCORE;
    else {
        for (int i = 0; i < m_list.size(); i++) {
            m_list.get(i, x);
            if (min > x)
                min = x;
        }
        return min;
    }
}

unsigned long ScoreList::maximum() const {
    ItemType max = 0, x = 0;
    if (m_list.empty())
        return NO_SCORE;
    else {
        for (int i = 0; i < m_list.size(); i++) {
            m_list.get(i, x);
            if (max < x)
                max = x;
        }
        return max;
    }
}
