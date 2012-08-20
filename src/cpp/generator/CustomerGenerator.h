#ifndef CUSTOMERGENERATOR_H_
#define CUSTOMERGENERATOR_H_

#include "generator/base/BaseCustomerGenerator.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class CustomerGenerator: public BaseCustomerGenerator
{
public:

    typedef RecordTraits<Customer>::SetterChainType SetterChainType;

    CustomerGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseCustomerGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace VLDBDemo

#endif /* BASECUSTOMERGENERATOR_H_ */
