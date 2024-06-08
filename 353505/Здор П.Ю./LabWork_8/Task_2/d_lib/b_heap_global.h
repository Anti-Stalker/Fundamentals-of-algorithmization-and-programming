#ifndef B_HEAP_GLOBAL_H
#define B_HEAP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(B_HEAP_LIBRARY)
#define B_HEAP_EXPORT Q_DECL_EXPORT
#else
#define B_HEAP_EXPORT Q_DECL_IMPORT
#endif

#endif // B_HEAP_GLOBAL_H
