#include <iostream>

using namespace std;

class Ship() {
private:
    virtual int length;
    virtual string name;
    int yStart;
    int xStart;
    int direction;
    bool isDestroyed;

public:
    int getyStart() {
        return yStart;
    }
    int getxStart() {
        return xStart;
    }
    int getDirection() {
        return direction;
    }
    void destroyedShip() {
            if (isDestroyed==true) {
                yStart = 0;
                xStart = 0;
                direction = 0;
            }
            else {
                break;
            }
    }
    bool getStatus() {
        if (isDestroyed==false) {
            return false;
        }

        else {
            return true;
        }
    }
}
class Battleship:Ship {
    length = 4;
    name = "Battleship";
};
class Carrier:Ship {
    length = 5;
    name = "Carrier";
};
class Cruiser:Ship {
    length = 3;
    name = "Cruiser";
};
class Submarine:Ship {
    length = 3;
    name = "Submarine";
};
class Destroyer:Ship {
    length = 2;
    name = "Destroyer";
};

};
