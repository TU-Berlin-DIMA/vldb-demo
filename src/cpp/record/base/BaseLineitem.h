// auto-generatad C++ file for `lineitem`

#ifndef BASELINEITEM_H_
#define BASELINEITEM_H_

#include "record/Record.h"
#include "record/LineitemMeta.h"
#include "record/Order.h"
#include "record/Product.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Lineitem;
class LineitemConfig;
class LineitemGenerator;
class LineitemSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseLineitem: public Record
{
public:

    BaseLineitem(const LineitemMeta& meta) : 
        _meta(meta)
    {
    }

    const LineitemMeta& meta() const
    {
        return _meta;
    }

    void price(const Decimal& v);
    const Decimal& price() const;

    void tax(const Decimal& v);
    const Decimal& tax() const;

    void shipDateOffset(const I16u& v);
    const I16u& shipDateOffset() const;

    void discount(const Decimal& v);
    const Decimal& discount() const;

    void pk(const I64u& v);
    const I64u& pk() const;

    void quantity(const I16u& v);
    const I16u& quantity() const;

    void product(const AutoPtr<Product>& v);
    const AutoPtr<Product>& product() const;

    void order(const AutoPtr<Order>& v);
    const AutoPtr<Order>& order() const;

protected:

    // meta
    const LineitemMeta& _meta;

    // fields
    Decimal _price;
    Decimal _tax;
    I16u _ship_date_offset;
    Decimal _discount;
    I64u _pk;
    I16u _quantity;

    // references
    AutoPtr<Product> _product;
    AutoPtr<Order> _order;
};

inline void BaseLineitem::price(const Decimal& v)
{
    _price = v;
}

inline const Decimal& BaseLineitem::price() const
{
    return _price;
}

inline void BaseLineitem::tax(const Decimal& v)
{
    _tax = v;
}

inline const Decimal& BaseLineitem::tax() const
{
    return _tax;
}

inline void BaseLineitem::shipDateOffset(const I16u& v)
{
    _ship_date_offset = v;
}

inline const I16u& BaseLineitem::shipDateOffset() const
{
    return _ship_date_offset;
}

inline void BaseLineitem::discount(const Decimal& v)
{
    _discount = v;
}

inline const Decimal& BaseLineitem::discount() const
{
    return _discount;
}

inline void BaseLineitem::pk(const I64u& v)
{
    _pk = v;
}

inline const I64u& BaseLineitem::pk() const
{
    return _pk;
}

inline void BaseLineitem::quantity(const I16u& v)
{
    _quantity = v;
}

inline const I16u& BaseLineitem::quantity() const
{
    return _quantity;
}

inline void BaseLineitem::product(const AutoPtr<Product>& v)
{
    _product = v;
}

inline const AutoPtr<Product>& BaseLineitem::product() const
{
    return _product;
}

inline void BaseLineitem::order(const AutoPtr<Order>& v)
{
    _order = v;
}

inline const AutoPtr<Order>& BaseLineitem::order() const
{
    return _order;
}

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<VLDBDemo::Lineitem>
{
    typedef VLDBDemo::LineitemMeta MetaType;
    typedef VLDBDemo::LineitemGenerator GeneratorType;
    typedef VLDBDemo::LineitemSetterChain SetterChainType;
    typedef RecordFactory<VLDBDemo::Lineitem> FactoryType;

    enum Field { UNKNOWN, GEN_ID, PK, QUANTITY, PRICE, TAX, DISCOUNT, SHIP_DATE_OFFSET, ORDER, PRODUCT };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::BaseLineitem>::CollectorType::serialize(OutputTraits<VLDBDemo::Lineitem>::CollectorType::StreamType& out, const VLDBDemo::BaseLineitem& record)
{
    write(out, record.pk(), false);
    out << '|';
    write(out, record.quantity(), false);
    out << '|';
    write(out, record.price(), false);
    out << '|';
    write(out, record.tax(), false);
    out << '|';
    write(out, record.discount(), false);
    out << '|';
    write(out, record.shipDateOffset(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* BASELINEITEM_H_ */
