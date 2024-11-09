#include <iostream>
#include <string>
#define N 5

using namespace std;

struct FIO{
    string Name = "Unknown";
    string Surname = "Unknown";
};


class Animal{
    public:
       virtual void makeSound() = 0;
};

class Cat : public Animal {
    private:
        int years;
        int HP;
        string breed;
        string name;
    public:
        virtual void makeSound(){
            cout << "Meow\n";
         }
        Cat(string abreed, string aname, int ayears){
            years = ayears;
            name = aname;
            HP = 100;
            breed = abreed;
            cout << "\nBreed:" << abreed << "\nName:" << aname << "\nAge:" << ayears;
        }
        Cat(){
            years = 0;
            name = "Unknown";
            HP = 100;
            breed = "Unknown";
        }
        void show_inf(){
            cout << "Name:" << name << "\n";
            cout << "Breed:" << breed << "\n";
            cout << "Age:" << years << "\n";
            cout << "HP:" << HP << "\n";
        }
        friend class Vet;
};

class Dog : public Animal {
    private:
        int years;
        int HP;
        string breed;
        string name;
    public:
        Dog(string abreed, string aname, int ayears){
            years = ayears; 
            HP = 100;
            name = aname;
            breed = abreed;
           
            cout << "\nBreed:" << abreed << "\nName:" << aname << "\nAge:" << ayears;
        }
        Dog(){
            years = 0;
            name = "Unknown";
            HP = 100;
            breed = "Unknown";
        }
        virtual void makeSound(){
            cout << "Gav\n";
        }
        void show_inf(){
            cout << "Name:" << name << "\n";
            cout << "Breed:" << breed << "\n";
            cout << "Age:" << years << "\n";
            cout << "HP:" << HP << "\n";
        }
        friend class Vet; 
            
};

class Master{
    private:
        struct FIO FIO;
        int age;
        int ncats;
        int ndogs;
        Cat** cats;
        Dog dog;
    public:
        Master(string name, string surname, int aage, int ancats, int andogs, Dog d, Cat** c){
            FIO.Name = name;
            FIO.Surname = surname;
            age = aage;
            ncats = ancats;
            ndogs = andogs; 
            this->dog = d;
            cats = c;
        }
        friend class Vet;

};

class Vet{
    private:
        struct FIO FIo;
    public:
        Vet(string name, string surname){
            FIo.Name = name;
            FIo.Surname = surname;
        }
        void medex(Master* m, string animal){
            if (animal == "cat"){
                for (int i=0; i<N; i++){
                    m->cats[i]->HP +=10;
                    m->cats[i]->show_inf();
                }
                
            }
            else{
                m->dog.HP +=10;
                m->dog.show_inf();
        
            }
        }
        void talkToMaster(Master* m){
            cout << "I talk with" << m->FIO.Name << " " << m->FIO.Surname; 
        }

};

int main(){
    string cname, cbreed;
    int cage;
    Cat* cats[N];
    for (int i=0; i<N; i++){
        cout << "\nEnter cat's name:";
        cin >> cname;
        cout << "\nEnter cat's breed:";
        cin >> cbreed;
        cout << "\nEnter cat's age:";
        cin >> cage;       
        cats[i] = new Cat(cbreed, cname, cage); 
    }
    Cat** c =cats;
    string dname, dbreed;
    int dage;
    cout << "\nEnter dog's name:";
    cin >> dname;
    cout << "\nEnter dog's breed:";
    cin >> dbreed;
    cout << "\nEnter dog's age:";
    cin >> dage;
    Dog dog1(dbreed, dname, dage);
    string mname, msurname;
    int mage;
    cout << "\nEnter master's name:";
    cin >> mname;
    cout << "\nEnter master's surname:";
    cin >> msurname;
    cout << "\nEnter master's age:";
    cin >> mage;
    Master master1(mname, msurname, mage, 1, 1, dog1, c);
    Master* m;
    m = &master1;
    cats[1]->makeSound();
    dog1.makeSound();
    Vet v = Vet("Ivan", "Ivanov");
    v.medex(m, "dog");
    
}
