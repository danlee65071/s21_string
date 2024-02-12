#ifndef S21_STRERROR_H
#define S21_STRERROR_H

#if defined(__APPLE__)
#define MAX_ERROR 107
#elif defined(__linux__)
#define MAX_ERROR 134
#else
// other platforms
#define MAX_ERROR 134
#endif

#endif