#include <iostream>

using namespace std;

class Ship {

public:
    int length;
    string name;
    int yStart;
    int xStart;
    int direction;
    bool isDestroyed;

    Ship(int x,int y,int len,int dir,bool des)
    {
        xStart = x;
        yStart = y;
        direction = dir;
        length = len;
        isDestroyed = des;
    }

    int getyStart()
    {
        return yStart;
    }
    int getxStart()
    {
        return xStart;
    }
    int getDirection()
    {
        return direction;
    }
    void destroyedShip() /////
    {
            if (isDestroyed==true) {
                yStart = 0;
                xStart = 0;
                direction = 0;
            }
    }
    bool getStatus()
    {
        if (isDestroyed==false)
        {
            return false;
        }

        else
        {
            return true;
        }
    }
};
/*class Battleship:Ship {
    int length = 4;
    string name = "Battleship";
};
class Carrier:Ship {
    int length = 5;
    string name = "Carrier";
};
class Cruiser:Ship {
    int length = 3;
    string name = "Cruiser";
};
class Submarine:Ship {
    int length = 3;
    string name = "Submarine";
};
class Destroyer:Ship {
    int length = 2;
    string name = "Destroyer";
};*/

