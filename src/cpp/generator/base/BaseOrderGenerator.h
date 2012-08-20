// auto-generatad C++ generator for `order`

#ifndef BASEORDERGENERATOR_H_
#define BASEORDERGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/OrderSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseOrderGenerator: public RandomSequenceGenerator<Order>
{
public:

    BaseOrderGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Order>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Order>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Order > (*this, _config));
        }
    }

    OrderSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return OrderSetterChain(opMode, random, _config);
    }
};

} // namespace VLDBDemo

#endif /* BASEORDERGENERATOR_H_ */
