#pragma once
#include <string>
#include "Point2D.h"

using namespace std;
class Character
{
private:
    string name;
    Point2D location;
    bool npc;

public:
    Character(const std::string& name, const Point2D& location, bool npcflag = 0) : name(name), location(location), npc(npcflag) {   }

    void MoveTo(int x, int y) 
    {
        location.setPoint(x, y);
    }

    void MoveTo(int direction, int steps = 1)
    {
        int deltaX(0), deltaY(0);
        // 0 - вверх 1 - вправо 2 - вниз 3 - влево 4 - вверх влево 5 - вверх вправо 6 - вниз вправо 7 - вниз влево
        switch (direction)
        {
        case 0:
            deltaY = 1;
            break;
        case 1:
            deltaX= 1;
            break;
        case 2:
            deltaY = -1;
            break;
        case 3:
            deltaX = -1;
            break;
        case 4:
            deltaX = -1;
            deltaY = 1;
                break;
        case 5:
            deltaX = 1;
            deltaY = 1;
            
            break;
        case 6:
            deltaX = 1;
            deltaY = -1;
            break;
        case 7:
            deltaX = -1;
            deltaY = -1;
            
                break;

        default:
            break;
            }
        location.setPoint(location.getX() + deltaX*steps, location.getY() + deltaY*steps);
    }
    Point2D getlocation()
    {
        return location;
    }

    bool isNPC() { return npc; }



    virtual void AutoMove() = 0;
    
        
   
};

class Prey : Character {
    //friend ostream& operator<<(ostream&, const Arena&);
private:
    //friend Predator;
    //friend class Arena;
    //std::string name;
    //Point2D location;
    const int range = 1;
public:
    Prey(const std::string& name, const Point2D& location, bool npcflag = 0) : Character (name, location, npcflag) {   }

    

   // void AutoMove(const Arena&, int z);

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
    
};
//ostream& operator<<(ostream& out, const Prey& p) {
//    out << "Имя жертвы - " << p.name << "Координаты жертвы - " << p.location << endl;
//    return out;
//}


void Prey::AutoMove() {
    //int range = 1;
    int direction;
    if (isNPC())
    {
        int direction = rand % 8;
       
    }
    else {
        cout << "Куда идти?\n0-вверх-влево 1-вверх 2-вверх-вправо 3-влево 4-вправо 5-вниз-влево 6-вниз 7-вниз-вправо" << endl;
        cin >> direction;
    }
    MoveTo(direction, range);
    
}


class Predator : Character {
private:
    /*friend Prey;
    friend class Arena;
    friend ostream& operator<<(ostream&, const Arena&);
    std::string name;
    Point2D location;*/
    int range;
public:
    Predator(const std::string& name, const Point2D& location, bool npcflag = 0) : Character (name,location, npcflag) {   }

    void SetRange(int r)
    {
        
    }

    void AskRange()
    {
        do {
            cout << "На сколько? (1-5)" << endl;
            cin >> r;
            if (1 <=r)
        }
    };
    /*void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }
    void AutoMove(const Arena&, int z);
    friend ostream& operator<<(ostream&, const Predator&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);*/
};
//ostream& operator<<(ostream& out, const Predator& p) {
//    out << "Имя хищника - " << p.name << "\nКоординаты хищника - " << p.location << endl;
//    return out;
//}