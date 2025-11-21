#include "wctype_test_base.h"
#include "mywctype.h"
#include <cwctype>

struct ConversionTestCase {
  wint_t input;
  wint_t expected;
  const char *name;
};

class TowupperTest : public WctypeTest,
                     public ::testing::WithParamInterface<ConversionTestCase> {
};

TEST_P(TowupperTest, Towupper) {
  auto test = GetParam();
  wint_t my_result = my_wctype::towupper(test.input);
  wint_t std_result = std::towupper(static_cast<wint_t>(test.input));

  EXPECT_EQ(my_result, test.expected)
    << "Failed for U+" << std::hex << test.input << " (" << test.name << ")"
    << " - expected U+" << test.expected << " but got U+" << my_result;
  EXPECT_EQ(my_result, std_result)
    << "Mismatch with std::towupper for U+" << std::hex << test.input
    << " (" << test.name << ")"
    << " - std returned U+" << std_result << " but we returned U+" << my_result;
}

INSTANTIATE_TEST_SUITE_P(TowupperTests, TowupperTest, ::testing::Values(
                           // ASCII lowercase letters should convert to uppercase
                           ConversionTestCase{0x0061, 0x0041,
                           "LATIN SMALL LETTER A -> A"},
                           ConversionTestCase{0x0062, 0x0042,
                           "LATIN SMALL LETTER B -> B"},
                           ConversionTestCase{0x0068, 0x0048,
                           "LATIN SMALL LETTER H -> H"},
                           ConversionTestCase{0x007A, 0x005A,
                           "LATIN SMALL LETTER Z -> Z"},

                           // ASCII uppercase letters should remain unchanged
                           ConversionTestCase{0x0041, 0x0041,
                           "LATIN CAPITAL LETTER A -> A"},
                           ConversionTestCase{0x0042, 0x0042,
                           "LATIN CAPITAL LETTER B -> B"},
                           ConversionTestCase{0x0048, 0x0048,
                           "LATIN CAPITAL LETTER H -> H"},
                           ConversionTestCase{0x005A, 0x005A,
                           "LATIN CAPITAL LETTER Z -> Z"},

                           // ASCII non-letters should remain unchanged
                           ConversionTestCase{0x0030, 0x0030,
                           "DIGIT ZERO -> DIGIT ZERO"},
                           ConversionTestCase{0x0039, 0x0039,
                           "DIGIT NINE -> DIGIT NINE"},
                           ConversionTestCase{0x0020, 0x0020, "SPACE -> SPACE"},
                           ConversionTestCase{0x0021, 0x0021,
                           "EXCLAMATION MARK -> EXCLAMATION MARK"},
                           ConversionTestCase{0x0040, 0x0040,
                           "AT SIGN -> AT SIGN"},
                           ConversionTestCase{0x005B, 0x005B,
                           "LEFT SQUARE BRACKET -> LEFT SQUARE BRACKET"},
                           ConversionTestCase{0x0060, 0x0060,
                           "GRAVE ACCENT -> GRAVE ACCENT"},
                           ConversionTestCase{0x007B, 0x007B,
                           "LEFT CURLY BRACKET -> LEFT CURLY BRACKET"},

                           // Latin Extended lowercase should convert to uppercase
                           ConversionTestCase{0x00E0, 0x00C0,
                           "LATIN SMALL LETTER A WITH GRAVE -> CAPITAL"},
                           ConversionTestCase{0x00E1, 0x00C1,
                           "LATIN SMALL LETTER A WITH ACUTE -> CAPITAL"},
                           ConversionTestCase{0x00F6, 0x00D6,
                           "LATIN SMALL LETTER O WITH DIAERESIS -> CAPITAL"},
                           ConversionTestCase{0x00FF, 0x0178,
                           "LATIN SMALL LETTER Y WITH DIAERESIS -> CAPITAL"},

                           // Latin Extended uppercase should remain unchanged
                           ConversionTestCase{0x00C0, 0x00C0,
                           "LATIN CAPITAL LETTER A WITH GRAVE -> CAPITAL"},
                           ConversionTestCase{0x00C1, 0x00C1,
                           "LATIN CAPITAL LETTER A WITH ACUTE -> CAPITAL"},
                           ConversionTestCase{0x00D6, 0x00D6,
                           "LATIN CAPITAL LETTER O WITH DIAERESIS -> CAPITAL"},
                           ConversionTestCase{0x00DE, 0x00DE,
                           "LATIN CAPITAL LETTER THORN -> CAPITAL"},

                           // Greek lowercase should convert to uppercase
                           ConversionTestCase{0x03B1, 0x0391,
                           "GREEK SMALL LETTER ALPHA -> CAPITAL"},
                           ConversionTestCase{0x03B2, 0x0392,
                           "GREEK SMALL LETTER BETA -> CAPITAL"},
                           ConversionTestCase{0x03B5, 0x0395,
                           "GREEK SMALL LETTER EPSILON -> CAPITAL"},
                           ConversionTestCase{0x03C9, 0x03A9,
                           "GREEK SMALL LETTER OMEGA -> CAPITAL"},

                           // Greek uppercase should remain unchanged
                           ConversionTestCase{0x0391, 0x0391,
                           "GREEK CAPITAL LETTER ALPHA -> CAPITAL"},
                           ConversionTestCase{0x0392, 0x0392,
                           "GREEK CAPITAL LETTER BETA -> CAPITAL"},
                           ConversionTestCase{0x0395, 0x0395,
                           "GREEK CAPITAL LETTER EPSILON -> CAPITAL"},
                           ConversionTestCase{0x03A9, 0x03A9,
                           "GREEK CAPITAL LETTER OMEGA -> CAPITAL"},

                           // Cyrillic lowercase should convert to uppercase
                           ConversionTestCase{0x0430, 0x0410,
                           "CYRILLIC SMALL LETTER A -> CAPITAL"},
                           ConversionTestCase{0x0431, 0x0411,
                           "CYRILLIC SMALL LETTER BE -> CAPITAL"},
                           ConversionTestCase{0x0434, 0x0414,
                           "CYRILLIC SMALL LETTER DE -> CAPITAL"},
                           ConversionTestCase{0x044F, 0x042F,
                           "CYRILLIC SMALL LETTER YA -> CAPITAL"},

                           // Cyrillic uppercase should remain unchanged
                           ConversionTestCase{0x0410, 0x0410,
                           "CYRILLIC CAPITAL LETTER A -> CAPITAL"},
                           ConversionTestCase{0x0411, 0x0411,
                           "CYRILLIC CAPITAL LETTER BE -> CAPITAL"},
                           ConversionTestCase{0x0414, 0x0414,
                           "CYRILLIC CAPITAL LETTER DE -> CAPITAL"},
                           ConversionTestCase{0x042F, 0x042F,
                           "CYRILLIC CAPITAL LETTER YA -> CAPITAL"},

                           // Non-alphabetic scripts (no case conversion)
                           ConversionTestCase{0x4E00, 0x4E00,
                           "CJK UNIFIED IDEOGRAPH-4E00 -> UNCHANGED"},
                           ConversionTestCase{0x3042, 0x3042,
                           "HIRAGANA LETTER A -> UNCHANGED"},
                           ConversionTestCase{0x30A2, 0x30A2,
                           "KATAKANA LETTER A -> UNCHANGED"},
                           ConversionTestCase{0xAC00, 0xAC00,
                           "HANGUL SYLLABLE GA -> UNCHANGED"},

                           // Arabic and Hebrew (no case conversion)
                           ConversionTestCase{0x0627, 0x0627,
                           "ARABIC LETTER ALEF -> UNCHANGED"},
                           ConversionTestCase{0x05D0, 0x05D0,
                           "HEBREW LETTER ALEF -> UNCHANGED"},

                           // Special cases
                           ConversionTestCase{0x0000, 0x0000, "NULL -> NULL"},
                           ConversionTestCase{0xFFFD, 0xFFFD,
                           "REPLACEMENT CHARACTER -> UNCHANGED"},
                           ConversionTestCase{WEOF, WEOF, "WEOF -> WEOF"}
                         ));