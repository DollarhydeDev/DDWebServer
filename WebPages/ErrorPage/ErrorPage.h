#pragma once

#include "DDWebPage.h"

class ErrorPage : public DDWebPage
{
public:
    DDString Read() const override;
};