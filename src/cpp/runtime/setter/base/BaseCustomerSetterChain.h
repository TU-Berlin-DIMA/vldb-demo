// auto-generatad C++ setter chain for `customer`

#ifndef BASECUSTOMERSETTERCHAIN_H_
#define BASECUSTOMERSETTERCHAIN_H_

#include "runtime/setter/SetterChain.h"
#include "record/Customer.h"
#include "record/CustomerUtil.h"
#include "runtime/provider/range/ConstRangeProvider.h"
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
class BaseCustomerSetterChain : public SetterChain<Customer>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_pk`
    typedef ConstRangeProvider< I64u, Customer > RangeProvider01Type;
    typedef ClusteredValueProvider< I64u, Customer, UniformPrFunction<I64u>, RangeProvider01Type > ValueProvider01Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::PK, ValueProvider01Type > SetPkType;
    // runtime components for setter `set_gender`
    typedef RandomValueProvider< Enum, Customer, CombinedPrFunction<Enum>, 0 > ValueProvider02Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::GENDER, ValueProvider02Type > SetGenderType;
    // runtime components for setter `set_first_name`
    typedef RandomValueProvider< Enum, Customer, ConditionalCombinedPrFunction<Enum, Enum>, RecordTraits<Customer>::GENDER > ValueProvider03Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::FIRST_NAME, ValueProvider03Type > SetFirstNameType;
    // runtime components for setter `set_last_name`
    typedef RandomValueProvider< Enum, Customer, CombinedPrFunction<Enum>, 0 > ValueProvider04Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::LAST_NAME, ValueProvider04Type > SetLastNameType;
    // runtime components for setter `set_age`
    typedef RandomValueProvider< I16u, Customer, NormalPrFunction, 0 > ValueProvider05Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::AGE, ValueProvider05Type > SetAgeType;
    // runtime components for setter `set_orders_count`
    typedef RandomValueProvider< I32u, Customer, CombinedPrFunction<I32u>, 0 > ValueProvider06Type;
    typedef FieldSetter< Customer, RecordTraits<Customer>::ORDERS_COUNT, ValueProvider06Type > SetOrdersCountType;

    BaseCustomerSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        SetterChain<Customer>(opMode, random),
        _sequenceCardinality(config.cardinality("customer")),
        _rangeProvider01(0, config.parameter<I64u>("customer.sequence.cardinality")),
        _valueProvider01(config.function< UniformPrFunction<I64u> >("Pr[customer.pk]"), _rangeProvider01),
        _setPk(_valueProvider01),
        _valueProvider02(config.function< CombinedPrFunction<Enum> >("Pr[customer.gender]")),
        _setGender(_valueProvider02),
        _valueProvider03(config.function< ConditionalCombinedPrFunction<Enum, Enum> >("Pr[customer.first_name]")),
        _setFirstName(_valueProvider03),
        _valueProvider04(config.function< CombinedPrFunction<Enum> >("Pr[customer.last_name]")),
        _setLastName(_valueProvider04),
        _valueProvider05(config.function< NormalPrFunction >("Pr[customer.age]")),
        _setAge(_valueProvider05),
        _valueProvider06(config.function< CombinedPrFunction<I32u> >("Pr[customer.orders_count]")),
        _setOrdersCount(_valueProvider06),
        _logger(Logger::get("customer.setter.chain"))
    {
    }

    virtual ~BaseCustomerSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Customer> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseCustomerSetterChain* me = const_cast<BaseCustomerSetterChain*>(this);

        // apply setter chain
        me->_setPk(recordPtr, me->_random);
        me->_setGender(recordPtr, me->_random);
        me->_setFirstName(recordPtr, me->_random);
        me->_setLastName(recordPtr, me->_random);
        me->_setAge(recordPtr, me->_random);
        me->_setOrdersCount(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Interval<I64u> filter(const EqualityPredicate<Customer>& predicate)
    {
        Interval<I64u> result(0, _sequenceCardinality);

        // apply inverse setter chain
        _setPk.filterRange(predicate, result);
        _setGender.filterRange(predicate, result);
        _setFirstName.filterRange(predicate, result);
        _setLastName.filterRange(predicate, result);
        _setAge.filterRange(predicate, result);
        _setOrdersCount.filterRange(predicate, result);

        return result;
    }

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_pk`
    RangeProvider01Type _rangeProvider01;
    ValueProvider01Type _valueProvider01;
    SetPkType _setPk;

    // runtime components for setter `set_gender`
    ValueProvider02Type _valueProvider02;
    SetGenderType _setGender;

    // runtime components for setter `set_first_name`
    ValueProvider03Type _valueProvider03;
    SetFirstNameType _setFirstName;

    // runtime components for setter `set_last_name`
    ValueProvider04Type _valueProvider04;
    SetLastNameType _setLastName;

    // runtime components for setter `set_age`
    ValueProvider05Type _valueProvider05;
    SetAgeType _setAge;

    // runtime components for setter `set_orders_count`
    ValueProvider06Type _valueProvider06;
    SetOrdersCountType _setOrdersCount;

    // Logger instance.
    Logger& _logger;
};

} // namespace VLDBDemo

#endif /* BASECUSTOMERSETTERCHAIN_H_ */
