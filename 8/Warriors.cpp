#include <iostream>
#include <vector>
#include <math.h>
#include "Spells.cpp"

using namespace std;

using namespace std;
template <typename T> T summ(T& a, T& b){
    T s;
    s = a + b;
    return s;
}


int summury_damage(int a, int hp, int d){
    int da;
    da = round(a*(100-d)/100);
    if (da>hp){
        return 0;
    }
    else{
        return hp - da;
    }
}

class Creature{
    public:
    int HP;
    int def;
    int damage;
    int speed;
    bool shield;
    bool curse;
    virtual void inf()=0;        
};

class Infantryman : public Creature{ //пехотинец
    public:
    Infantryman(int h, int de, int da, int s){
        damage = da;
        HP = h;
        def = de;
        speed = s;
        shield = false;   
        curse = false;     

    }
    Infantryman(){
        damage = 15;
        HP = 150;
        def = 20;
        speed = 100;
        shield = false;   
        curse = false; 
    }
    void inf(){
            cout << "HP:" << HP << "\n";
            cout << "Deffence: " << def << "\n";
            cout << "Damage: " << damage << "\n";
            cout << "Speed: " << speed << "\n";
            if (curse){
                cout << "You have a curse." << "\n";
            }
            else{
                cout << "You have no curses" << "\n";
            }
    }
    void RaiseShield(){
        int s = round(speed/2);
        speed = s;
        def *=2;
    }
};

class Grunt: public Creature{ //базовый орк (рубака)
    public:
    Grunt(int h, int de, int da, int s){
        damage = da;
        HP = h;
        def = de;
        speed = s;
        shield = false;   
        curse = false;
        }
    Grunt(){
        damage = 15;
        HP = 175;
        def = 15;
        speed = 100;
        shield = false;   
        curse = false; 
    }
    void inf(){
            cout << "HP:" << HP << "\n";
            cout << "Deffence: " << def << "\n";
            cout << "Damage: " << damage << "\n";
            cout << "Speed: " << speed << "\n";
            if (curse){
                cout << "You have a curse." << "\n";
            }
            else{
                cout << "You have no curses" << "\n";
            }
    }
    void Berserker(){
        int de = round(def/2);
        int da = round(damage*3/2);
        damage = da;
        def = de;
    }
};

class Wizard: public Creature{   
    public:
        int mana;
        Attack* attack;
        Deffence* deffence;
        Unforgivable* unforgivable;
        Effects* effect; 

        Wizard(int H, int De, int Da, int S, int m, Attack* a, Deffence* d, Unforgivable* u, Effects* e){
            attack = a;
            deffence = d;
            unforgivable = u;
            effect = e;
            HP = H;
            def = De;
            damage = Da;
            speed = S;
            mana = m;
            shield = false;
            curse = false;
        }
        void inf(){
            cout << "HP:" << HP << "\n";
            cout << "Deffence: " << def << "\n";
            cout << "Damage: " << damage << "\n";
            cout << "Speed: " << speed << "\n";
            cout << "Mana: " << mana << "\n";
            if (curse){
                cout << "You have a curse." << "\n";
            }
            else{
                cout << "You have no curses" << "\n";
            }
            cout << "Attack spell: " << attack->name << "\n";
            cout << "Deffence spell: " << deffence->name << "\n";
            cout << "Unforgivable spell: " << unforgivable->name << "\n";
            cout << "Effect spell: " << effect->name << "\n";
            if (shield){
                cout << " Shield is on" << "\n";
            }
            else{
                cout << "No shield" << "\n";
            }
        }
        void useAttackSpell(Creature* t){
            string err = "You can't attack him. He has a shield.";
            if (t->shield){
                throw err;
            }
            else{
                t->HP = summury_damage(attack->damage, t->HP, t->def);
                mana -= attack->vmana;
                t->speed = summury_damage(attack->speed, t->speed, 0);
                t->def = summury_damage(attack->def, t->def, 0);
            }
        }
        void useDeffenceSpell(){
            HP =summ(HP, deffence->HP);
            def = summ(def, deffence->def);
            string err = "You can't put new shield";
            if (shield){
                throw err;
            }
            shield = summ(shield , deffence->shield);
        }
        void useUnforgivableSpell(Creature* t){
            string err = "You have been cursed yet. You can't use unforgivable spells more";
            if (curse){
                throw err;
            }
            t->HP = summury_damage(unforgivable->damage, t->HP, 0);
            t->shield = false;
            curse = summ(curse, unforgivable->curse);
            t->curse = summ(t->curse, unforgivable->curse);
        }
};