// auto-generatad C++ generator for `product`

#ifndef BASEPRODUCTGENERATOR_H_
#define BASEPRODUCTGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/ProductSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseProductGenerator: public RandomSequenceGenerator<Product>
{
public:

    BaseProductGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Product>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Product>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Product > (*this, _config));
        }
    }

    ProductSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return ProductSetterChain(opMode, random, _config);
    }
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTGENERATOR_H_ */
