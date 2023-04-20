#pragma once
#include <iostream>
#include "Characters.h"



class Arena {
    int l, w;
    Prey* prey;
    Predator* predator;

    int view_length, view_width;
    char** field;

public:
    Arena(int w, int l, Prey* prey, Predator* predator);
    //{
    //    this->l = l;
    //    this->w = w;
    //    this->prey = prey;
    //    this->predator = predator;
    //}
    void clearStep();
    bool checkOverRun();
   /* friend void Prey::AutoMove(const Arena& a, int z);
    friend void Predator::AutoMove(const Arena& ar, int z);*/
    ~Arena();

    friend std::ostream& operator<<(std::ostream&, const Arena&);

};