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
    OutputTraits<VLDBDemo::BaseProduct>::CollectorType::serialize(out, record);
}

} // namespace Myriad

#endif /* PRODUCT_H_ */
