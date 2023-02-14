#ifndef CLASS_INFO_HPP
#define CLASS_INFO_HPP

#include <string>
#include <iostream>
#include "non_copyable.hpp"

namespace onion{


class ClassInfo
{
public:

    struct Data{
        std::string _name;
        std::string _purpose;
        std::string _version_tag;
    };

    struct ClassInfoSet{

        ClassInfoSet() = default;
        ClassInfoSet& name(const std::string name ) { _data._name = name; return *this; }
        ClassInfoSet& purpose(const std::string purp ) { _data._purpose = purp; return *this; }
        ClassInfoSet& version_tag(const std::string ver ) { _data._version_tag = ver; return *this; }

        friend std::ostream& operator<<(std::ostream& , const ClassInfo& );
        friend std::ostream& operator<<(std::ostream& , const ClassInfo * const);
        friend class ClassInfo;

    protected:

        Data _data;

    };

    ClassInfo(const ClassInfoSet& info);
    ~ClassInfo() = default;

    friend std::ostream& operator<<(std::ostream& , const ClassInfo& );
    friend std::ostream& operator<<(std::ostream& , const ClassInfo* );

private:

    Data _data;

};

ClassInfo::ClassInfo(const ClassInfoSet& info){
    _data._name        = info._data._name;
    _data._purpose     = info._data._purpose;
    _data._version_tag = info._data._version_tag;
}

std::ostream& operator<<(std::ostream& os, const ClassInfo& ci){
    os << "Class Name  : " <<  ci._data._name << std::endl;
    os << "Purpose     : " <<  ci._data._purpose << std::endl;
    os << "Version     : " <<  ci._data._version_tag << std::endl;

    return os;
}
std::ostream& operator<<(std::ostream& os, const ClassInfo * const cip ){
   return operator<<(os,*cip);
}

}

#endif // ONION_OBJECT_ID_HPP
