#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Item.h"

using namespace std;

class NPC {
private:
    string script;
    vector<Item> commodity;
public:
    // NPC();
    // NPC(string, string, vector<Item>);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item>);
    string getScript();
    vector<Item> getCommodity();
};


#endif // NPC_H_INCLUDED
