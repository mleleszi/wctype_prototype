#ifndef MYWCTYPE_H
#define MYWCTYPE_H

#include "wctype_table.h"

namespace my_wctype {
inline int iswalpha(wchar_t wc) {
  // Fast path: ASCII
  if (wc <= 0x7F) {
    return (wc >= 'A' && wc <= 'Z') || (wc >= 'a' && wc <= 'z');
  }

  // Fast path: Common CJK ranges (all alphabetic)
  if ((wc >= 0x4E00 && wc <= 0x9FFF) || // CJK Unified Ideographs
      (wc >= 0x3400 && wc <= 0x4DBF) || // CJK Extension A
      (wc >= 0x20000 && wc <= 0x2A6DF)) {
    // CJK Extension B
    return 1;
  }

  return lookup_properties(wc) & PROP_ALPHA;
}

inline int iswdigit(wchar_t wc) {
  // Fast path: ASCII digits only in C.UTF-8
  if (wc >= '0' && wc <= '9') {
    return 1;
  }
  // In C.UTF8 only ASCII 0-9 are digits, so this is not needed
  return lookup_properties(wc) & PROP_DIGIT;
}

inline int iswpunct(wchar_t wc) {
  // TODO: ASCII fast path
  return lookup_properties(wc) & PROP_PUNCT;
}

inline int iswalnum(wchar_t wc) {
  // Fast path: ASCII alphanumeric
  if (wc <= 0x7F) {
    return (wc >= 'A' && wc <= 'Z') ||
           (wc >= 'a' && wc <= 'z') ||
           (wc >= '0' && wc <= '9');
  }

  // Fast path: Common CJK ranges
  if ((wc >= 0x4E00 && wc <= 0x9FFF) ||
      (wc >= 0x3400 && wc <= 0x4DBF) ||
      (wc >= 0x20000 && wc <= 0x2A6DF)) {
    return 1;
  }

  return lookup_properties(wc) & (PROP_ALPHA | PROP_DIGIT);
}

inline int iswblank(wchar_t wc) {
  // TODO: fast path
  return lookup_properties(wc) & PROP_BLANK;
}

inline int iswgraph(wchar_t wc) {
  // TODO: fast path
  return lookup_properties(wc) & PROP_GRAPH;
}

inline int iswlower(wchar_t wc) {
  // Fast path: ASCII lowercase
  if (wc >= 'a' && wc <= 'z') {
    return 1;
  }

  return lookup_properties(wc) & PROP_LOWER;
}

inline int iswspace(wchar_t wc) {
  // TODO: fast path

  return lookup_properties(wc) & PROP_SPACE;
}

// TODO: iswctype
// TODO: iswprint
// TODO: iswupper
// TODO: iswxdigit

} // namespace my_wctype

#endif // MYWCTYPE_H
