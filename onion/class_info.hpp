#ifndef CLASS_INFO_HPP
#define CLASS_INFO_HPP

#include <string>
#include <iostream>

namespace onion{


class ClassInfo
{
protected:

    using string = std::string;
    ClassInfo() = default;

    friend std::ostream& operator<<(std::ostream&, const ClassInfo&);
    friend std::ostream& operator<<(std::ostream&, const ClassInfo * const);

    string _name;
    string _purpose;
    string _version_tag;
};

std::ostream& operator<<(std::ostream& os, const ClassInfo& info){
    os << "Class Name  : " <<  info._name << std::endl;
    os << "Purpose     : " <<  info._purpose << std::endl;
    os << "Version     : " <<  info._version_tag << std::endl;

    return os;
}
std::ostream& operator<<(std::ostream& os, const ClassInfo * const cip ){
   return operator<<(os,*cip);
}

class COPInfo : protected ClassInfo
{
protected:

    using string = std::string;

    //COPInfo( ClassInfo, string problem, string prob_subtype):_problem(problem),_subtype(prob_subtype){}
    COPInfo() = default;

private:

    friend std::ostream& operator<<(std::ostream&, const COPInfo&);
    friend std::ostream& operator<<(std::ostream&, const COPInfo * const);
    std::string _problem;
    std::string _subtype;

};

std::ostream& operator<<(std::ostream& os, const COPInfo& info){
    os << static_cast<const ClassInfo&>(info);
    os << "Problem  : " <<  info._problem << std::endl;
    os << "Subtype  : " <<  info._subtype << std::endl;

    return os;
}
std::ostream& operator<<(std::ostream& os, const COPInfo * const cip ){
   return operator<<(os,*cip);
}

}

#endif // ONION_OBJECT_ID_HPP
