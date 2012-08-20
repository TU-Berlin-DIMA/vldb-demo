#ifndef LINEITEMGENERATOR_H_
#define LINEITEMGENERATOR_H_

#include "generator/base/BaseLineitemGenerator.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class LineitemGenerator: public BaseLineitemGenerator
{
public:

    typedef RecordTraits<Lineitem>::SetterChainType SetterChainType;

    LineitemGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseLineitemGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace VLDBDemo

#endif /* BASELINEITEMGENERATOR_H_ */
