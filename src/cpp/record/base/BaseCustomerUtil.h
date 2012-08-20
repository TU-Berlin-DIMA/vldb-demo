// auto-generatad C++ file for `customer`

#ifndef BASECUSTOMERUTIL_H_
#define BASECUSTOMERUTIL_H_

#include "record/Customer.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// pk
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::PK, VLDBDemo::Customer>
{
    typedef I64u FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::pk);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::pk);
    }
};

// first_name
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::FIRST_NAME, VLDBDemo::Customer>
{
    typedef Enum FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::firstName);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::firstName);
    }
};

// last_name
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::LAST_NAME, VLDBDemo::Customer>
{
    typedef Enum FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::lastName);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::lastName);
    }
};

// gender
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::GENDER, VLDBDemo::Customer>
{
    typedef Enum FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::gender);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::gender);
    }
};

// age
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::AGE, VLDBDemo::Customer>
{
    typedef I16u FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::age);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::age);
    }
};

// orders_count
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Customer>::ORDERS_COUNT, VLDBDemo::Customer>
{
    typedef I32u FieldType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Customer, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Customer::ordersCount);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Customer::ordersCount);
    }
};

} // namespace Myriad

#endif /* BASECUSTOMERUTIL_H_ */
