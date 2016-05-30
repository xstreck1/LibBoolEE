#ifndef SHARED_EXPORT_DEF_H
#define SHARED_EXPORT_DEF_H

#ifdef _WIN32 || _WIN64
#ifdef BUILD_SHARED_IMPORT
#define SHARED_EXPORT __declspec(dllexport)
#elif BUILD_SHARED_EXPORT
#define SHARED_EXPORT __declspec(dllimport)
#else
#endif
#else
#define SHARED_EXPORT
#endif

#endif // SHARED_EXPORT_DEF_H
