// auto-generatad C++ file for `product`

#ifndef BASEPRODUCT_H_
#define BASEPRODUCT_H_

#include "record/Record.h"
#include "record/ProductMeta.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Product;
class ProductConfig;
class ProductGenerator;
class ProductSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseProduct: public Record
{
public:

    BaseProduct(const ProductMeta& meta) : 
        _meta(meta)
    {
    }

    const ProductMeta& meta() const
    {
        return _meta;
    }

    void pk(const I64u& v);
    const I64u& pk() const;

    void retailPrice(const Decimal& v);
    const Decimal& retailPrice() const;

    void type(const Enum& v);
    const Enum& type() const;
    const String& typeEnumValue() const;

    void name(const String& v);
    const String& name() const;

protected:

    // meta
    const ProductMeta& _meta;

    // fields
    I64u _pk;
    Decimal _retail_price;
    Enum _type;
    String _name;
};

inline void BaseProduct::pk(const I64u& v)
{
    _pk = v;
}

inline const I64u& BaseProduct::pk() const
{
    return _pk;
}

inline void BaseProduct::retailPrice(const Decimal& v)
{
    _retail_price = v;
}

inline const Decimal& BaseProduct::retailPrice() const
{
    return _retail_price;
}

inline void BaseProduct::type(const Enum& v)
{
    _type = v;
}

inline const Enum& BaseProduct::type() const
{
    return _type;
}

inline const String& BaseProduct::typeEnumValue() const
{
    return _meta.type[_type];
}

inline void BaseProduct::name(const String& v)
{
    _name = v;
}

inline const String& BaseProduct::name() const
{
    return _name;
}

} // namespace VLDBDemo

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<VLDBDemo::Product>
{
    typedef VLDBDemo::ProductMeta MetaType;
    typedef VLDBDemo::ProductGenerator GeneratorType;
    typedef VLDBDemo::ProductSetterChain SetterChainType;
    typedef RecordFactory<VLDBDemo::Product> FactoryType;

    enum Field { UNKNOWN, GEN_ID, PK, NAME, TYPE, RETAIL_PRICE };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void OutputTraits<VLDBDemo::BaseProduct>::CollectorType::serialize(OutputTraits<VLDBDemo::Product>::CollectorType::StreamType& out, const VLDBDemo::BaseProduct& record)
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

#endif /* BASEPRODUCT_H_ */
