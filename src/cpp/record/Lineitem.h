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
    write(out, record.pk(), false);
    out << '|';
    write(out, record.order()->pk(), false);
    out << '|';
    write(out, record.product()->pk(), false);
    out << '|';
    write(out, record.quantity(), false);
    out << '|';
    write(out, record.price(), false);
    out << '|';
    write(out, record.tax(), false);
    out << '|';
    write(out, record.discount(), false);
    out << '|';
    write(out, record.order()->orderDate() + record.shipDateOffset(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* LINEITEM_H_ */
