#ifndef PRODUCTSETTERCHAIN_H_
#define PRODUCTSETTERCHAIN_H_

#include "runtime/setter/base/BaseProductSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class ProductSetterChain : public BaseProductSetterChain
{
public:

    ProductSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseProductSetterChain(opMode, random, config)
    {
    }

    virtual ~ProductSetterChain()
    {
    }

    virtual String setProductName(const AutoPtr<Product>& recordPtr, RandomStream& random)
    {
        return format("PRODUCT #%06Lu", recordPtr->pk());
    }
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTGENERATOR_H_ */
