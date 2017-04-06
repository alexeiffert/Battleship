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
        return 0;
    }
    int getxStart() {
        return 0;
    }
    int getDirection() {
        return 0;
    }
    void destroyedShip() {

    }
    bool getStatus() {
        if () {

        }

        else {

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
