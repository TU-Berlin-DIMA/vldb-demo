// auto-generatad C++ file for `order`

#ifndef BASEORDERMETA_H_
#define BASEORDERMETA_H_

#include "record/Record.h"

using namespace Myriad;

namespace VLDBDemo {

// forward declarations
class Order;

class BaseOrderMeta : public RecordMeta<Order>
{
public:

    BaseOrderMeta(const map<string, vector<string> >& enumSets) : 
        status(enumSets.find("retail.order.status")->second)
    {
    }

    // enum set refecences
    const vector<String>& status;
};

} // namespace VLDBDemo

#endif /* BASEORDERMETA_H_ */
