// auto-generatad base generator config C++ file

#ifndef BASEGENERATORCONFIG_H_
#define BASEGENERATORCONFIG_H_

#include "config/AbstractGeneratorConfig.h"

namespace Myriad {

class BaseGeneratorConfig: public AbstractGeneratorConfig
{
public:

    BaseGeneratorConfig(GeneratorPool& generatorPool) : AbstractGeneratorConfig(generatorPool)
    {
    }

protected:

    virtual void configurePartitioning()
    {
        // TODO: this piece of auto-generating code / Config API needs to be rewritten

        // setup linear scale estimator for customer
        setString("partitioning.customer.base-cardinality", toString<I64u>(parameter<I64u>("customer.sequence.base_cardinality")));
        computeLinearScalePartitioning("customer");
        // setup linear scale estimator for product
        setString("partitioning.product.base-cardinality", toString<I64u>(parameter<I64u>("product.sequence.base_cardinality")));
        computeLinearScalePartitioning("product");
        // setup linear scale estimator for order
        setString("partitioning.order.base-cardinality", toString<I64u>(static_cast<I64u>(parameter<I32u>("customer.sequence.max_orders_per_customer") * parameter<I32u>("customer.sequence.base_cardinality"))));
        computeLinearScalePartitioning("order");
        // setup linear scale estimator for lineitem
        setString("partitioning.lineitem.base-cardinality", toString<I64u>(static_cast<I64u>(parameter<I64u>("order.sequence.max_lineitems_per_order") * parameter<I64u>("order.sequence.base_cardinality"))));
        computeLinearScalePartitioning("lineitem");
    }

    virtual void configureFunctions()
    {
        // register prototype functions
        function(new NormalPrFunction("Pr[customer.age]", 48, 12));
        function(new ConditionalCombinedPrFunction<Enum, Enum>("Pr[customer.first_name]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/demographics/first_name.distribution")));
        function(new CombinedPrFunction<Enum>("Pr[customer.gender]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/customer/gender.distribution")));
        function(new CombinedPrFunction<Enum>("Pr[customer.last_name]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/demographics/last_name.distribution")));
        function(new CombinedPrFunction<I32u>("Pr[customer.orders_count]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/customer/orders_count.distribution")));
        function(new UniformPrFunction<I64u>("Pr[customer.pk]", 1, static_cast<I64u>(parameter<I64u>("customer.sequence.cardinality") + 1)));
        function(new CombinedPrFunction<Decimal>("Pr[lineitem.discount]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/lineitem/discount.distribution")));
        function(new UniformPrFunction<I64u>("Pr[lineitem.pk]", 1, static_cast<I64u>(parameter<I64u>("lineitem.sequence.cardinality") + 1)));
        function(new UniformPrFunction<I64u>("Pr[lineitem.product]", 0, parameter<I64u>("lineitem.sequence.cardinality")));
        function(new CombinedPrFunction<I16u>("Pr[lineitem.quantity]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/lineitem/quantity.distribution")));
        function(new UniformPrFunction<I16u>("Pr[lineitem.ship_date_offset]", 0, 15));
        function(new CombinedPrFunction<Decimal>("Pr[lineitem.tax]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/lineitem/tax.distribution")));
        function(new CombinedPrFunction<I32u>("Pr[order.lineitems_count]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/order/lineitems_count.distribution")));
        function(new UniformPrFunction<Date>("Pr[order.order_date]", Date("2012-01-01"), Date("2012-07-01")));
        function(new UniformPrFunction<I64u>("Pr[order.pk]", 1, static_cast<I64u>(parameter<I64u>("order.sequence.cardinality") + 1)));
        function(new UniformPrFunction<I64u>("Pr[order.product_pk]", 1, static_cast<I64u>(parameter<I64u>("product.sequence.cardinality") + 1)));
        function(new CombinedPrFunction<Enum>("Pr[order.status]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/order/status.distribution")));
        function(new UniformPrFunction<I64u>("Pr[product.pk]", 1, static_cast<I64u>(parameter<I64u>("product.sequence.cardinality") + 1)));
        function(new CombinedPrFunction<Decimal>("Pr[product.retail_price]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/product/price.distribution")));
        function(new CombinedPrFunction<Enum>("Pr[product.type]", static_cast<String>(parameter<String>("ENV.config-dir") + "/distributions/core/retail/category.distribution")));
    }

    virtual void configureSets()
    {
        // bind string sets to config members with the bindStringSet method
        bindEnumSet("demographics.gender", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/core/demographics/gender.domain"));
        bindEnumSet("demographics.last_name", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/core/demographics/last_name.domain"));
        bindEnumSet("retail.order.status", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/core/retail/order/status.domain"));
        bindEnumSet("demographics.first_name", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/core/demographics/first_name.domain"));
        bindEnumSet("retail.product.type", static_cast<String>(parameter<String>("ENV.config-dir") + "/domains/core/retail/category.domain"));
    }
};

} // namespace Myriad

#endif /* BASEGENERATORCONFIG_H_ */
