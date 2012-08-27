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
    out << '\n';
}

} // namespace Myriad

#endif /* CUSTOMER_H_ */
