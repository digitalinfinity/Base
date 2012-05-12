#pragma once

#include "../base.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "Ptr.h"

namespace Util
{
	template <typename TLogger>
	class GenericLogger
	{
	public:
		void Log(CharType* formatString, ...)
		{
			va_list args;
			int len;
			AutoArrayPtr<CharType> buffer;

			va_start(args, formatString);
#ifdef UNICODE
			len = _vscwprintf(formatString, args) + 1;
#else
			len = _vscprintf(formatString, args) + 1;
#endif
			buffer = new CharType[len];

#ifdef UNICODE
			vswprintf_s(buffer, len, formatString, args);
#else
			vsprintf_s(buffer, len, formatString, args);
#endif
			TLogger::LogOutput(buffer);
		}
	};

	class OutputLogger: public GenericLogger<OutputLogger>
	{
	public:
		static void LogOutput(CharType* buffer)
		{
#ifdef UNICODE
			wprintf(buffer);
#else
			printf(buffer);
#endif
		}
	};

	static OutputLogger Output;
};