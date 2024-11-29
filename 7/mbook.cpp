#include <iostream>
#include <vector>
#include <math.h>

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
        return hp;
    }
    else{
        return hp - da;
    }
}
    

class Spell{
    public:\
    string name;
    int vmana; //расход маны колдуна
    virtual void inf() = 0;
};

// атака
class Attack : public Spell { //1
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
class Deffence : public Spell {    //2
    public:
    int HP;
    int def;
    bool shield;
    Deffence(int HP, int d, int m, bool s, string n){
        HP = HP;
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
//быт
class Household : public Spell {   //3
    public:
    string effect;
    Household(string e, int m, string n){
        effect = e;
        vmana = m;
        name = n;
    }
    void inf(){
        cout << "Spell's name: " << name << "\n";
        cout << "Mana: " << vmana << "\n";
    }
};
//непростительные
class Unforgivable : public Spell {   //4
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
class Effects : public Spell {  //5
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

class Warrior : public Creature{
    public:
    Warrior(int h, int de, int da, int s){
        damage = da;
        HP = h;
        def = de;
        speed = s;
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
};

class Visard: public Creature{   
    public:
        int mana;
        Attack* attack;
        Deffence* deffence;
        Household* household;
        Unforgivable* unforgivable;
        Effects* effect; 

        Visard(int H, int De, int Da, int S, int m, Attack* a, Deffence* d, Household* h, Unforgivable* u, Effects* e){
            attack = a;
            deffence = d;
            household = h;
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
            cout << "Household spell: " << household->name << "\n";
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
            HP = summ(HP, deffence->HP);
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

int main(){
    Attack* G = new Attack(10, 0, 0, 15, "Grace");
    Chapter* c = new Chapter(G, "Attack");
    vector<Chapter*> cc = {c};
    Book b(cc, "name");
    c->inf();
    Deffence* GS = new Deffence(5, 3, 10, true, "God's shield");
    Unforgivable* LB = new Unforgivable(25, true, 50, "Light betrayl");
    Effects* AF = new Effects(12, 0, 0, 0, "Armor of Fair");
    Household* WD = new Household("Fast washing dish", 10, "Wash dish");
    Visard Uter = Visard(100, 0, 7, 5, 100, G, GS, WD, LB, AF);
    Warrior* w = new Warrior(100, 0, 15, 10);
    try
    {
        Uter.useAttackSpell(w);
    }
    catch (const string& error) {
    cerr << "Error: " << error << endl;
    }
    w->inf();
    try
    {
        Uter.useUnforgivableSpell(w);
    }
    catch (const string& error) {
    cerr << "Error: " << error << endl;
    }
    w->inf();
    
    try
    {
        Uter.useUnforgivableSpell(w);
    }
    catch (const string& error) {
    cerr << "Error: " << error << endl;
  }
    Uter.inf();
    }
    
    

    

