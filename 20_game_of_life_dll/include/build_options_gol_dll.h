#pragma once

#if defined(_MSC_VER)
# ifdef GOL_DLL
#  define GOLS_IMPEXP __declspec(dllexport)
# else
#  define GOLS_IMPEXP __declspec(dllimport)
# endif //GOL_DLL
#elif defined(_GCC)
# ifdef GOL_DLL
#  define GOLS_IMPEXP __attribute__((visibility("default")))
# else
#  define GOLS_IMPEXP 
# endif //GOL_DLL
#else
#  define GOLS_IMPEXP
#endif

// Note: alternatively [[gnu::dllexport]