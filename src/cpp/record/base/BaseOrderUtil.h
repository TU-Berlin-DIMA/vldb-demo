// auto-generatad C++ file for `order`

#ifndef BASEORDERUTIL_H_
#define BASEORDERUTIL_H_

#include "record/Order.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// pk
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::PK, VLDBDemo::Order>
{
    typedef I64u FieldType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::pk);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::pk);
    }
};

// status
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::STATUS, VLDBDemo::Order>
{
    typedef Enum FieldType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::status);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::status);
    }
};

// total_price
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::TOTAL_PRICE, VLDBDemo::Order>
{
    typedef Decimal FieldType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::totalPrice);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::totalPrice);
    }
};

// order_date
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::ORDER_DATE, VLDBDemo::Order>
{
    typedef Date FieldType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::orderDate);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::orderDate);
    }
};

// lineitems_count
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::LINEITEMS_COUNT, VLDBDemo::Order>
{
    typedef I32u FieldType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::lineitemsCount);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::lineitemsCount);
    }
};

// customer
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Order>::CUSTOMER, VLDBDemo::Order>
{
    typedef VLDBDemo::Customer FieldType;
    // record field getter / setter types
    typedef MethodTraits<VLDBDemo::Order, AutoPtr<FieldType> >::Setter FieldSetterType;
    typedef MethodTraits<VLDBDemo::Order, AutoPtr<FieldType> >::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Order::customer);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Order::customer);
    }
};

} // namespace Myriad

#endif /* BASEORDERUTIL_H_ */
