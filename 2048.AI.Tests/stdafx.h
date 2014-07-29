// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

// TODO: reference additional headers your program requires here
#include "AiMath.h"
#include "Analyzer.h"
#include "TestUtils.h"

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const MilCore::AI::Angles& t) { RETURN_WIDE_STRING((int)t); }

