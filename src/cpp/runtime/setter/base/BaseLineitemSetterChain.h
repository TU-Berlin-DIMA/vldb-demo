// auto-generatad C++ setter chain for `lineitem`

#ifndef BASELINEITEMSETTERCHAIN_H_
#define BASELINEITEMSETTERCHAIN_H_

#include "runtime/setter/SetterChain.h"
#include "generator/OrderGenerator.h"
#include "generator/ProductGenerator.h"
#include "record/Lineitem.h"
#include "record/LineitemUtil.h"
#include "runtime/provider/predicate/EqualityPredicateFieldBinder.h"
#include "runtime/provider/predicate/EqualityPredicateProvider.h"
#include "runtime/provider/range/ConstRangeProvider.h"
#include "runtime/provider/reference/ClusteredReferenceProvider.h"
#include "runtime/provider/reference/RandomReferenceProvider.h"
#include "runtime/provider/value/CallbackValueProvider.h"
#include "runtime/provider/value/ClusteredValueProvider.h"
#include "runtime/provider/value/ConstValueProvider.h"
#include "runtime/provider/value/ContextFieldValueProvider.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"
#include "runtime/setter/ReferenceSetter.h"

using namespace Myriad;

namespace VLDBDemo {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseLineitemSetterChain : public SetterChain<Lineitem>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_pk`
    typedef ConstRangeProvider< I64u, Lineitem > RangeProvider01Type;
    typedef ClusteredValueProvider< I64u, Lineitem, UniformPrFunction<I64u>, RangeProvider01Type > ValueProvider01Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::PK, ValueProvider01Type > SetPkType;
    // runtime components for setter `set_order`
    typedef ContextFieldValueProvider< I32u, Order, RecordTraits<Order>::LINEITEMS_COUNT > ValueProvider02Type;
    typedef ConstValueProvider< I32u, Lineitem > ValueProvider03Type;
    typedef ClusteredReferenceProvider< Order, Lineitem, ValueProvider02Type, 0 > ReferenceProvider01Type;
    typedef ReferenceSetter< Lineitem, RecordTraits<Lineitem>::ORDER, ReferenceProvider01Type > SetOrderType;
    // runtime components for setter `set_product`
    typedef RandomValueProvider< I64u, Lineitem, UniformPrFunction<I64u>, 0 > ValueProvider04Type;
    typedef EqualityPredicateFieldBinder< Product, RecordTraits<Product>::PK, Lineitem, ValueProvider04Type > PredicateBinder01Type;
    typedef EqualityPredicateProvider< Product, Lineitem > PredicateProvider01Type;
    typedef RandomReferenceProvider< Product, Lineitem > ReferenceProvider02Type;
    typedef ReferenceSetter< Lineitem, RecordTraits<Lineitem>::PRODUCT, ReferenceProvider02Type > SetProductType;
    // runtime components for setter `set_quantity`
    typedef RandomValueProvider< I16u, Lineitem, CombinedPrFunction<I16u>, 0 > ValueProvider05Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::QUANTITY, ValueProvider05Type > SetQuantityType;
    // runtime components for setter `set_tax`
    typedef RandomValueProvider< Decimal, Lineitem, CombinedPrFunction<Decimal>, 0 > ValueProvider06Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::TAX, ValueProvider06Type > SetTaxType;
    // runtime components for setter `set_discount`
    typedef RandomValueProvider< Decimal, Lineitem, CombinedPrFunction<Decimal>, 0 > ValueProvider07Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::DISCOUNT, ValueProvider07Type > SetDiscountType;
    // runtime components for setter `set_price`
    typedef CallbackValueProvider< Decimal, Lineitem, BaseLineitemSetterChain > ValueProvider08Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::PRICE, ValueProvider08Type > SetPriceType;
    // runtime components for setter `set_ship_date_offset`
    typedef RandomValueProvider< I16u, Lineitem, UniformPrFunction<I16u>, 0 > ValueProvider09Type;
    typedef FieldSetter< Lineitem, RecordTraits<Lineitem>::SHIP_DATE_OFFSET, ValueProvider09Type > SetShipDateOffsetType;

    BaseLineitemSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        SetterChain<Lineitem>(opMode, random),
        _sequenceCardinality(config.cardinality("lineitem")),
        _rangeProvider01(0, config.parameter<I64u>("lineitem.sequence.cardinality")),
        _valueProvider01(config.function< UniformPrFunction<I64u> >("Pr[lineitem.pk]"), _rangeProvider01),
        _setPk(_valueProvider01),
        _valueProvider02(),
        _valueProvider03(config.parameter<I32u>("order.sequence.max_lineitems_per_order")),
        _referenceProvider01(_valueProvider03, _valueProvider02, config.generatorPool().get<OrderGenerator>().inspector()),
        _setOrder(_referenceProvider01),
        _valueProvider04(config.function< UniformPrFunction<I64u> >("Pr[order.product_pk]")),
        _predicateBinder01(_valueProvider04),
        _predicateProvider01(config.generatorPool().get<ProductGenerator>().recordFactory(), _predicateBinder01),
        _referenceProvider02(_predicateProvider01, config.generatorPool().get<ProductGenerator>().inspector()),
        _setProduct(_referenceProvider02),
        _valueProvider05(config.function< CombinedPrFunction<I16u> >("Pr[lineitem.quantity]")),
        _setQuantity(_valueProvider05),
        _valueProvider06(config.function< CombinedPrFunction<Decimal> >("Pr[lineitem.tax]")),
        _setTax(_valueProvider06),
        _valueProvider07(config.function< CombinedPrFunction<Decimal> >("Pr[lineitem.discount]")),
        _setDiscount(_valueProvider07),
        _valueProvider08(*this, &BaseLineitemSetterChain::setPrice, 0),
        _setPrice(_valueProvider08),
        _valueProvider09(config.function< UniformPrFunction<I16u> >("Pr[lineitem.ship_date_offset]")),
        _setShipDateOffset(_valueProvider09),
        _logger(Logger::get("lineitem.setter.chain"))
    {
    }

    virtual ~BaseLineitemSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Lineitem> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseLineitemSetterChain* me = const_cast<BaseLineitemSetterChain*>(this);

        // apply setter chain
        me->_setPk(recordPtr, me->_random);
        me->_setOrder(recordPtr, me->_random);
        me->_setProduct(recordPtr, me->_random);
        me->_setQuantity(recordPtr, me->_random);
        me->_setTax(recordPtr, me->_random);
        me->_setDiscount(recordPtr, me->_random);
        me->_setPrice(recordPtr, me->_random);
        me->_setShipDateOffset(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Interval<I64u> filter(const EqualityPredicate<Lineitem>& predicate)
    {
        Interval<I64u> result(0, _sequenceCardinality);

        // apply inverse setter chain
        _setPk.filterRange(predicate, result);
        _setQuantity.filterRange(predicate, result);
        _setTax.filterRange(predicate, result);
        _setDiscount.filterRange(predicate, result);
        _setPrice.filterRange(predicate, result);
        _setShipDateOffset.filterRange(predicate, result);

        return result;
    }

    virtual Decimal setPrice(const AutoPtr<Lineitem>& recordPtr, RandomStream& random) = 0;

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_pk`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetPkType _setPk;

    // runtime components for setter `set_order`
    ValueProvider02Type _valueProvider02;
    ValueProvider03Type _valueProvider03;
    ReferenceProvider01Type _referenceProvider01;
    SetOrderType _setOrder;

    // runtime components for setter `set_product`
    ValueProvider04Type _valueProvider04;
    PredicateBinder01Type _predicateBinder01;
    PredicateProvider01Type _predicateProvider01;
    ReferenceProvider02Type _referenceProvider02;
    SetProductType _setProduct;

    // runtime components for setter `set_quantity`
    ValueProvider05Type _valueProvider05;
    SetQuantityType _setQuantity;

    // runtime components for setter `set_tax`
    ValueProvider06Type _valueProvider06;
    SetTaxType _setTax;

    // runtime components for setter `set_discount`
    ValueProvider07Type _valueProvider07;
    SetDiscountType _setDiscount;

    // runtime components for setter `set_price`
    ValueProvider08Type _valueProvider08;
    SetPriceType _setPrice;

    // runtime components for setter `set_ship_date_offset`
    ValueProvider09Type _valueProvider09;
    SetShipDateOffsetType _setShipDateOffset;

    // Logger instance.
    Logger& _logger;
};

} // namespace VLDBDemo

#endif /* BASELINEITEMSETTERCHAIN_H_ */
