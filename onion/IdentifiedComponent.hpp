/** @file onion/IdentifiedComponent.hpp
 *  @brief This header contains the classes used to identify a component of the Onion Framework.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */

#ifndef IDENTIFIEDCOMPONENT_H
#define IDENTIFIEDCOMPONENT_H

#include <string>
#include <ostream>

using std::string;

namespace onion{

/** @class ComponentID
 *  @brief Defines the data used to identify a component.
 *
 *  The Onion framework is structured around extensible components. This class contains data used to
 *  clearly identify each component.
 *
 */
class ComponentID{
public:

    string name            = "Not set";  // CreateRandom
    string type            = "Onion Framework Component";  // Create Operator
    string description     = "Not set";  // Creates random hamiltonian cycle....
    string version         = "v0.1.0";   // v0.1.0
    string problem         = "Any";   // TSP, MKP ...
    string solution_type   = "Any"; // array, bitmatrix, other
};

/** @class ComponentIdBuilder
 *  @brief Builder to create a componentID
 *
 *  The onion framework uses a simplified version of the Builder Pattern to create objects that have certain characteristics.
 *  A thorough explanation on this is presented [(here)](@ref BUILDERPATTERNPAGE).
 *
 */
class ComponentIdBuilder{
public:

    ComponentIdBuilder& name(const string& name)            {_id.name           = name;     return *this;}
    ComponentIdBuilder& type(const string& type)            {_id.type           = type;     return *this;}
    ComponentIdBuilder& description(const string& desc)     {_id.description    = desc;     return *this;}
    ComponentIdBuilder& version(const string& ver)          {_id.version        = ver;      return *this;}
    ComponentIdBuilder& problem(const string& problem)      {_id.problem        = problem;  return *this;}
    ComponentIdBuilder& solution_type(const string& sol_t)  {_id.solution_type  = sol_t;    return *this;}

private:

    friend class IdentifiedComponent;
    ComponentID _id;

};

/** @class IdentifiedComponent
 *  @brief Onion components derive from this class in order to add identification functionality.
 *
 */
class IdentifiedComponent
{
protected:

    IdentifiedComponent(const ComponentIdBuilder& s):_id(s._id){}
    ~IdentifiedComponent() = default;

private:

    friend std::ostream& operator<<(std::ostream& os, const IdentifiedComponent& obj);
    ComponentID _id;
};

/** @brief Outputs a component ID to a stream in a user readable format.
 *  @param [in] os the output stream
 *  @param [in] c a constant reference to the component whose ID is to be printed.
 *  @return The os output stream, so it can be used in sequence.
 */
std::ostream& operator<<(std::ostream& os, const IdentifiedComponent& c){
    os << "Name          : " << c._id.name << std::endl;
    os << "Type          : " << c._id.type << std::endl;
    os << "Description   : " << c._id.description << std::endl;
    os << "Version       : " << c._id.version << std::endl;
    os << "Problem       : " << c._id.problem << std::endl;
    os << "Solution type : " << c._id.solution_type << std::endl;
    return os;
}
/** @brief Outputs a component ID to a stream in a user readable format.
 *  @param [in] os the output stream
 *  @param [in] c a constant pointer to the component whose ID is to be printed.
 *  @return The os output stream, so it can be in sequence.
 */
std::ostream& operator<<(std::ostream& os, const IdentifiedComponent* const c ){
   return operator<<(os,*c);
}

}

#endif // ONION_OBJECT_ID_HPP
