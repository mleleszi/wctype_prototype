#include "wctype_test_base.h"
#include "mywctype.h"

class UpperTest : public WctypeTest,
                  public ::testing::WithParamInterface<TestCase> {
};

TEST_P(UpperTest, IsUpper) {
  auto test = GetParam();
  int my_result = my_wctype::iswupper(test.codepoint);
  int std_result = std::iswupper(static_cast<wint_t>(test.codepoint));

  EXPECT_EQ((my_result != 0), test.expected)
    << "Failed for U+" << std::hex << test.codepoint << " (" << test.name <<
 ")";
  EXPECT_EQ((my_result != 0), (std_result != 0))
    << "Mismatch with std for U+" << std::hex << test.codepoint << " (" << test.
name << ")";
}

INSTANTIATE_TEST_SUITE_P(UpperTests, UpperTest, ::testing::Values(
                           // ASCII uppercase letters
                           TestCase{0x0041, "LATIN CAPITAL LETTER A", true},
                           TestCase{0x0042, "LATIN CAPITAL LETTER B", true},
                           TestCase{0x0048, "LATIN CAPITAL LETTER H", true},
                           TestCase{0x005A, "LATIN CAPITAL LETTER Z", true},

                           // ASCII lowercase letters (not uppercase)
                           TestCase{0x0061, "LATIN SMALL LETTER A", false},
                           TestCase{0x0062, "LATIN SMALL LETTER B", false},
                           TestCase{0x0068, "LATIN SMALL LETTER H", false},
                           TestCase{0x007A, "LATIN SMALL LETTER Z", false},

                           // ASCII non-letters
                           TestCase{0x0030, "DIGIT ZERO", false},
                           TestCase{0x0039, "DIGIT NINE", false},
                           TestCase{0x0020, "SPACE", false},
                           TestCase{0x0021, "EXCLAMATION MARK", false},
                           TestCase{0x0040, "AT SIGN", false},
                           TestCase{0x005B, "LEFT SQUARE BRACKET", false},
                           TestCase{0x0060, "GRAVE ACCENT", false},
                           TestCase{0x007B, "LEFT CURLY BRACKET", false},

                           // Latin Extended uppercase
                           TestCase{0x00C0, "LATIN CAPITAL LETTER A WITH GRAVE",
                           true},
                           TestCase{0x00C1, "LATIN CAPITAL LETTER A WITH ACUTE",
                           true},
                           TestCase{0x00D6,
                           "LATIN CAPITAL LETTER O WITH DIAERESIS", true},
                           TestCase{0x00DE, "LATIN CAPITAL LETTER THORN", true},

                           // Latin Extended lowercase (not uppercase)
                           TestCase{0x00E0, "LATIN SMALL LETTER A WITH GRAVE",
                           false},
                           TestCase{0x00E1, "LATIN SMALL LETTER A WITH ACUTE",
                           false},
                           TestCase{0x00F6,
                           "LATIN SMALL LETTER O WITH DIAERESIS", false},
                           TestCase{0x00FF,
                           "LATIN SMALL LETTER Y WITH DIAERESIS", false},

                           // Greek uppercase
                           TestCase{0x0391, "GREEK CAPITAL LETTER ALPHA", true},
                           TestCase{0x0392, "GREEK CAPITAL LETTER BETA", true},
                           TestCase{0x0395, "GREEK CAPITAL LETTER EPSILON", true
                           },
                           TestCase{0x03A9, "GREEK CAPITAL LETTER OMEGA", true},

                           // Greek lowercase (not uppercase)
                           TestCase{0x03B1, "GREEK SMALL LETTER ALPHA", false},
                           TestCase{0x03B2, "GREEK SMALL LETTER BETA", false},
                           TestCase{0x03B5, "GREEK SMALL LETTER EPSILON", false}
                           ,
                           TestCase{0x03C9, "GREEK SMALL LETTER OMEGA", false},

                           // Cyrillic uppercase
                           TestCase{0x0410, "CYRILLIC CAPITAL LETTER A", true},
                           TestCase{0x0411, "CYRILLIC CAPITAL LETTER BE", true},
                           TestCase{0x0414, "CYRILLIC CAPITAL LETTER DE", true},
                           TestCase{0x042F, "CYRILLIC CAPITAL LETTER YA", true},

                           // Cyrillic lowercase (not uppercase)
                           TestCase{0x0430, "CYRILLIC SMALL LETTER A", false},
                           TestCase{0x0431, "CYRILLIC SMALL LETTER BE", false},
                           TestCase{0x0434, "CYRILLIC SMALL LETTER DE", false},
                           TestCase{0x044F, "CYRILLIC SMALL LETTER YA", false},

                           // Non-alphabetic scripts (no case)
                           TestCase{0x4E00, "CJK UNIFIED IDEOGRAPH-4E00", false}
                           ,
                           TestCase{0x3042, "HIRAGANA LETTER A", false},
                           TestCase{0x30A2, "KATAKANA LETTER A", false},
                           TestCase{0xAC00, "HANGUL SYLLABLE GA", false},

                           // Arabic and Hebrew (no case)
                           TestCase{0x0627, "ARABIC LETTER ALEF", false},
                           TestCase{0x05D0, "HEBREW LETTER ALEF", false},

                           // Special cases
                           TestCase{0x0000, "NULL", false},
                           TestCase{0xFFFD, "REPLACEMENT CHARACTER", false}
                         ));