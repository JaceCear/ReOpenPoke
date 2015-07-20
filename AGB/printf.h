
#ifndef __SPRINTF
#define __SPRINTF

u32 strnlen(const char *str, u32 count);
int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buf, const char *fmt, ...);

#endif	// __SPRINTF

// EOF
