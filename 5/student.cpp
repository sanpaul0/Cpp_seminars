#include <iostream>
#include <string>

using namespace std;
class Student{
    private:
        const string name = "Vitya";
        const string surname = "Victor";
        string group {};
        unsigned age {};
        int knowledge {};
        float HP {};
        int money {};
        int student_time {};
        int time {};
    public:
        string grade;
        Student( string bgroup, string bgrade, unsigned bage ){
            group = bgroup;
            age = bage;
            HP = 100;
            money = 10;
            student_time = 0;
            time = 2688;
            knowledge = 0;
            grade = bgrade;
            cout << "Student has created!\n";
            }
        Student(string bgroup, string bgrade): Student(bgroup, bgrade, 19){}
        Student(string bgroup): Student(bgroup, "отл10"){}
    void get_time(){
        cout << "Time before session:" << time << "\n";
    }
    void get_HP(){
        cout << "HP:" << HP << "\n";
    }
    void get_s_time(){
        cout << "Student time:" << student_time << "\n";
    }
    void get_money(){
        cout << "Money:" << money << "\n";
    }
    void get_knowledge(){
        cout << "Knowledge:" << knowledge << "\n";
    }
    void get_all(){
        cout << "Name:" << name << "\n";
        cout << "Surname:" << surname << "\n";
        cout << "Age:" << age << "\n";
        cout << "Group:" << group << "\n";
        cout << "HP:" << HP << "\n";
        cout << "Money:" << money << "\n";
        cout << "Knowledge:" << knowledge << "\n";
        cout << "Student time:" << student_time << "\n";
        cout << "Time before session:" << time << "\n";
        cout << "Informatics grade:" << grade << "\n";
    }
    void meal(){
        if (money >=2 && student_time >= 1 && HP < 100){
            money -=2;
            student_time+=1;
            time-=1;
            HP +=2;
            if (HP > 100){
                HP = 100;
            }
        }
        else{
            cout << "error\n";
        }
    }
    void learning(int learning_time){
        int k = 2;
        time -= learning_time;
        if (learning_time > 24){
            k *= 3;
        }
            HP-=k*learning_time;
            student_time +=learning_time;
            knowledge += learning_time;

    }
    void sleep(int sleep_time){
        time-=sleep_time;
        if (sleep_time > 6){
            student_time = 0;
        }
        else{
            student_time-=sleep_time;
            }
        HP+=sleep_time*1.5;
        if (HP > 100){
            HP = 100;
        }
        }
    
    void work(int t){
        int j = 3;
        time -= t;
        if (t>24){
            j *= 3;
        }
        HP-=j*t;
        money += 2*t;
        knowledge += 3*t;
        student_time +=t;
            }
    void fun(int t){
        time -= t;
        if (money>=3*t){
            if (t>24){
                HP+=t/3;
            }
            else{
                HP+=t;
            }
            money-=3*t;
            student_time+=t;
        }
        else{
            cout << "error\n";
        }
        }
    void SVO(){
        if (money>0 || HP<90 || time < 2016){
            cout << "You can't go to SVO.\n";
        }
        else{
            money+=2000;
            HP -=85;
            student_time = 0;
            time-=2016;
        }
    }
    void session(){
        if (knowledge<800 && money < 3000){
            cout<<"Session failed. Game over.\n";
        }
        else if (knowledge >= 800 && money < 3000){
            cout << "Great! You passed all exams\n!";
        }
        else{
            cout << "Because you have a lot of money, you dropped out from uni and went to Hawaii.\n";
        }
    }
    void life(){
        string act;
        int t;
        while (time>0 && HP>0){
            cout<<"Enter the activity\n";
            cin >> act;
            if (act == "meal"){
                meal();
            }
            else if (act == "learning"){
                cout << "Enter learning time\n";
                cin >> t;
                learning(t);
            }
            else if (act == "sleep"){
                cout << "Enter sleeping time\n";
                cin >> t;
                sleep(t);
            }
            else if (act == "fun"){
                cout << "Enter funning time\n";
                cin >> t;
                fun(t);
            }
            else if (act == "work"){
                cout << "Enter working time\n";
                cin >> t;
                work(t);
            }
            else if (act == "SVO"){
                SVO();
            }
            else if (act == "inf"){
                get_all();
            }
            else if (act == "knowledge"){
                get_knowledge();
            }
            else if (act == "money"){
                get_money();
            }
            else if (act == "HP"){
                get_HP();
            }
            else if (act == "student_time"){
                get_s_time();
            }
            else if (act == "time"){
                get_time();
            }
        }
        if (HP<0){
            cout<< "You ran out of HP and took the gap year.\n";
        }
        else{
            session();
        }
    }
        

};
int main(){
    string group, grade;
    unsigned age;
    cout << "\n" << "Enter student age:";
    cin >> age;
    cout << "\n" << "Enter student's group:";
    cin >> group;
    cout << "\n" << "Enter student's grade:";
    cin >> grade;
    if (age==0 && grade == ""){
        Student Vitya(group);
        Vitya.get_all();
        cout << "So, let's start the game!\n";
        Vitya.life();
    }
    else if (age == 0){
        Student Vitya(group, grade);
        Vitya.get_all();
        cout << "So, let's start the game!\n";
        Vitya.life();
    }
    else{
        Student Vitya(group, grade, age);
        Vitya.get_all();
        cout << "So, let's start the game! Your aim is passing session and be alive.\n";
        Vitya.life();
    }
   
    
}