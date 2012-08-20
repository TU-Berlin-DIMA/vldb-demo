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
    OutputTraits<VLDBDemo::BaseOrder>::CollectorType::serialize(out, record);
}

} // namespace Myriad

#endif /* ORDER_H_ */
