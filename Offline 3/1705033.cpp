#include<iostream>
#include<cstring>
using namespace std;

class Unit
{
protected:
    int range;
    int health;
    int damage;
    int cost;
    int step_size;
    int position;
    int round;
    int return_coin;
    int coin;
    char shoot_type[20];
    char movement[20];
    char name[20];
public:
    virtual int get_health(){}
    virtual int get_cost(){}
    virtual int get_coin(){}
    virtual int get_round(){}
    virtual int get_position(){}
    virtual int get_range(){}
    virtual char *get_name(){}
    virtual char *get_movement(){}
    virtual char *get_shoot_type(){}
    virtual void round_update(int k){}
    virtual void cost_update(int k){}
    virtual int round_decreament(){}
};

class Archer : public Unit
{
public:
    Archer(int n)
    {
        range=50;
        health=100;
        damage=25;
        cost=150;
        step_size=25;
        position=25;
        return_coin=0;
        strcpy(movement,"Running");
        strcpy(shoot_type,"Advanced Arrow");
        strcpy(name,"Archer");
    }

    int get_range(){
        return range;
    }

    int get_health(){
        return health;
    }

    int get_cost(){
        return cost;
    }

    int get_position(){
        return position;
    }

    char *get_name(){
        return name;
    }

    char *get_movement(){
        return movement;
    }

    char *get_shoot_type(){
        return shoot_type;
    }

    void round_update(int k)
    {
        health-=40;
        position+=25;
    }
};

class AdvancedArcher : public Unit
{
public:
    AdvancedArcher(int n)
    {
        range=50;
        health=120;
        damage=50;
        cost=600;
        step_size=30;
        position=30;
        return_coin=0;
        strcpy(movement,"Riding_Horse");
        strcpy(shoot_type,"Improved Arrow");
        strcpy(name,"Advanced Archer");
    }

    int get_range(){
        return range;
    }

    int get_health(){
        return health;
    }

    int get_cost(){
        return cost;
    }

    int get_position(){
        return position;
    }

    char *get_name(){
        return name;
    }

    char *get_movement(){
        return movement;
    }

    char *get_shoot_type(){
        return shoot_type;
    }

    void round_update(int k)
    {
        health-=40;
        position+=30;
    }
};

class Bowman : public Unit
{
public:
    Bowman(int n)
    {
        range=110;
        health=60;
        damage=10;
        cost=100;
        step_size=0;
        position=0;
        return_coin=40;
        strcpy(movement,"Stationary");
        strcpy(shoot_type,"Basic Arrow");
        strcpy(name,"Bowman");
    }

    int get_range(){
        return range;
    }

    int get_health(){
        return health;
    }

    int get_cost(){
        return cost;
    }

    int get_position(){
        return position;
    }

    char *get_name(){
        return name;
    }

    char *get_movement(){
        return movement;
    }

    char *get_shoot_type(){
        return shoot_type;
    }


    void round_update(int k)
    {
        health-=40;
    }
};

class AdvancedBowman : public Unit
{
public:
    AdvancedBowman(int n){
        range=130;
        health=85;
        damage=15;
        cost=200;
        step_size=0;
        position=0;
        return_coin=60;
        strcpy(movement,"Stationary");
        strcpy(shoot_type,"Canon");
        strcpy(name,"Advanced Bowman");
    }

    int get_range(){
        return range;
    }

    int get_health(){
        return health;
    }

    int get_cost(){
        return cost;
    }

    int get_position(){
        return position;
    }

    char *get_name(){
        return name;
    }

    char *get_movement(){
        return movement;
    }

    char *get_shoot_type(){
        return shoot_type;
    }

    void round_update(int k)
    {
        health-=40;
    }
};

class EnemyTower : public Unit
{
public:
    EnemyTower(int k)
    {
        range=200;
        health=300;
        damage=40;
        coin=1600;
        step_size=0;
        position=0;
        return_coin=0;
        round=1;
        strcpy(movement,"Stationary");
        strcpy(shoot_type,"Fire Arrow");
        strcpy(name,"Enemy tower");
    }


    int get_health(){
        return health;
    }

    int get_coin(){
        return coin;
    }

    int get_round(){
        return round++;
    }

    int round_decreament(){
        return --round;
    }

    int get_position(){
        return position;
    }

    char *get_name(){
        return name;
    }

    char *get_movement(){
        return movement;
    }

    char *get_shoot_type(){
        return shoot_type;
    }

    void round_update(int k)
    {
        if(k==3) health-=10;
        else if(k==4) health-=15;
        else if(k==1) health-=25;
        else if(k==2) health-=50;
    }

    void cost_update(int k)
    {
        if(k==3){
            coin-=60;
            cout<<"Bowman gave 40 coins while dying.\n";
        }
        else if(k==4){
            coin-=140;
            cout<<"Advanced Bowman gave 60 coins while dying.\n";
        }
        else if(k==1){
            coin-=150;
        }
        else if(k==2){
            coin-=600;
        }
    }
};

int main()
{
    Unit *w;
    Unit *x;
    x=new EnemyTower(0);
    int choice;

    while(1)
    {
        cout<<"Coins remaining: "<<x->get_coin()<<endl;
        cout<<"Choose your option:"<<endl;
        cout<<"1. Archer (cost 150)"<<endl;
        cout<<"2. Advanced Archer(cost 600)"<<endl;
        cout<<"3. Bowman(cost 100)"<<endl;
        cout<<"4. Advanced Bowman(cost 200)"<<endl;

        cin>>choice;

        switch(choice)
        {
            case 1: w =  new Archer(0);
                    break;
            case 2: w = new AdvancedArcher(0);
                    break;
            case 3: w =  new Bowman(0);
                    break;
            default : w = new AdvancedBowman(0);
                    break;
        }


        if(w->get_cost()>x->get_coin()){
            cout<<"You can't deploy "<<w->get_name()<<" because you don't have enough coins\n";
            continue;
        }

        cout<<"Round : "<<x->get_round()<<endl;
        if(100-w->get_position()<=w->get_range()){
            cout<<w->get_name()<<". Health : "<<w->get_health()<<". "<<w->get_movement()<<". "<<"Positioned at "<<w->get_position()<<". "<<w->get_name()<<" is shooting "<<w->get_shoot_type()<<"."<<endl;
            x->round_update(choice);
        }
        else
            cout<<w->get_name()<<". Health : "<<w->get_health()<<". "<<w->get_movement()<<". "<<"Positioned at "<<w->get_position()<<". "<<endl;
        cout<<"EnemyTower's Health : "<<x->get_health()<<". EnemyTower is shooting Fire Arrow."<<endl;
        w->round_update(0);

        while(1){
            if(w->get_health()>0){
                if(100-w->get_position()<=w->get_range()){
                    x->round_update(choice);
                    //w->round_update(0);
                    cout<<"Round : "<<x->get_round()<<endl;
                    cout<<w->get_name()<<". Health : "<<w->get_health()<<". "<<w->get_movement()<<". "<<"Positioned at "<<w->get_position()<<". "<<w->get_name()<<" is shooting "<<w->get_shoot_type()<<"."<<endl;
                    if(x->get_health()<=0){
                    cout<<"EnemyTower's Health : "<<x->get_health()<<". EnemyTower died."<<endl;
                    cout<<"Game Over! You won!!!"<<endl;
                    return 0;
                    }
                    cout<<"EnemyTower's Health : "<<x->get_health()<<". EnemyTower is shooting Fire Arrow."<<endl;
                    w->round_update(0);
                    //x->round_update(choice);
                 }
                 else{
                    //w->round_update(0);
                    cout<<"Round : "<<x->get_round()<<endl;
                    cout<<w->get_name()<<". Health : "<<w->get_health()<<". "<<w->get_movement()<<". "<<"Positioned at "<<w->get_position()<<". "<<endl;
                    cout<<"EnemyTower's Health : "<<x->get_health()<<". EnemyTower is shooting Fire Arrow."<<endl;
                    w->round_update(0);
                    //x->round_update(choice);
                 }
            }
            if(w->get_health()<=0){
                cout<<"Round : "<<x->get_round()<<endl;
                cout<<w->get_name()<<". "<<"Health: "<<w->get_health()<<". Unit Died!!"<<endl;
                x->round_decreament();
                break;
            }
        }

        x->cost_update(choice);

        if(x->get_coin()<100){
            cout<<"Game over!You are short of coin!!!\n";
            return 0;
        }

    }

    return 0;

}
