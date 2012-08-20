#ifndef LINEITEM_H_
#define LINEITEM_H_

#include "record/base/BaseLineitem.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Lineitem: public BaseLineitem
{
public:

    Lineitem(const LineitemMeta& meta)
        : BaseLineitem(meta)
    {
    }

};

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::Lineitem>::CollectorType::serialize(OutputTraits<VLDBDemo::Lineitem>::CollectorType::StreamType& out, const VLDBDemo::Lineitem& record)
{
    OutputTraits<VLDBDemo::BaseLineitem>::CollectorType::serialize(out, record);
}

} // namespace Myriad

#endif /* LINEITEM_H_ */
