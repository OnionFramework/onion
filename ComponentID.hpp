/** @file onion/ComponentID.hpp
 *  @brief This header contains the classes used to identify a component of the Onion Framework.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */

#pragma once

#include <string>
#include <ostream>

using std::string;

namespace onion{

/** @class ComponentData
 *  @brief This class contains the data used to identify a component.
 *
 *  The Onion Framework is structured around extensible components that can become quite complex.
 *  This class contains data used to clearly identify each component.
 *
 */
class ComponentData{
public:
    /** @brief Name of the component. Usually the name of the Class.
     */
    string name            = "Not set";
    /** @brief Component type. Ex: CreateOperator, SelectOperator Decorator etc..."
     */
    string type            = "Onion Framework Component";
    /** @brief A compact description of what the component does.
     *  Ex: Creates a random hamiltonian cycle...."
     */
    string description     = "Not set";
    /** @brief Ccomponent version. Used to identify it unambiguously."
     */
    string version         = "v0.1.0";
    /** @brief The problem it belongs to.
     *  TSP, MKP etc..."
     */
    string problem         = "Any";   // TSP, MKP ...
//    /** @brief Solution type.
//     *  It defines the domain to which the component belongs."
//     */
//    string solution_type   = "Any"; // array, bitmatrix, other
};

/** @class IDBuilder
 *  @brief Builder to create a componentID
 *
 *  The onion framework uses a simplified version of the Builder Pattern to create
 *  objects that have certain characteristics, as explained
 *  <a href="md__glossary.html#builder_pattern">here</a>.
 *
 */
class IDBuilder{
public:

    IDBuilder& name(const string& name)            {_id.name           = name;     return *this;}
    IDBuilder& type(const string& type)            {_id.type           = type;     return *this;}
    IDBuilder& description(const string& desc)     {_id.description    = desc;     return *this;}
    IDBuilder& version(const string& ver)          {_id.version        = ver;      return *this;}
    IDBuilder& problem(const string& problem)      {_id.problem        = problem;  return *this;}

    friend class ComponentID;
    ComponentData _id;

};

/** @class ComponentID
 *  @brief Base class used to provide identification functionalities to concrete implementations of the Onion components.
 *
 *  Classes that implement any of the four basic Onion components (CreateOperator, PerturbationOperator,
 *  ObjectiveFunction and SelectOperator) must inherit from ComponentID in order to be identifiable within
 *  the framework.
 *
 *
 */
class ComponentID
{
protected:
    /**
     * @brief Class constructor.
     * @param builder ComponentIDBuilder instance.
     *
     * The onion framework uses a simplified version of the
     * <a href="md__glossary.html#builder_pattern">Builder Pattern</a> to create some special objects.
     * In summary, its a clever way to have constructors that have named parameters that also
     * can be called in any order or combination.
     *
     * Example:
     *
     *     ComponentID myClass( IDBuilder().name("My Class")
     *                                     .description("My class purpose is...")
     *                                     .version("1.0.0") );
     */
    ComponentID(const IDBuilder& builder):_id(builder._id){}
    /**
     * @brief Class destructor
     */
    ~ComponentID() = default;

private:

    friend std::ostream& operator<<(std::ostream& os, const ComponentID& id);
    ComponentData _id;
};

/** @brief Outputs a component ID to a stream in a user readable format.
 *  @param [in] os the output stream
 *  @param [in] id a constant reference to the component whose ID is to be printed.
 *  @return the os output stream, so it can be used in sequence.
 */
std::ostream& operator<<(std::ostream& os, const ComponentID& id){
    os << "Name          : " << id._id.name << std::endl;
    os << "Type          : " << id._id.type << std::endl;
    os << "Description   : " << id._id.description << std::endl;
    os << "Version       : " << id._id.version << std::endl;
    os << "Problem       : " << id._id.problem << std::endl;
//    os << "Solution type : " << c._id.solution_type << std::endl;
    return os;
}
/** @brief Outputs a component ID to a stream in a user readable format.
 *  @param [in] os the output stream
 *  @param [in] id a constant pointer to the component whose ID is to be printed.
 *  @return The os output stream, so it can be in sequence.
 */
std::ostream& operator<<(std::ostream& os, const ComponentID* const id ){
   return operator<<(os,*id);
}

}
