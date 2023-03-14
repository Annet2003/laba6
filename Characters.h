#pragma once
#include <string>
#include "Point2D.h"
#include <ostream>
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
    Point2D getlocation()
    {
        return location;
    }

    bool isNPC() { return npc; }
};

class Prey : Character {
    //friend ostream& operator<<(ostream&, const Arena&);
private:
    //friend Predator;
    //friend class Arena;
    //std::string name;
    //Point2D location;

public:
    Prey(const std::string& name, const Point2D& location) : Character (name, location) {   }

    

   // void AutoMove(const Arena&, int z);

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
    
};
//ostream& operator<<(ostream& out, const Prey& p) {
//    out << "Имя жертвы - " << p.name << "Координаты жертвы - " << p.location << endl;
//    return out;
//}


class Predator : Character {
private:
    /*friend Prey;
    friend class Arena;
    friend ostream& operator<<(ostream&, const Arena&);
    std::string name;
    Point2D location;*/

public:
    Predator(const std::string& name, const Point2D& location) : Character (name,location) {   }

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