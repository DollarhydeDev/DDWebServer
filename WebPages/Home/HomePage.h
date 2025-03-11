#pragma once

#include "DDWebPage.h"

class HomePage : public DDWebPage
{
public:
    DDString Read() const override;
};