// auto-generatad C++ file for `lineitem`

#ifndef BASELINEITEMUTIL_H_
#define BASELINEITEMUTIL_H_

#include "record/Lineitem.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// pk
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::PK, VLDBDemo::Lineitem>
{
    typedef I64u FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::pk);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::pk);
    }
};

// quantity
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::QUANTITY, VLDBDemo::Lineitem>
{
    typedef I16u FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::quantity);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::quantity);
    }
};

// price
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::PRICE, VLDBDemo::Lineitem>
{
    typedef Decimal FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::price);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::price);
    }
};

// tax
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::TAX, VLDBDemo::Lineitem>
{
    typedef Decimal FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::tax);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::tax);
    }
};

// discount
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::DISCOUNT, VLDBDemo::Lineitem>
{
    typedef Decimal FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::discount);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::discount);
    }
};

// ship_date_offset
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::SHIP_DATE_OFFSET, VLDBDemo::Lineitem>
{
    typedef I16u FieldType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::shipDateOffset);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::shipDateOffset);
    }
};

// order
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::ORDER, VLDBDemo::Lineitem>
{
    typedef VLDBDemo::Order FieldType;
    // record field getter / setter types
    typedef MethodTraits<VLDBDemo::Lineitem, AutoPtr<FieldType> >::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, AutoPtr<FieldType> >::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::order);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::order);
    }
};

// product
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Lineitem>::PRODUCT, VLDBDemo::Lineitem>
{
    typedef VLDBDemo::Product FieldType;
    // record field getter / setter types
    typedef MethodTraits<VLDBDemo::Lineitem, AutoPtr<FieldType> >::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Lineitem, AutoPtr<FieldType> >::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Lineitem::product);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Lineitem::product);
    }
};

} // namespace Myriad

#endif /* BASELINEITEMUTIL_H_ */
