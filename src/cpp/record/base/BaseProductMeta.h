// auto-generatad C++ file for `product`

#ifndef BASEPRODUCTMETA_H_
#define BASEPRODUCTMETA_H_

#include "record/Record.h"

using namespace Myriad;

namespace VLDBDemo {

// forward declarations
class Product;

class BaseProductMeta : public RecordMeta<Product>
{
public:

    BaseProductMeta(const map<string, vector<string> >& enumSets) : 
        type(enumSets.find("retail.product.type")->second)
    {
    }

    // enum set refecences
    const vector<String>& type;
};

} // namespace VLDBDemo

#endif /* BASEPRODUCTMETA_H_ */
