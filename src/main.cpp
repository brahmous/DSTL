#include <iostream>

#include "DSTL/vector.h"
#include "DSTL/fraction.h"

int main()
{
  try{
    dstl::vector<int> nums {1, 2, 3, 4};
    dstl::vector<std::string> names {"nick", "mike", "jame", "vince", "Zherka"};

    dstl::Fraction f1;

    names.push_back("james");
    names.push_back("killer");
    std::cout << names << std::endl;
    names.pop_back();
    std::cout << names << std::endl;
  }catch(std::runtime_error err){
    std::cout << "Exception" << std::endl;
  }
}
