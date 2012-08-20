// auto-generatad C++ file for `order`

#ifndef BASEORDER_H_
#define BASEORDER_H_

#include "record/Record.h"
#include "record/OrderMeta.h"
#include "record/Customer.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Order;
class OrderConfig;
class OrderGenerator;
class OrderSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseOrder: public Record
{
public:

    BaseOrder(const OrderMeta& meta) : 
        _meta(meta)
    {
    }

    const OrderMeta& meta() const
    {
        return _meta;
    }

    void status(const Enum& v);
    const Enum& status() const;
    const String& statusEnumValue() const;

    void pk(const I64u& v);
    const I64u& pk() const;

    void totalPrice(const Decimal& v);
    const Decimal& totalPrice() const;

    void lineitemsCount(const I32u& v);
    const I32u& lineitemsCount() const;

    void orderDate(const Date& v);
    const Date& orderDate() const;

    void customer(const AutoPtr<Customer>& v);
    const AutoPtr<Customer>& customer() const;

protected:

    // meta
    const OrderMeta& _meta;

    // fields
    Enum _status;
    I64u _pk;
    Decimal _total_price;
    I32u _lineitems_count;
    Date _order_date;

    // references
    AutoPtr<Customer> _customer;
};

inline void BaseOrder::status(const Enum& v)
{
    _status = v;
}

inline const Enum& BaseOrder::status() const
{
    return _status;
}

inline const String& BaseOrder::statusEnumValue() const
{
    return _meta.status[_status];
}

inline void BaseOrder::pk(const I64u& v)
{
    _pk = v;
}

inline const I64u& BaseOrder::pk() const
{
    return _pk;
}

inline void BaseOrder::totalPrice(const Decimal& v)
{
    _total_price = v;
}

inline const Decimal& BaseOrder::totalPrice() const
{
    return _total_price;
}

inline void BaseOrder::lineitemsCount(const I32u& v)
{
    _lineitems_count = v;
}

inline const I32u& BaseOrder::lineitemsCount() const
{
    return _lineitems_count;
}

inline void BaseOrder::orderDate(const Date& v)
{
    _order_date = v;
}

inline const Date& BaseOrder::orderDate() const
{
    return _order_date;
}

inline void BaseOrder::customer(const AutoPtr<Customer>& v)
{
    _customer = v;
}

inline const AutoPtr<Customer>& BaseOrder::customer() const
{
    return _customer;
}

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<VLDBDemo::Order>
{
    typedef VLDBDemo::OrderMeta MetaType;
    typedef VLDBDemo::OrderGenerator GeneratorType;
    typedef VLDBDemo::OrderSetterChain SetterChainType;
    typedef RecordFactory<VLDBDemo::Order> FactoryType;

    enum Field { UNKNOWN, GEN_ID, PK, STATUS, TOTAL_PRICE, ORDER_DATE, LINEITEMS_COUNT, CUSTOMER };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::BaseOrder>::CollectorType::serialize(OutputTraits<VLDBDemo::Order>::CollectorType::StreamType& out, const VLDBDemo::BaseOrder& record)
{
    write(out, record.pk(), false);
    out << '|';
    write(out, record.statusEnumValue(), false);
    out << '|';
    write(out, record.totalPrice(), false);
    out << '|';
    write(out, record.orderDate(), false);
    out << '|';
    write(out, record.lineitemsCount(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* BASEORDER_H_ */
