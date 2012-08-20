// auto-generatad C++ file for `customer`

#ifndef BASECUSTOMERMETA_H_
#define BASECUSTOMERMETA_H_

#include "record/Record.h"

using namespace Myriad;

namespace VLDBDemo {

// forward declarations
class Customer;

class BaseCustomerMeta : public RecordMeta<Customer>
{
public:

    BaseCustomerMeta(const map<string, vector<string> >& enumSets) : 
        gender(enumSets.find("demographics.gender")->second), first_name(enumSets.find("demographics.first_name")->second), last_name(enumSets.find("demographics.last_name")->second)
    {
    }

    // enum set refecences
    const vector<String>& gender;
    const vector<String>& first_name;
    const vector<String>& last_name;
};

} // namespace VLDBDemo

#endif /* BASECUSTOMERMETA_H_ */
