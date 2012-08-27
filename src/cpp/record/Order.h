#ifndef ORDER_H_
#define ORDER_H_

#include "record/base/BaseOrder.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Order: public BaseOrder
{
public:

    Order(const OrderMeta& meta)
        : BaseOrder(meta)
    {
    }

};

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::Order>::CollectorType::serialize(OutputTraits<VLDBDemo::Order>::CollectorType::StreamType& out, const VLDBDemo::Order& record)
{
    write(out, record.pk(), false);
    out << '|';
    write(out, record.customer()->pk(), false);
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

#endif /* ORDER_H_ */
