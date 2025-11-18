#include "wctype_test_base.h"
#include "mywctype.h"

class CntrlTest : public WctypeTest,
                  public ::testing::WithParamInterface<TestCase> {
};

TEST_P(CntrlTest, IsCntrl) {
  auto test = GetParam();
  int my_result = my_wctype::iswcntrl(test.codepoint);
  int std_result = std::iswcntrl(static_cast<wint_t>(test.codepoint));

  EXPECT_EQ((my_result != 0), test.expected)
    << "Failed for U+" << std::hex << test.codepoint << " (" << test.name <<
 ")";
  EXPECT_EQ((my_result != 0), (std_result != 0))
    << "Mismatch with std for U+" << std::hex << test.codepoint << " (" << test.
name << ")";
}

INSTANTIATE_TEST_SUITE_P(CntrlTests, CntrlTest, ::testing::Values(
                           // ASCII control characters (0x00-0x1F)
                           TestCase{0x0000, "NULL", true},
                           TestCase{0x0001, "START OF HEADING", true},
                           TestCase{0x0009, "TAB", true},
                           TestCase{0x000A, "LINE FEED", true},
                           TestCase{0x000D, "CARRIAGE RETURN", true},
                           TestCase{0x001B, "ESCAPE", true},
                           TestCase{0x001F, "UNIT SEPARATOR", true},

                           // ASCII printable characters (not control)
                           TestCase{0x0020, "SPACE", false},
                           TestCase{0x0021, "EXCLAMATION MARK", false},
                           TestCase{0x0030, "DIGIT ZERO", false},
                           TestCase{0x0041, "LATIN CAPITAL LETTER A", false},
                           TestCase{0x0061, "LATIN SMALL LETTER A", false},
                           TestCase{0x007E, "TILDE", false},

                           // DELETE character
                           TestCase{0x007F, "DELETE", true},

                           // C1 control characters (0x80-0x9F)
                           TestCase{0x0080, "PADDING CHARACTER", true},
                           TestCase{0x0081, "HIGH OCTET PRESET", true},
                           TestCase{0x0090, "DEVICE CONTROL STRING", true},
                           TestCase{0x009F, "APPLICATION PROGRAM COMMAND", true}
                           ,

                           // Non-control characters after C1 range
                           TestCase{0x00A0, "NO-BREAK SPACE", false},
                           TestCase{0x00A1, "INVERTED EXCLAMATION MARK", false},
                           TestCase{0x00C0, "LATIN CAPITAL LETTER A WITH GRAVE",
                           false},
                           TestCase{0x00E9, "LATIN SMALL LETTER E WITH ACUTE",
                           false},

                           // Letters (not control)
                           TestCase{0x0391, "GREEK CAPITAL LETTER ALPHA", false}
                           ,
                           TestCase{0x0410, "CYRILLIC CAPITAL LETTER A", false},
                           TestCase{0x4E00, "CJK UNIFIED IDEOGRAPH-4E00", false}
                         ));