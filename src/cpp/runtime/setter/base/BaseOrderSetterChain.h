// auto-generatad C++ setter chain for `order`

#ifndef BASEORDERSETTERCHAIN_H_
#define BASEORDERSETTERCHAIN_H_

#include "runtime/setter/SetterChain.h"
#include "generator/CustomerGenerator.h"
#include "record/Order.h"
#include "record/OrderUtil.h"
#include "runtime/provider/range/ConstRangeProvider.h"
#include "runtime/provider/reference/ClusteredReferenceProvider.h"
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
class BaseOrderSetterChain : public SetterChain<Order>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_pk`
    typedef ConstRangeProvider< I64u, Order > RangeProvider01Type;
    typedef ClusteredValueProvider< I64u, Order, UniformPrFunction<I64u>, RangeProvider01Type > ValueProvider01Type;
    typedef FieldSetter< Order, RecordTraits<Order>::PK, ValueProvider01Type > SetPkType;
    // runtime components for setter `set_customer`
    typedef ContextFieldValueProvider< I32u, Customer, RecordTraits<Customer>::ORDERS_COUNT > ValueProvider02Type;
    typedef ConstValueProvider< I32u, Order > ValueProvider03Type;
    typedef ClusteredReferenceProvider< Customer, Order, ValueProvider02Type, 0 > ReferenceProvider01Type;
    typedef ReferenceSetter< Order, RecordTraits<Order>::CUSTOMER, ReferenceProvider01Type > SetCustomerType;
    // runtime components for setter `set_status`
    typedef RandomValueProvider< Enum, Order, CombinedPrFunction<Enum>, 0 > ValueProvider04Type;
    typedef FieldSetter< Order, RecordTraits<Order>::STATUS, ValueProvider04Type > SetStatusType;
    // runtime components for setter `set_total_price`
    typedef CallbackValueProvider< Decimal, Order, BaseOrderSetterChain > ValueProvider05Type;
    typedef FieldSetter< Order, RecordTraits<Order>::TOTAL_PRICE, ValueProvider05Type > SetTotalPriceType;
    // runtime components for setter `set_order_date`
    typedef RandomValueProvider< Date, Order, UniformPrFunction<Date>, 0 > ValueProvider06Type;
    typedef FieldSetter< Order, RecordTraits<Order>::ORDER_DATE, ValueProvider06Type > SetOrderDateType;
    // runtime components for setter `set_lineitems_count`
    typedef RandomValueProvider< I32u, Order, CombinedPrFunction<I32u>, 0 > ValueProvider07Type;
    typedef FieldSetter< Order, RecordTraits<Order>::LINEITEMS_COUNT, ValueProvider07Type > SetLineitemsCountType;

    BaseOrderSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        SetterChain<Order>(opMode, random),
        _sequenceCardinality(config.cardinality("order")),
        _rangeProvider01(0, config.parameter<I64u>("order.sequence.cardinality")),
        _valueProvider01(config.function< UniformPrFunction<I64u> >("Pr[order.pk]"), _rangeProvider01),
        _setPk(_valueProvider01),
        _valueProvider02(),
        _valueProvider03(config.parameter<I32u>("customer.sequence.max_orders_per_customer")),
        _referenceProvider01(_valueProvider03, _valueProvider02, config.generatorPool().get<CustomerGenerator>().inspector()),
        _setCustomer(_referenceProvider01),
        _valueProvider04(config.function< CombinedPrFunction<Enum> >("Pr[order.status]")),
        _setStatus(_valueProvider04),
        _valueProvider05(*this, &BaseOrderSetterChain::setTotalPrice, 0),
        _setTotalPrice(_valueProvider05),
        _valueProvider06(config.function< UniformPrFunction<Date> >("Pr[order.order_date]")),
        _setOrderDate(_valueProvider06),
        _valueProvider07(config.function< CombinedPrFunction<I32u> >("Pr[order.lineitems_count]")),
        _setLineitemsCount(_valueProvider07),
        _logger(Logger::get("order.setter.chain"))
    {
    }

    virtual ~BaseOrderSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Order> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseOrderSetterChain* me = const_cast<BaseOrderSetterChain*>(this);

        // apply setter chain
        me->_setPk(recordPtr, me->_random);
        me->_setCustomer(recordPtr, me->_random);
        me->_setStatus(recordPtr, me->_random);
        me->_setTotalPrice(recordPtr, me->_random);
        me->_setOrderDate(recordPtr, me->_random);
        me->_setLineitemsCount(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Interval<I64u> filter(const EqualityPredicate<Order>& predicate)
    {
        Interval<I64u> result(0, _sequenceCardinality);

        // apply inverse setter chain
        _setPk.filterRange(predicate, result);
        _setStatus.filterRange(predicate, result);
        _setTotalPrice.filterRange(predicate, result);
        _setOrderDate.filterRange(predicate, result);
        _setLineitemsCount.filterRange(predicate, result);

        return result;
    }

    virtual Decimal setTotalPrice(const AutoPtr<Order>& recordPtr, RandomStream& random) = 0;

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_pk`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetPkType _setPk;

    // runtime components for setter `set_customer`
    ValueProvider02Type _valueProvider02;
    ValueProvider03Type _valueProvider03;
    ReferenceProvider01Type _referenceProvider01;
    SetCustomerType _setCustomer;

    // runtime components for setter `set_status`
    ValueProvider04Type _valueProvider04;
    SetStatusType _setStatus;

    // runtime components for setter `set_total_price`
    ValueProvider05Type _valueProvider05;
    SetTotalPriceType _setTotalPrice;

    // runtime components for setter `set_order_date`
    ValueProvider06Type _valueProvider06;
    SetOrderDateType _setOrderDate;

    // runtime components for setter `set_lineitems_count`
    ValueProvider07Type _valueProvider07;
    SetLineitemsCountType _setLineitemsCount;

    // Logger instance.
    Logger& _logger;
};

} // namespace VLDBDemo

#endif /* BASEORDERSETTERCHAIN_H_ */
