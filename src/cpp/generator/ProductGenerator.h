#ifndef PRODUCTGENERATOR_H_
#define PRODUCTGENERATOR_H_

#include "generator/base/BaseProductGenerator.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class ProductGenerator: public BaseProductGenerator
{
public:

    typedef RecordTraits<Product>::SetterChainType SetterChainType;

    ProductGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseProductGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTGENERATOR_H_ */
