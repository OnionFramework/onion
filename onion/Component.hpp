#ifndef COMPONENT_H
#define COMPONENT_H

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

    string _name;  // CreateRandom
    string _type;  // Create Operator
    string _description;  // Creates random hamiltonian cycle....
    string _version;   // v0.1.0
    string _problem;   // TSP, MKP ...
    string _solution_type; // array, bitmatrix, other
};

class SetComponent{
public:
    SetComponent& name(const string& name){_data._name = name; return *this;}
    SetComponent& type(const string& type){_data._type = type; return *this;}
    SetComponent& description(const string& desc){_data._description = desc; return *this;}
    SetComponent& version(const string& ver){_data._version = ver; return *this;}
    SetComponent& problem(const string& problem){_data._problem= problem; return *this;}
    SetComponent& solution_type(const string& sol_t){_data._solution_type = sol_t; return *this;}
private:
    friend class Component;
    ComponentData _data;

};

class Component
{
protected:

    Component(const SetComponent& s):_data(s._data){}
    ~Component() = default;

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
