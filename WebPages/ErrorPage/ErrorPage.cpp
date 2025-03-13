#include "ErrorPage.h"

DDString ErrorPage::Read() const
{
	return DDString("<html><body><h1>WebServer ErrorPage</h1></body></html>");
}