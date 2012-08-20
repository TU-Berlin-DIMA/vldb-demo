#ifndef ORDERGENERATOR_H_
#define ORDERGENERATOR_H_

#include "generator/base/BaseOrderGenerator.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class OrderGenerator: public BaseOrderGenerator
{
public:

    typedef RecordTraits<Order>::SetterChainType SetterChainType;

    OrderGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseOrderGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace VLDBDemo

#endif /* BASEORDERGENERATOR_H_ */
