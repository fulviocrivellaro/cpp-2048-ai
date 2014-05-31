#pragma once

#include "2048.Core.Tokenizer.h"

// define ToString
namespace Microsoft
{ 
    namespace VisualStudio
    { 
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<TOKEN>(const TOKEN& t) { RETURN_WIDE_STRING(t); }
        }
    }
}
