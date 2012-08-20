// auto-generatad C++ setter chain for `product`

#ifndef BASEPRODUCTSETTERCHAIN_H_
#define BASEPRODUCTSETTERCHAIN_H_

#include "runtime/setter/SetterChain.h"
#include "record/Product.h"
#include "record/ProductUtil.h"
#include "runtime/provider/range/ConstRangeProvider.h"
#include "runtime/provider/value/CallbackValueProvider.h"
#include "runtime/provider/value/ClusteredValueProvider.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseProductSetterChain : public SetterChain<Product>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_pk`
    typedef ConstRangeProvider< I64u, Product > RangeProvider01Type;
    typedef ClusteredValueProvider< I64u, Product, UniformPrFunction<I64u>, RangeProvider01Type > ValueProvider01Type;
    typedef FieldSetter< Product, RecordTraits<Product>::PK, ValueProvider01Type > SetPkType;
    // runtime components for setter `set_name`
    typedef CallbackValueProvider< String, Product, BaseProductSetterChain > ValueProvider02Type;
    typedef FieldSetter< Product, RecordTraits<Product>::NAME, ValueProvider02Type > SetNameType;
    // runtime components for setter `set_type`
    typedef RandomValueProvider< Enum, Product, CombinedPrFunction<Enum>, 0 > ValueProvider03Type;
    typedef FieldSetter< Product, RecordTraits<Product>::TYPE, ValueProvider03Type > SetTypeType;
    // runtime components for setter `set_retail_price`
    typedef RandomValueProvider< Decimal, Product, CombinedPrFunction<Decimal>, 0 > ValueProvider04Type;
    typedef FieldSetter< Product, RecordTraits<Product>::RETAIL_PRICE, ValueProvider04Type > SetRetailPriceType;

    BaseProductSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        SetterChain<Product>(opMode, random),
        _sequenceCardinality(config.cardinality("product")),
        _rangeProvider01(0, config.parameter<I64u>("product.sequence.cardinality")),
        _valueProvider01(config.function< UniformPrFunction<I64u> >("Pr[product.pk]"), _rangeProvider01),
        _setPk(_valueProvider01),
        _valueProvider02(*this, &BaseProductSetterChain::setProductName, 0),
        _setName(_valueProvider02),
        _valueProvider03(config.function< CombinedPrFunction<Enum> >("Pr[product.type]")),
        _setType(_valueProvider03),
        _valueProvider04(config.function< CombinedPrFunction<Decimal> >("Pr[product.retail_price]")),
        _setRetailPrice(_valueProvider04),
        _logger(Logger::get("product.setter.chain"))
    {
    }

    virtual ~BaseProductSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Product> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseProductSetterChain* me = const_cast<BaseProductSetterChain*>(this);

        // apply setter chain
        me->_setPk(recordPtr, me->_random);
        me->_setName(recordPtr, me->_random);
        me->_setType(recordPtr, me->_random);
        me->_setRetailPrice(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Interval<I64u> filter(const EqualityPredicate<Product>& predicate)
    {
        Interval<I64u> result(0, _sequenceCardinality);

        // apply inverse setter chain
        _setPk.filterRange(predicate, result);
        _setName.filterRange(predicate, result);
        _setType.filterRange(predicate, result);
        _setRetailPrice.filterRange(predicate, result);

        return result;
    }

    virtual String setProductName(const AutoPtr<Product>& recordPtr, RandomStream& random) = 0;

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_pk`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetPkType _setPk;

    // runtime components for setter `set_name`
    ValueProvider02Type _valueProvider02;
    SetNameType _setName;

    // runtime components for setter `set_type`
    ValueProvider03Type _valueProvider03;
    SetTypeType _setType;

    // runtime components for setter `set_retail_price`
    ValueProvider04Type _valueProvider04;
    SetRetailPriceType _setRetailPrice;

    // Logger instance.
    Logger& _logger;
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTSETTERCHAIN_H_ */
