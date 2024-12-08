#include <iostream>
#include <vector>
#include <math.h>

#ifndef A
#define A
using namespace std;

class Spell{
    public:\
    string name;
    int vmana; //расход маны колдуна
    virtual void inf() = 0;
};

// атака
class Attack : public Spell {
    public:
    int damage;
    int speed;
    int def;
    Attack(int da, int s, int de, int m, string n){
        damage = da;
        speed = s;
        def = de;
        vmana = m;
        name = n;
    }
    void inf(){
            cout << "Spell's name: " << name << "\n";
            cout << "Damage: " << damage << "\n";
            cout << "Deffence: " << def << "\n";
            cout << "Speed: " << speed << "\n";
            cout << "Mana: " << vmana << "\n";
    }
};
// защита+лечение
class Deffence : public Spell {    
    public:
    int HP;
    int def;
    bool shield;
    Deffence(int hp, int d, int m, bool s, string n){
        HP = hp;
        def = d;
        vmana = m;
        name = n;
        shield = s;
    }
    void inf(){
        cout << "Spell's name: " << name << "\n";
        cout << "HP:" << HP << "\n";
        cout << "Deffence: " << def << "\n";
        cout << "Mana: " << vmana << "\n";
        cout << "Shield:  " << shield << "\n";
    }
};

//непростительные
class Unforgivable : public Spell {   
    public:
    int damage;
    bool curse;
    Unforgivable(int d, bool c, int m, string n){
        damage = d;
        curse = c;
        vmana = m;
        name = n;
    }
    void inf(){
        cout << "Spell's name: " << name << "\n";
        cout << "Mana: " << vmana << "\n";
        cout << "Damage: " << damage << "\n"; 
        cout << "Curse: " << curse << "\n";
    }
};
// накладывающие эффекты
class Effects : public Spell {  
    public:
    int def;
    int speed;
    int damage;
    Effects(int de, int s, int da, int vm, string n){
        def = de;
        speed = s;
        damage = da;
        vmana = vm;
        name = n;
    }
    void inf(){
            cout << "Spell's name: " << name << "\n";
            cout << "Damage: " << damage << "\n";
            cout << "Deffence: " << def << "\n";
            cout << "Speed: " << speed << "\n";
            cout << "Mana: " << vmana << "\n";

    }
};

  
class Chapter{
    public:
    string name;
    vector<Spell*> spells;
    void addSpell(Spell* spell){
        spells.push_back(spell);
     }
    Chapter(Spell* s, string n){
        name = n;
        spells.push_back(s); 
    }
    void inf(){
        int S;
        cout << "Chapter's name: " << name << "\n";
        S = spells.size();
        for (int i=0; i<S; i++){
            spells[i]->inf();
        }
    }

    };



class Book{   
    public:
    vector<Chapter*> chapters;
    string name;
    Book(vector<Chapter*> c, string n){
        chapters = c;
        name = n;
    }
    void inf(){
        int S = chapters.size();
        cout<<"Book's name: "<<name<<"\n";
        cout<<"Chapters: " << "\n";
        for(int i = 0; i<S; i++){
            chapters[i]->inf();
        }

    }
    void addChapter(Chapter* c){
        chapters.push_back(c);
    }

};
#endif