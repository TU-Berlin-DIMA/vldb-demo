#ifndef LINEITEMSETTERCHAIN_H_
#define LINEITEMSETTERCHAIN_H_

#include "runtime/setter/base/BaseLineitemSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class LineitemSetterChain : public BaseLineitemSetterChain
{
public:

    LineitemSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseLineitemSetterChain(opMode, random, config)
    {
    }

    virtual ~LineitemSetterChain()
    {
    }

    virtual Decimal setPrice(const AutoPtr<Lineitem>& recordPtr, RandomStream& random)
    {
        return (1.0 - recordPtr->discount() + recordPtr->tax()) * recordPtr->product()->retailPrice();
    }
};

} // namespace VLDBDemo

#endif /* BASELINEITEMGENERATOR_H_ */
