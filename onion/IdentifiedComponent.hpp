#ifndef IDENTIFIEDCOMPONENT_H
#define IDENTIFIEDCOMPONENT_H

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

/** @class RandomEngineProxy
 *  @brief Creates and control the access to the global RandonEngine object.
 *
 *  The Onion Framework recomends that random number generation to be both centralized
 *  and homogeneous, i.e., use a single algorithm. A discussion on this subject is presented
 *  [(here)](@ref onion/Random.hpp).
 *
 *  All RandomEngineProxy methods are private. RNG functionalities are accessed using the
 *  Random() and SetRandomEngine functions.
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

/** @class RandomEngineProxy
 *  @brief Creates and control the access to the global RandonEngine object.
 *
 *  The Onion Framework recomends that random number generation to be both centralized
 *  and homogeneous, i.e., use a single algorithm. A discussion on this subject is presented
 *  [(here)](@ref onion/Random.hpp).
 *
 *  All RandomEngineProxy methods are private. RNG functionalities are accessed using the
 *  Random() and SetRandomEngine functions.
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

/** @class RandomEngineProxy
 *  @brief Creates and control the access to the global RandonEngine object.
 *
 *  The Onion Framework recomends that random number generation to be both centralized
 *  and homogeneous, i.e., use a single algorithm. A discussion on this subject is presented
 *  [(here)](@ref onion/Random.hpp).
 *
 *  All RandomEngineProxy methods are private. RNG functionalities are accessed using the
 *  Random() and SetRandomEngine functions.
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

/** @class RandomEngineProxy
 *  @brief Creates and control the access to the global RandonEngine object.
 *
 *  The Onion Framework recomends that random number generation to be both centralized
 *  and homogeneous, i.e., use a single algorithm. A discussion on this subject is presented
 *  [(here)](@ref onion/Random.hpp).
 *
 *  All RandomEngineProxy methods are private. RNG functionalities are accessed using the
 *  Random() and SetRandomEngine functions.
 *
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
std::ostream& operator<<(std::ostream& os, const IdentifiedComponent* const c ){
   return operator<<(os,*c);
}

}

#endif // ONION_OBJECT_ID_HPP
