#ifndef ORDERSETTERCHAIN_H_
#define ORDERSETTERCHAIN_H_

#include "runtime/setter/base/BaseOrderSetterChain.h"
#include "runtime/provider/value/AggregateChildFieldValueProvider.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class OrderSetterChain : public BaseOrderSetterChain
{
public:

    OrderSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseOrderSetterChain(opMode, random, config)
    {
    }

    virtual ~OrderSetterChain()
    {
    }

    virtual Decimal setTotalPrice(const AutoPtr<Order>& recordPtr, RandomStream& random)
    {
        return 0;
    }
};

} // namespace VLDBDemo

#endif /* BASEORDERGENERATOR_H_ */
