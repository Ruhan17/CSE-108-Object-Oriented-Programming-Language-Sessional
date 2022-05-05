#include <iostream>
#include<cstdio>
#include <cmath>
#include <sstream>
#include<cstdlib>

using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3


string to_string(int x) {
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}

//class Player;
class WumpusWorld;
class Player;

class Position {
private:

    friend class WumpusWorld;
    friend class Player;
    //Player ply;
    int x, y;

public:

    Position (int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight() {
        if(this->x<=3)
        this->x++;
        //if(this->x>3) this->x--;
    }

    void moveLeft() {
        this->x--;
        if(this->x<0) this->x++;
    }

    void moveUp() {
        this->y++;
        if(this->y>3) this->y--;
    }

    void moveDown() {
        this->y--;
        if(this->y<0) this->y++;
    }

    bool isAdjacent(Position p) {
        //implement the function
        if(this->x-p.x==1&&this->y==p.y) return true;
        else if(p.x-this->x==1&&this->y==p.y) return true;
        else if(this->y-p.y==1&&this->x==p.x) return true;
        else if(p.y-this->y==1&&this->x==p.x) return true;
        else return false;
    }

    bool isSamePoint(Position p) {
        //implement the function
        if(p.x==this->x&&p.y==this->y) return true;
        else return false;
    }

    bool ShootWumpus(Position p){
        if(this->x==p.x&&p.y>this->y) return true;
        if(this->x==p.x&&p.y<this->y) return true;
        if(this->y==p.y&&p.x<this->x) return true;
        if(this->y==p.y&&p.x>this->x) return true;
        return false;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

};

class Pit
{
private:

    friend class WumpusWorld;
    friend class Player;
    bool killed;
    Position p;
    int x;
    int y;

public:
    Pit(int x,int y) {
        this->x=x;
        this->y=y;
        p=Position(x,y);
        killed=false;
    }

    Pit(){
        x=rand()%4;
        y=rand()%4;
        p=Position(x,y);
    }

    void kill()
    {
        killed=true;
    }

    Position getPosition()
    {
        return p;
    }
};


class Wumpus {
private:

    friend class WumpusWorld;
    bool killed;
    Position p;
    int x;
    int y;

public:

    Wumpus(int x, int y) {
        this->x=x;
        this->y=y;
        p=Position(x,y);
        killed = false;
    }

    Wumpus() {
        //...
        x=rand()%4;
        y=rand()%4;
        p=Position(x,y);
    }

    void kill() {
        killed = true;
    }

    Position getPosition() {
        return p;
    }

};


class Player {
private:

    friend class WumpusWorld;
    friend class Position;
    friend class Pit;
    int direction;
    int total_shots;
    bool killed;
    Position p;
    int x,y;

public:

    Player() {
        //...
        x=0;
        y=0;
        direction=UP;
        total_shots=0;
        killed=false;
        p=Position(x,y);
    }

    void turnLeft() {
        //...
        direction=(direction+3)%4;
    }

    void turnRight() {
        //...
        direction=(direction+1)%4;
    }

    void moveForward() {
        //...
        if(direction==UP&&p.y<=2) p.y++;
        if(direction==LEFT&&p.x>=1) p.x--;
        if(direction==DOWN&&p.y>=1) p.y--;
        if(direction==RIGHT&&p.x<=2) p.x++;
    }

    bool isAdjacent(Position pos) {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos) {
        return p.isSamePoint(pos);
    }

    bool ShootWumpus(Position pos){
        return p.ShootWumpus(pos);
    }

    void kill() {
        killed = true;
    }

    string getPositionInfo() {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo() {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

};



class WumpusWorld {

private:

    friend class Position;
    Position p;
    Player player;
    Wumpus wumpus;
    Pit pit;
    Position gold_position;
    bool ended;
    Position wumpus_position;
    Position pit_position;

public:

    //Player pl;
    //Wumpus w;
    WumpusWorld() {
        //...
        gold_position=Position(rand()%4,rand()%4);
        wumpus=Wumpus(rand()%4,rand()%4);
        pit_position=Position(rand()%4,rand()%4);
    }

    WumpusWorld(int wumpus_x, int wumpus_y) {
        //...
        gold_position=Position(rand()%4,rand()%4);
        wumpus=Wumpus(wumpus_x,wumpus_y);
        pit_position=Position(rand()%4,rand()%4);
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y) {
        //...
        gold_position=Position(gold_x,gold_y);
        wumpus=Wumpus(wumpus_x,wumpus_y);
        pit_position=Position(rand()%4,rand()%4);
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y) {
        //...
        //cout<<wumpus_x<<' '<<wumpus_y;
        gold_position=Position(gold_x,gold_y);
        wumpus=Wumpus(wumpus_x,wumpus_y);
        pit_position=Position(pit_x,pit_y);
    }

    void moveForward() {
        player.moveForward();
        return showGameState();
    }

    void turnLeft() {
        player.turnLeft();
        return showGameState();
    }

    void turnRight() {
        player.turnRight();
        return showGameState();
    }

    void shoot() {
        //...
        player.total_shots++;
        if(player.total_shots<=3&&!(wumpus.killed)){
            if (player.direction==UP&&player.ShootWumpus(wumpus.getPosition())){
                cout<<"Wumpus is killed!\n";
                wumpus.kill();
                cout << player.getPositionInfo() << endl;
                cout << player.getDirectionInfo() << endl;

            }
            else if (player.direction==DOWN&&player.ShootWumpus(wumpus.getPosition())){
                cout<<"Wumpus is killed!\n";
                wumpus.kill();
                cout << player.getPositionInfo() << endl;
                cout << player.getDirectionInfo() << endl;

            }
            else if (player.direction==RIGHT&&player.ShootWumpus(wumpus.getPosition())){
                cout<<"Wumpus is killed!\n";
                wumpus.kill();
                cout << player.getPositionInfo() << endl;
                cout << player.getDirectionInfo() << endl;

            }
            else if (player.direction==LEFT&&player.ShootWumpus(wumpus.getPosition())){
                cout<<"Wumpus is killed!\n";
                wumpus.kill();
                cout << player.getPositionInfo() << endl;
                cout << player.getDirectionInfo() << endl;

            }
            else{
                cout<<"Wumpus is not killed\n";
                cout<<"Remaining Shots: "<<3-player.total_shots<<"\n";
                cout << player.getPositionInfo() << endl;
                cout << player.getDirectionInfo() << endl;

            }
        }
        else if(player.total_shots<=3&&wumpus.killed){
            cout<<"Wumpus is already killed!\n";
            cout<<"Remaining Shots: "<<3-player.total_shots<<"\n";
            cout << player.getPositionInfo() << endl;
            cout << player.getDirectionInfo() << endl;

        }
        else{
            cout<<"No arrows remaining\n";
            cout << player.getPositionInfo() << endl;
            cout << player.getDirectionInfo() << endl;

        }
    }

    void showGameState() {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition())) {
            if(!wumpus.killed){
                cout << "stench!" << endl;
            }
        }

        if (player.isAdjacent(pit_position)) {
                cout << "breeze!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition())) {
            if(!wumpus.killed){
                cout << "Player is killed!" << endl;
                player.kill();
                cout << "Game over!" << endl;
                ended = true;
            }
        }

        if (player.isSamePoint(gold_position)) {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }

        if(player.isSamePoint(pit_position)){
            cout<<"Fallen in the pit\n";
            player.kill();
            cout<<"Game over!\n"<<endl;
            ended=true;
        }
    }

    bool isOver() {
        return ended;
    }

};


int main()
{
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    FILE *fp;
    char filename[]="wumpus.txt";
    fp=fopen(filename,"r");
    fscanf(fp,"%d%d%d%d%d%d",&wumpus_x,&wumpus_y,&gold_x,&gold_y,&pit_x,&pit_y);
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    w.showGameState();
    while (!w.isOver()) {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1) {
            w.moveForward();
        } else if (c == 2) {
            w.turnLeft();
        } else if (c == 3) {
            w.turnRight();
        } else if (c == 4) {
            w.shoot();
        }
    }
    return 0;
}
