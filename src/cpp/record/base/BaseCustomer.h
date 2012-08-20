// auto-generatad C++ file for `customer`

#ifndef BASECUSTOMER_H_
#define BASECUSTOMER_H_

#include "record/Record.h"
#include "record/CustomerMeta.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Customer;
class CustomerConfig;
class CustomerGenerator;
class CustomerSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseCustomer: public Record
{
public:

    BaseCustomer(const CustomerMeta& meta) : 
        _meta(meta)
    {
    }

    const CustomerMeta& meta() const
    {
        return _meta;
    }

    void firstName(const Enum& v);
    const Enum& firstName() const;
    const String& firstNameEnumValue() const;

    void lastName(const Enum& v);
    const Enum& lastName() const;
    const String& lastNameEnumValue() const;

    void ordersCount(const I32u& v);
    const I32u& ordersCount() const;

    void gender(const Enum& v);
    const Enum& gender() const;
    const String& genderEnumValue() const;

    void age(const I16u& v);
    const I16u& age() const;

    void pk(const I64u& v);
    const I64u& pk() const;

protected:

    // meta
    const CustomerMeta& _meta;

    // fields
    Enum _first_name;
    Enum _last_name;
    I32u _orders_count;
    Enum _gender;
    I16u _age;
    I64u _pk;
};

inline void BaseCustomer::firstName(const Enum& v)
{
    _first_name = v;
}

inline const Enum& BaseCustomer::firstName() const
{
    return _first_name;
}

inline const String& BaseCustomer::firstNameEnumValue() const
{
    return _meta.first_name[_first_name];
}

inline void BaseCustomer::lastName(const Enum& v)
{
    _last_name = v;
}

inline const Enum& BaseCustomer::lastName() const
{
    return _last_name;
}

inline const String& BaseCustomer::lastNameEnumValue() const
{
    return _meta.last_name[_last_name];
}

inline void BaseCustomer::ordersCount(const I32u& v)
{
    _orders_count = v;
}

inline const I32u& BaseCustomer::ordersCount() const
{
    return _orders_count;
}

inline void BaseCustomer::gender(const Enum& v)
{
    _gender = v;
}

inline const Enum& BaseCustomer::gender() const
{
    return _gender;
}

inline const String& BaseCustomer::genderEnumValue() const
{
    return _meta.gender[_gender];
}

inline void BaseCustomer::age(const I16u& v)
{
    _age = v;
}

inline const I16u& BaseCustomer::age() const
{
    return _age;
}

inline void BaseCustomer::pk(const I64u& v)
{
    _pk = v;
}

inline const I64u& BaseCustomer::pk() const
{
    return _pk;
}

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<VLDBDemo::Customer>
{
    typedef VLDBDemo::CustomerMeta MetaType;
    typedef VLDBDemo::CustomerGenerator GeneratorType;
    typedef VLDBDemo::CustomerSetterChain SetterChainType;
    typedef RecordFactory<VLDBDemo::Customer> FactoryType;

    enum Field { UNKNOWN, GEN_ID, PK, FIRST_NAME, LAST_NAME, GENDER, AGE, ORDERS_COUNT };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::BaseCustomer>::CollectorType::serialize(OutputTraits<VLDBDemo::Customer>::CollectorType::StreamType& out, const VLDBDemo::BaseCustomer& record)
{
    write(out, record.pk(), false);
    out << '|';
    write(out, record.firstNameEnumValue(), false);
    out << '|';
    write(out, record.lastNameEnumValue(), false);
    out << '|';
    write(out, record.genderEnumValue(), false);
    out << '|';
    write(out, record.age(), false);
    out << '|';
    write(out, record.ordersCount(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* BASECUSTOMER_H_ */
