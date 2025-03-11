#pragma once

#include "String/DDString.h"

class DDWebPage
{

public:
    virtual ~DDWebPage() {};
    virtual DDString Read() const = 0;

};
