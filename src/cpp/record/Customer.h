#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "record/base/BaseCustomer.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Customer: public BaseCustomer
{
public:

    Customer(const CustomerMeta& meta)
        : BaseCustomer(meta)
    {
    }

};

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::Customer>::CollectorType::serialize(OutputTraits<VLDBDemo::Customer>::CollectorType::StreamType& out, const VLDBDemo::Customer& record)
{
    OutputTraits<VLDBDemo::BaseCustomer>::CollectorType::serialize(out, record);
}

} // namespace Myriad

#endif /* CUSTOMER_H_ */
