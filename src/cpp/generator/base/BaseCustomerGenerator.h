// auto-generatad C++ generator for `customer`

#ifndef BASECUSTOMERGENERATOR_H_
#define BASECUSTOMERGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/CustomerSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseCustomerGenerator: public RandomSequenceGenerator<Customer>
{
public:

    BaseCustomerGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Customer>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Customer>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Customer > (*this, _config));
        }
    }

    CustomerSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return CustomerSetterChain(opMode, random, _config);
    }
};

} // namespace VLDBDemo

#endif /* BASECUSTOMERGENERATOR_H_ */
