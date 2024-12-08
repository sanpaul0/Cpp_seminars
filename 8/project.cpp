#include <iostream>
#include <vector>
#include <math.h>
#include "Spells.cpp"
#include "Warriors.cpp"
#include <fstream>
#include <sstream>

using namespace std;

struct Answer
{
    int num = 0;
    string message = "";
};


string Duel(Grunt* g, Wizard* w){
    string gaction, waction;
    string t;
    while ((g->HP > 0) && (w->HP > 0)){
        cout << "Enter grunt's action: ";
        cin >> gaction;
        cout << "Enter wizard's action: ";
        cin >> waction;            
        if ((gaction == "attack") && (w->shield)){
            cout << "You can't attack warriors with shield." << "\n";
            w->shield = false;
            }
        else if((!w->shield) && (gaction == "attack")){
                cerr << "a";
                w->HP = summury_damage(g->damage, w->HP, w->def);
            }
        else if (gaction == "Berserker"){
            g->Berserker();
        }
        if (waction == "attack"){
            g->HP = summury_damage(w->damage, g->HP, g->def);
        }
        else if (waction == "spell"){
            cout << "Enter type of spells: ";
            cin >> t;

            if (t == "attack"){
                try
                {
                    w->useAttackSpell(g);
                }
                catch (const string& error) {
                cerr << "Error: " << error << endl;
            }
            }
            else if (t == "deffence"){
                try
                {
                    w->useDeffenceSpell();
                }
                catch (const string& error) {
                cerr << "Error: " << error << endl;
            }
            }
            else if (t == "unforgivable"){
                try
                {
                    w->useUnforgivableSpell(g);
                }
                catch (const string& error) {
                cerr << "Error: " << error << endl;
            }
        }
        
    
    }
    cout << "Wizard's HP: "<< w->HP<< "\n";
    cout << w->def << "\n";
    cout << "Grunt's HP: " << g->HP<< "\n";

}
    if (g->HP == 0){
        return "g";
    }
    return "w";
}

struct Answer Battle(vector<Wizard> w, vector<Grunt> g){
    while (!w.empty() && !g.empty()){
        string res = Duel(&g[0], &w[0]);
        if (res == "w"){
            w.erase(w.begin());
        }
        else{
            g.erase(g.begin());
        }

    }
    int s;
    struct Answer ans;
    if (w.size() == 0){
        s = g.size();
         ans = {s, "Hord wins!"};
    }
    else{
        s = w.size();
        ans = {s, "Dalaran wins!"};
    }
        return ans;

}

int main(){
    string wnums, gnums;
    int wnum, gnum;
    ifstream f;
    ofstream ff;
    string err1 = "Error open file data.txt";
    string err2 = "Error convert to int";
    f.open("data.txt");
    try {
        if (!f.is_open()) {
            throw err1;
        }
        f.seekg(19, ios::beg);
        getline(f, wnums);
        f.seekg(18, ios::cur);
        getline(f, gnums);
        cout << wnums << "\n"<< gnums << "\n";        
        wnum = stoi(wnums);
        gnum = stoi(gnums);
        }
    catch (const string& error) {
        cerr << "Error: " << error << endl;
    }
    f.close();
    vector<Wizard> wizs;
    vector<Grunt> grs;
    Attack G(10, 0, 0, 15, "Grace");
    Chapter c(&G, "Attack");
    vector<Chapter*> cc = {&c};
    Book b(cc, "name");
    c.inf();
    Deffence GS(10, 5, 3, true, "God's shield");
    Unforgivable LB(170, true, 50, "Light betrayl");
    Effects AF(12, 0, 0, 0, "Armor of Fair");
    Wizard Uter(100, 12, 17, 5, 100, &G, &GS, &LB, &AF);
    Attack TS(15, 0, 0, 17, "Throw stone");
    for (int i=0; i<wnum; i++){
        wizs.push_back(Uter);
    }
    for (int i=0; i<gnum; i++){
        grs.push_back(Grunt{});
    }
    struct Answer a= Battle(wizs, grs);
    
  
    ff.open("data.txt", ios::app);  
    ff.seekp(0, ios::end);
    ff << "\n" <<  a.message << "\n" << a.num << " alive";
    ff.close();
    }