// auto-generatad C++ file for `product`

#ifndef BASEPRODUCTUTIL_H_
#define BASEPRODUCTUTIL_H_

#include "record/Product.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// pk
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Product>::PK, VLDBDemo::Product>
{
    typedef I64u FieldType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Product::pk);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Product::pk);
    }
};

// name
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Product>::NAME, VLDBDemo::Product>
{
    typedef String FieldType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Product::name);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Product::name);
    }
};

// type
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Product>::TYPE, VLDBDemo::Product>
{
    typedef Enum FieldType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Product::type);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Product::type);
    }
};

// retail_price
template<>
struct RecordFieldTraits<RecordTraits<VLDBDemo::Product>::RETAIL_PRICE, VLDBDemo::Product>
{
    typedef Decimal FieldType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Setter FieldSetterType;
    typedef typename MethodTraits<VLDBDemo::Product, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&VLDBDemo::Product::retailPrice);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&VLDBDemo::Product::retailPrice);
    }
};

} // namespace Myriad

#endif /* BASEPRODUCTUTIL_H_ */
