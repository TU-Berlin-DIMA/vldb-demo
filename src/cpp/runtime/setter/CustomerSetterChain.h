#ifndef CUSTOMERSETTERCHAIN_H_
#define CUSTOMERSETTERCHAIN_H_

#include "runtime/setter/base/BaseCustomerSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class CustomerSetterChain : public BaseCustomerSetterChain
{
public:

    CustomerSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseCustomerSetterChain(opMode, random, config)
    {
    }

    virtual ~CustomerSetterChain()
    {
    }
};

} // namespace VLDBDemo

#endif /* BASECUSTOMERGENERATOR_H_ */
