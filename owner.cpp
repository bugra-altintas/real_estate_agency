#include <iostream>
#include <string>
#include <vector>
#include "owner.h"

using namespace std;

Owner::Owner()
{
    name = "";
    balance = 0.0;

}

Owner::Owner(const string &name, float balance)
{
    this->name = name;
    this->balance = balance;
}

void Owner::print_info()
{
}

string &Owner::get_name()
{
    return this->name;
}

void Owner::add_property(Property *property)
{
    (this->properties).push_back(property);
}

void Owner::buy(Property *property, Owner *seller)
{
    cout << "[BUY] Property: " << property->get_name() << " Value: " << property->valuate() << "$ " << seller->get_name() << "--->" << get_name() << endl; 
    bool found = false;
    int pos;
    for(int i = 0; i<(seller->properties).size();i++){
        if((seller->properties)[i] ==  property){
            pos = i;
            found = true;
            break;
        }
    }
    if(balance>=(*property).valuate()){
        if(found){
            balance -= (*property).valuate();
            seller->balance += (*property).valuate();
            (seller->properties).erase((seller->properties).begin()+pos);
            add_property(property);
            property->set_owner(this);
        }
        else{
            cout << "[ERROR] Transaction  on  unowned  property" << endl;
        }
    }
    else{
        cout << "[ERROR] Unaffordable  property" << endl;
    }
}

void Owner::sell(Property *property, Owner *owner)
{
    cout << "[SELL] Property: " << property->get_name() << " Value: " << property->valuate() << "$ " << get_name() << "--->" << owner->get_name() << endl; 
    bool found = false;
    int pos;
    for(int i = 0; i<properties.size();i++){
        if(properties[i] ==  property){
            pos = i;
            found = true;
            break;
        }
    }
    if(owner->balance>=(*property).valuate()){
        if(found){
            owner->balance -= (*property).valuate();
            balance += (*property).valuate();
            properties.erase(properties.begin() + pos);
            owner->add_property(property);
            property->set_owner(owner);
        }
        else{
            cout << "[ERROR] Transaction  on  unowned  property" << endl;
        }
    }
    else{
        cout << "[ERROR] Unaffordable  property" << endl;
    }
}

void Owner::list_properties()
{
    cout << "Properties of " << get_name() << ":" << endl;
    cout << "Balance: " << balance << "$" << endl;
    for(int i = 0; i<properties.size();i++){
        cout << i+1 << ". " << properties[i]->get_name() << endl; 
    }

}