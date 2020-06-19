/* SIE CONFIDENTIAL
 PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 *
 *      Copyright (C) 2015 Sony Interactive Entertainment Inc.
 *                        All Rights Reserved.
 *
 */

/* stddef.h standard header */
#ifndef _STDDEF
#define _STDDEF
#include <sys/yvals.h>
#include <sys/_types/_size_t.h>

_C_STD_BEGIN
		/* macros */

#ifndef offsetof

 #if defined(__EDG__) && (__EDG__ != 0)
  #define offsetof(T, member) ((_Sizet)__INTADDR__(&(((T *)0)->member)))

 #elif defined(__ORBIS__) && defined(__clang__)
  #define offsetof __builtin_offsetof

 #elif defined(__cplusplus) && ((__GNUC__ == 3) && (3 < __GNUC_MINOR__))
  #define offsetof(T, member) \
	(__offsetof__ (reinterpret_cast<_CSTD size_t> \
	(&reinterpret_cast<char &> \
	(static_cast<T *>(0)->member))))

 #else /* defined(__EDG__) && (__EDG__ != 0) */
  #define offsetof(T, member)	((_CSTD size_t)&(((T *)0)->member))
 #endif /* defined(__EDG__) && (__EDG__ != 0) */

#endif /* offsetof */

		/* type definitions */

 #if !defined(_PTRDIFF_T) && !defined(_PTRDIFFT) \
	&& !defined(_PTRDIFF_T_DEFINED)
  #define _PTRDIFF_T
  #define _PTRDIFFT
  #define _PTRDIFF_T_DEFINED
  #define _STD_USING_PTRDIFF_T
typedef _Ptrdifft ptrdiff_t;
 #endif /* !defined(_PTRDIFF_T) etc. */

 #if !defined(_WCHART) && !defined(_WCHAR_T_DEFINED)
  #define _WCHART
  #define _WCHAR_T_DEFINED
typedef _Wchart wchar_t;
 #endif /* _WCHART etc. */

 #if defined(__need_wint_t) && defined (__CYGWIN__)
  #ifndef _WINTT
   #define _WINTT
typedef _Wintt wint_t;
  #endif /* _WINTT */

 #endif /* defined(__need_wint_t) && defined (__CYGWIN__) */

 #if _HAS_CPP0X

 #ifdef __cplusplus

 #if _HAS_NULLPTR_T
typedef decltype(nullptr) nullptr_t;

 #else /* _HAS_NULLPTR_T */
typedef void *nullptr_t;
 #endif /* _HAS_NULLPTR_T */

typedef float max_align_t __attribute__((__vector_size__ (32) )); // most aligned type
 #endif /* __cplusplus */

 #endif /* _HAS_CPP0X */
_C_STD_END
#endif /* _STDDEF */

 #if defined(_STD_USING)

  #ifdef _STD_USING_PTRDIFF_T
using _CSTD ptrdiff_t;
  #endif /* _STD_USING_PTRDIFF_T */

  #ifdef _STD_USING_SIZE_T
using _CSTD size_t;
  #endif /* _STD_USING_SIZE_T */

 #if __STDC_WANT_LIB_EXT1__
using _CSTD rsize_t;

 #if _HAS_CPP0X

 #ifdef __cplusplus
using _CSTD nullptr_t;
using _CSTD max_align_t;
 #endif /* __cplusplus */

 #endif /* _HAS_CPP0X */
 #endif /* __STDC_WANT_LIB_EXT1__ */

 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2012 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V6.01:0216 */
