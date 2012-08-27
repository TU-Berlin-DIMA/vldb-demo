#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "record/base/BaseProduct.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Product: public BaseProduct
{
public:

    Product(const ProductMeta& meta)
        : BaseProduct(meta)
    {
    }

};

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::Product>::CollectorType::serialize(OutputTraits<VLDBDemo::Product>::CollectorType::StreamType& out, const VLDBDemo::Product& record)
{
    write(out, record.pk(), false);
    out << '|';
    write(out, record.name(), false);
    out << '|';
    write(out, record.typeEnumValue(), false);
    out << '|';
    write(out, record.retailPrice(), false);
    out << '|';
    out << '\n';
}

} // namespace Myriad

#endif /* PRODUCT_H_ */
