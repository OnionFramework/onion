#ifndef COMPONENTID_H
#define COMPONENTID_H

/** @file onion/Component.hpp
 *  @brief This header defines the Component interface and its data.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */

#include <string>
#include <sstream>
#include <ostream>

using std::string;

namespace onion{

class ComponentData{
public:

    string _name            = "Not set";  // CreateRandom
    string _type            = "Onion Framework Component";  // Create Operator
    string _description     = "Not set";  // Creates random hamiltonian cycle....
    string _version         = "v0.1.0";   // v0.1.0
    string _problem         = "Any";   // TSP, MKP ...
    string _solution_type   = "Any"; // array, bitmatrix, other
};

class SetComponentID{
public:
    SetComponentID& name(const string& name){_data._name = name; return *this;}
    SetComponentID& type(const string& type){_data._type = type; return *this;}
    SetComponentID& description(const string& desc){_data._description = desc; return *this;}
    SetComponentID& version(const string& ver){_data._version = ver; return *this;}
    SetComponentID& problem(const string& problem){_data._problem= problem; return *this;}
    SetComponentID& solution_type(const string& sol_t){_data._solution_type = sol_t; return *this;}
private:
    friend class Component;
    ComponentData _data;

};

class ComponentID
{
protected:

    ComponentID(const SetComponentID& s):_data(s._data){}
    virtual ~ComponentID() = default;

private:

    friend std::ostream& operator<<(std::ostream& os, const Component& obj);
    ComponentData _data;

public:

};


std::ostream& operator<<(std::ostream& os, const Component& c){
    os << "Name          : " << c._data._name << std::endl;
    os << "Type          : " << c._data._type << std::endl;
    os << "Description   : " << c._data._description << std::endl;
    os << "Version       : " << c._data._version << std::endl;
    os << "Problem       : " << c._data._problem << std::endl;
    os << "Solution type : " << c._data._solution_type << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Component* const c ){
   return operator<<(os,*c);
}

}

#endif // ONION_OBJECT_ID_HPP
