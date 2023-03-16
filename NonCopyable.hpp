/** @file onion/NonCopyable.hpp
 *  @brief Contains the declaration of the NonCopyable class.
 *  <hr>
 *  @copyright 2022 André Ladeira / Onion Framework.
 */
#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

namespace onion {

/** @class NonCopyable
 *  @brief Class to make other classes non-copyable.
 *
 *  In many situations its not reasonable nor logical to let applications
 *  to create or set objects as copies of another objects.
 *  In terms os internal structure, this is usually the case of classes whose behaviour depends upon
 *  some internal state or of that encapsulate some kind of critical resource.
 *  Logically, this applies to objects that are suposed to be unique in some particular context.
 *  The later is the case of many components of the Onion Framework.
 *
 *  The purpose of the NonCopyable class is just to make this behaviour
 *  a little bit more simple to implement and evident to read.
 *
 */
class NonCopyable
{
public:
    /**
     * @brief Class constructor.
     *
     */
    NonCopyable() = default;
    /**
     * @brief Class destructor.
     *
     */
    virtual ~NonCopyable() = default;
    /**
     * @brief Class copy constructor.
     * Deleted. Therefore, derived classes can't be copy-construted.
     */
    NonCopyable( const NonCopyable& ) = delete;
    /**
     * @brief Assignement operator.
     * Deleted, so as to reinforce the idea that derived classes are not supposed to be copied.
     */
    NonCopyable& operator=( const NonCopyable& ) = delete;
};

}

#endif
