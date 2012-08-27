#ifndef PRODUCTSETTERCHAIN_H_
#define PRODUCTSETTERCHAIN_H_

#include "runtime/setter/base/BaseProductSetterChain.h"

#include <Poco/NumberFormatter.h>

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class ProductSetterChain : public BaseProductSetterChain
{
public:

    ProductSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseProductSetterChain(opMode, random, config),
        _productNamePrefix("PRODUCT #")
    {
    }

    virtual ~ProductSetterChain()
    {
    }

    virtual String setProductName(const AutoPtr<Product>& recordPtr, RandomStream& random)
    {
        String productName(_productNamePrefix);
        NumberFormatter::append0(productName, recordPtr->pk(), 6);
        return productName;
    }

private:

    const String _productNamePrefix;
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTGENERATOR_H_ */
