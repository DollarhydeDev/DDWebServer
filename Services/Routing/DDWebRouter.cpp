#include "DDWebRouter.h"

DDWebRouter::DDWebRouter()
{
}

DDWebRouter& DDWebRouter::GetInstance()
{
	static DDWebRouter instance;
	return instance;
}
