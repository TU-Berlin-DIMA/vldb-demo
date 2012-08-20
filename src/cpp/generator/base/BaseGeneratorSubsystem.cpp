// auto-generatad base generator config C++ file

#include "generator/base/BaseGeneratorSubsystem.h"
#include "generator/CustomerGenerator.h"
#include "generator/ProductGenerator.h"
#include "generator/OrderGenerator.h"
#include "generator/LineitemGenerator.h"

using namespace std;
using namespace Poco;

namespace Myriad {

// the initial stage ID should always be zero
I32u AbstractSequenceGenerator::Stage::NEXT_STAGE_ID = 0;

// register the valid stages for the Myriad generator extension
AbstractSequenceGenerator::StageList initList()
{
    AbstractSequenceGenerator::StageList tmp;

    tmp.push_back(AbstractSequenceGenerator::Stage("customer"));
    tmp.push_back(AbstractSequenceGenerator::Stage("product"));
    tmp.push_back(AbstractSequenceGenerator::Stage("order"));
    tmp.push_back(AbstractSequenceGenerator::Stage("lineitem"));

    return tmp;
}

const AbstractSequenceGenerator::StageList AbstractSequenceGenerator::STAGES(initList());

// register the record sequence generators
void BaseGeneratorSubsystem::registerGenerators()
{
    registerGenerator<VLDBDemo::CustomerGenerator>("customer");
    registerGenerator<VLDBDemo::ProductGenerator>("product");
    registerGenerator<VLDBDemo::OrderGenerator>("order");
    registerGenerator<VLDBDemo::LineitemGenerator>("lineitem");
}

} // namespace Myriad
