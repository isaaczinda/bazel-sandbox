#ifndef MATH_SYMBOLS_H
#define MATH_SYMBOLS_H

#ifdef _WIN32
// Export if this is our own source, otherwise import:

#ifndef MATH_STATIC
#ifdef MATH_EXPORTS
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif
#endif // MATH_STATIC
#endif  // _WIN32

#ifndef MATH_API
#define MATH_API
#endif

#endif  // MATH_SYMBOLS_H
