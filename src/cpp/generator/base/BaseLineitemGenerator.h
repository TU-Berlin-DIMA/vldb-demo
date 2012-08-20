// auto-generatad C++ generator for `lineitem`

#ifndef BASELINEITEMGENERATOR_H_
#define BASELINEITEMGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/LineitemSetterChain.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseLineitemGenerator: public RandomSequenceGenerator<Lineitem>
{
public:

    BaseLineitemGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Lineitem>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Lineitem>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Lineitem > (*this, _config));
        }
    }

    LineitemSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return LineitemSetterChain(opMode, random, _config);
    }
};

} // namespace VLDBDemo

#endif /* BASELINEITEMGENERATOR_H_ */
