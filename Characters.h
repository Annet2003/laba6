#pragma once
#include <string>
#include <iostream>
#include "Point2D.h"

using namespace std;

class Character
{
private:
    std::string name; // ��� ���������
    Point2D location; // ������� ��������� ���������
    bool npc; // ������� NPC

public:
    // Character(const std::string& name, const Point2D& location, bool npcflag = 0) : name(name), location(location), npc(npcflag) {   }

    Character(const std::string& name, const Point2D& location, bool npcFlag = 0);

    void moveTo(Point2D point);

    //0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - ����� ����� 5 - ����� ������ 6 - ���� ������ 7 - ���� �����

    void moveTo(int direction, int steps);

    Point2D getlocation();

    bool isNPC();

    virtual void autoMove() = 0;

    std::string getName()
    {
        return name;
    }
};
    /*
    void MoveTo(int x, int y) 
    {
        location.setPoint(x, y);
    }

    void MoveTo(int direction, int steps = 1)
    {
        int deltaX(0), deltaY(0);
        // 0 - ����� 1 - ������ 2 - ���� 3 - ����� 4 - ����� ����� 5 - ����� ������ 6 - ���� ������ 7 - ���� �����
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
    */
        

class Prey : public Character {
    //friend ostream& operator<<(ostream&, const Arena&);
private:
    //friend Predator;
    //friend class Arena;
    //std::string name;
    //Point2D location;
    const int range = 1;
public:
    Prey(const std::string& name, const Point2D& location, bool npcflag = 0); //: Character (name, location, npcflag) {   }
    int askDirection();
    void autoMove() override;
    

   // void AutoMove(const Arena&, int z);

    //friend ostream& operator<<(ostream& out, const Prey&);
    //friend bool check(const Prey& prey, const Predator& predator);
    //friend bool check1(const Prey& prey, const Predator& predator);
    
};
//ostream& operator<<(ostream& out, const Prey& p) {
//    out << "��� ������ - " << p.name << "���������� ������ - " << p.location << endl;
//    return out;
//}


/*void Prey::AutoMove() {
    //int range = 1;
    int direction;
    if (isNPC())
    {
        int direction = rand % 8;
       
    }
    else {
        cout << "���� ����?\n0-�����-����� 1-����� 2-�����-������ 3-����� 4-������ 5-����-����� 6-���� 7-����-������" << endl;
        cin >> direction;
    }
    MoveTo(direction, range);
    
}*/


class Predator : public Character {
private:
    /*friend Prey;
    friend class Arena;
    friend ostream& operator<<(ostream&, const Arena&);
    std::string name;
    Point2D location;*/
    const int MaxRange = 5;
public:
    Predator(const std::string& name, const Point2D& location, bool npcflag = 0) : Character (name,location, npcflag) {   }

   /* void SetRange(int r)
    {
        
    }*/

    int AskRange()
    {
        do {
            int range;
            std::cout << "�� �������? (1-5) \n" << endl;
            std::cin >> range;

            if (range >= 1 && range <= MaxRange)
            {
                return range;
            }
            else std::cout << "����������� ������� ������, ���������� ������ \n";
        } while (true);
    }

    int AskDirection()
    {
        do {
            int direction(0);
            std::cout << "���� ����?\n";
            std::cout << "0 - �����, 1 - ������, 2 - ����, 3 - ����� \n";
            std::cin >> direction;

            if (direction <= 3 && direction >= 0)
            {
                return direction;
            }
            else std::cout << "����������� ������� ������, ���������� ������ \n";
        } while (true);
    }

    void autoMove() override
    {
        int direction = 0;
        int range = 0;

        if (isNPC())
        {
            direction = rand() % 4;
            range = rand() % 5 + 1;
        }
        else
        {
            direction = AskDirection();
            range = AskRange();
        }

        moveTo(direction, range);
    }
    /*void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }
    void AutoMove(const Arena&, int z);
    friend ostream& operator<<(ostream&, const Predator&);
    friend bool check(const Prey& prey, const Predator& predator);
    friend bool check1(const Prey& prey, const Predator& predator);*/
};
//ostream& operator<<(ostream& out, const Predator& p) {
//    out << "��� ������� - " << p.name << "\n���������� ������� - " << p.location << endl;
//    return out;
//}