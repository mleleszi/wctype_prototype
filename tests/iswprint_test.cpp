#include "wctype_test_base.h"
#include "mywctype.h"

class PrintTest : public WctypeTest,
                  public ::testing::WithParamInterface<TestCase> {
};

TEST_P(PrintTest, IsPrint) {
  auto test = GetParam();
  int my_result = my_wctype::iswprint(test.codepoint);
  int std_result = std::iswprint(static_cast<wint_t>(test.codepoint));

  EXPECT_EQ((my_result != 0), test.expected)
    << "Failed for U+" << std::hex << test.codepoint << " (" << test.name <<
 ")";
  EXPECT_EQ((my_result != 0), (std_result != 0))
    << "Mismatch with std for U+" << std::hex << test.codepoint << " (" << test.
name << ")";
}

INSTANTIATE_TEST_SUITE_P(PrintTests, PrintTest, ::testing::Values(
                           // ASCII printable characters
                           TestCase{0x0020, "SPACE", true},
                           TestCase{0x0021, "EXCLAMATION MARK", true},
                           TestCase{0x0030, "DIGIT ZERO", true},
                           TestCase{0x0041, "LATIN CAPITAL LETTER A", true},
                           TestCase{0x0061, "LATIN SMALL LETTER A", true},
                           TestCase{0x007E, "TILDE", true},

                           // ASCII control characters (not printable)
                           TestCase{0x0000, "NULL", false},
                           TestCase{0x0009, "TAB", false},
                           TestCase{0x000A, "LINE FEED", false},
                           TestCase{0x000D, "CARRIAGE RETURN", false},
                           TestCase{0x001F, "UNIT SEPARATOR", false},
                           TestCase{0x007F, "DELETE", false},

                           // Latin Extended (printable)
                           TestCase{0x00A0, "NO-BREAK SPACE", true},
                           TestCase{0x00C0, "LATIN CAPITAL LETTER A WITH GRAVE",
                           true},
                           TestCase{0x00E9, "LATIN SMALL LETTER E WITH ACUTE",
                           true},
                           TestCase{0x00FF,
                           "LATIN SMALL LETTER Y WITH DIAERESIS", true},

                           // Greek (printable)
                           TestCase{0x0391, "GREEK CAPITAL LETTER ALPHA", true},
                           TestCase{0x03B1, "GREEK SMALL LETTER ALPHA", true},

                           // Cyrillic (printable)
                           TestCase{0x0410, "CYRILLIC CAPITAL LETTER A", true},
                           TestCase{0x0430, "CYRILLIC SMALL LETTER A", true},

                           // Arabic (printable)
                           TestCase{0x0627, "ARABIC LETTER ALEF", true},

                           // Hebrew (printable)
                           TestCase{0x05D0, "HEBREW LETTER ALEF", true},

                           // CJK (printable)
                           TestCase{0x4E00, "CJK UNIFIED IDEOGRAPH-4E00", true},
                           TestCase{0x9FFF, "CJK UNIFIED IDEOGRAPH-9FFF", true},

                           // Hiragana (printable)
                           TestCase{0x3042, "HIRAGANA LETTER A", true},

                           // Katakana (printable)
                           TestCase{0x30A2, "KATAKANA LETTER A", true},

                           // Hangul (printable)
                           TestCase{0xAC00, "HANGUL SYLLABLE GA", true},

                           // Emoji and symbols (printable)
                           TestCase{0x1F600, "GRINNING FACE", true},
                           TestCase{0x2764, "HEAVY BLACK HEART", true},

                           // Punctuation (printable)
                           TestCase{0x002E, "FULL STOP", true},
                           TestCase{0x002C, "COMMA", true},
                           TestCase{0x003A, "COLON", true},

                           // C1 control characters (not printable)
                           TestCase{0x0080, "PADDING CHARACTER", false},
                           TestCase{0x009F, "APPLICATION PROGRAM COMMAND", false
                           },

                           // Special cases
                           TestCase{0xFFFD, "REPLACEMENT CHARACTER", true}
                         ));