#include "DDString.h"

DDString::DDString()
{
	_bufferSize = 0;
	_bufferCapacity = 10;

	_buffer = new char[_bufferCapacity];
	_buffer[_bufferSize] = 0x00;
}
DDString::DDString(char* inBuffer)
{
	if (!inBuffer)
	{
		_bufferSize = 0;
		_bufferCapacity = 10;

		_buffer = new char[_bufferCapacity];
		_buffer[_bufferSize] = 0x00;
		return;
	}

	_bufferSize = 0;
	while (inBuffer[_bufferSize] != 0x00) _bufferSize++;
	_bufferCapacity = _bufferSize + 1;

	_buffer = new char[_bufferCapacity];
	memcpy(_buffer, inBuffer, _bufferSize);
	_buffer[_bufferSize] = 0x00;
}
DDString::DDString(const char* inBuffer)
{
	if (!inBuffer)
	{
		_bufferSize = 0;
		_bufferCapacity = 10;

		_buffer = new char[_bufferCapacity];
		_buffer[_bufferSize] = 0x00;
		return;
	}

	_bufferSize = 0;
	while (inBuffer[_bufferSize] != 0x00) _bufferSize++;
	_bufferCapacity = _bufferSize + 1;

	_buffer = new char[_bufferCapacity];
	memcpy(_buffer, inBuffer, _bufferSize);
	_buffer[_bufferSize] = 0x00;
}
DDString::DDString(const DDString& otherString)
{
	if (!otherString._buffer || otherString._bufferSize <= 0)
	{
		_bufferSize = 0;
		_bufferCapacity = 10;

		_buffer = new char[_bufferCapacity];
		_buffer[_bufferSize] = 0x00;
		return;
	}

	_bufferSize = otherString._bufferSize;
	_bufferCapacity = (_bufferSize >= otherString._bufferCapacity) ? (_bufferSize + 1) : otherString._bufferCapacity;
	_buffer = new char[_bufferCapacity];

	memcpy(_buffer, otherString._buffer, _bufferSize);
	_buffer[_bufferSize] = 0x00;
}
DDString::DDString(DDString&& otherString) noexcept
{
	_buffer = otherString._buffer;
	_bufferSize = otherString._bufferSize;
	_bufferCapacity = otherString._bufferCapacity;

	otherString._buffer = nullptr;
	otherString._bufferSize = 0;
	otherString._bufferCapacity = 0;
}
DDString::~DDString()
{
	if (_buffer)
	{
		delete[] _buffer;
		_buffer = nullptr;
	}

	_bufferSize = 0;
	_bufferCapacity = 0;
}

void DDString::IncreaseBufferSize(int increaseAmount)
{
	_bufferCapacity += increaseAmount;
	char* newBuffer = new char[_bufferCapacity];

	if (_buffer)
	{
		memcpy(newBuffer, _buffer, _bufferSize);
		delete[] _buffer;
	}

	_buffer = newBuffer;
	_buffer[_bufferSize] = 0x00;
}