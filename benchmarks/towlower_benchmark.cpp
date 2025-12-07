#include <benchmark/benchmark.h>
#include "mywctype.h"
#include <vector>
#include <random>
#include <locale>
#include "v8/v8_unicode.h"

static void SetupBenchmarks() {
  std::locale::global(std::locale("C.UTF-8"));
}

// Benchmark single character conversion - ASCII uppercase
static void BM_Towlower_My_ASCII_Upper(benchmark::State &state) {
  wint_t c = L'A';
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_ASCII_Upper);

static void BM_Towlower_Std_ASCII_Upper(benchmark::State &state) {
  wint_t c = L'A';
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_ASCII_Upper);

static void BM_Towlower_V8_ASCII_Upper(benchmark::State &state) {
  wint_t c = L'A';
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_ASCII_Upper);

// Benchmark single character conversion - ASCII lowercase (no change)
static void BM_Towlower_My_ASCII_Lower(benchmark::State &state) {
  wint_t c = L'a';
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_ASCII_Lower);

static void BM_Towlower_Std_ASCII_Lower(benchmark::State &state) {
  wint_t c = L'a';
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_ASCII_Lower);

static void BM_Towlower_V8_ASCII_Lower(benchmark::State &state) {
  wint_t c = L'a';
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_ASCII_Lower);

// Benchmark single character conversion - Latin Extended
static void BM_Towlower_My_Latin_Extended(benchmark::State &state) {
  wint_t c = 0x00C0; // À
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_Latin_Extended);

static void BM_Towlower_Std_Latin_Extended(benchmark::State &state) {
  wint_t c = 0x00C0; // À
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_Latin_Extended);

static void BM_Towlower_V8_Latin_Extended(benchmark::State &state) {
  wint_t c = 0x00C0; // À
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_Latin_Extended);

// Benchmark single character conversion - Greek
static void BM_Towlower_My_Greek(benchmark::State &state) {
  wint_t c = 0x0391; // Α
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_Greek);

static void BM_Towlower_Std_Greek(benchmark::State &state) {
  wint_t c = 0x0391; // Α
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_Greek);

static void BM_Towlower_V8_Greek(benchmark::State &state) {
  wint_t c = 0x0391; // Α
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_Greek);

// Benchmark single character conversion - No case conversion (CJK)
static void BM_Towlower_My_No_Case(benchmark::State &state) {
  wint_t c = 0x4E00; // CJK
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_No_Case);

static void BM_Towlower_Std_No_Case(benchmark::State &state) {
  wint_t c = 0x4E00; // CJK
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_No_Case);

static void BM_Towlower_V8_No_Case(benchmark::State &state) {
  wint_t c = 0x4E00; // CJK
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_No_Case);

// Benchmark bulk conversion - Mixed ASCII text
static void BM_Towlower_My_Bulk_ASCII(benchmark::State &state) {
  std::vector<wint_t> text;
  const char *sample = "The Quick Brown Fox Jumps Over The Lazy Dog 123!";
  for (const char *p = sample; *p; ++p) {
    text.push_back(static_cast<wint_t>(*p));
  }

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = my_wctype::towlower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_My_Bulk_ASCII);

static void BM_Towlower_Std_Bulk_ASCII(benchmark::State &state) {
  std::vector<wint_t> text;
  const char *sample = "The Quick Brown Fox Jumps Over The Lazy Dog 123!";
  for (const char *p = sample; *p; ++p) {
    text.push_back(static_cast<wint_t>(*p));
  }

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = std::towlower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_Std_Bulk_ASCII);

static void BM_Towlower_V8_Bulk_ASCII(benchmark::State &state) {
  std::vector<wint_t> text;
  const char *sample = "The Quick Brown Fox Jumps Over The Lazy Dog 123!";
  for (const char *p = sample; *p; ++p) {
    text.push_back(static_cast<wint_t>(*p));
  }

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = v8_unicode::ToLower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_V8_Bulk_ASCII);

// Benchmark bulk conversion - Unicode text
static void BM_Towlower_My_Bulk_Unicode(benchmark::State &state) {
  std::vector<wint_t> text = {
      // Latin Extended
      0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4,
      // Greek
      0x0391, 0x0392, 0x0393, 0x0394, 0x0395,
      // Cyrillic
      0x0410, 0x0411, 0x0412, 0x0413, 0x0414,
      // Mixed with ASCII
      L'A', L'B', L'C', L'D', L'E',
      // Lowercase (no conversion)
      L'a', L'b', L'c', L'd', L'e',
  };

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = my_wctype::towlower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_My_Bulk_Unicode);

static void BM_Towlower_Std_Bulk_Unicode(benchmark::State &state) {
  std::vector<wint_t> text = {
      // Latin Extended
      0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4,
      // Greek
      0x0391, 0x0392, 0x0393, 0x0394, 0x0395,
      // Cyrillic
      0x0410, 0x0411, 0x0412, 0x0413, 0x0414,
      // Mixed with ASCII
      L'A', L'B', L'C', L'D', L'E',
      // Lowercase (no conversion)
      L'a', L'b', L'c', L'd', L'e',
  };

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = std::towlower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_Std_Bulk_Unicode);

static void BM_Towlower_V8_Bulk_Unicode(benchmark::State &state) {
  std::vector<wint_t> text = {
      // Latin Extended
      0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4,
      // Greek
      0x0391, 0x0392, 0x0393, 0x0394, 0x0395,
      // Cyrillic
      0x0410, 0x0411, 0x0412, 0x0413, 0x0414,
      // Mixed with ASCII
      L'A', L'B', L'C', L'D', L'E',
      // Lowercase (no conversion)
      L'a', L'b', L'c', L'd', L'e',
  };

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = v8_unicode::ToLower(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towlower_V8_Bulk_Unicode);

// Benchmark random characters from different ranges
static void BM_Towlower_My_Random_ASCII(benchmark::State &state) {
  std::vector<wint_t> chars;
  std::mt19937 rng(42);
  std::uniform_int_distribution<wint_t> dist(0x20, 0x7E);

  for (int i = 0; i < 1000; ++i) {
    chars.push_back(dist(rng));
  }

  size_t idx = 0;
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(chars[idx]);
    benchmark::DoNotOptimize(result);
    idx = (idx + 1) % chars.size();
  }
}

BENCHMARK(BM_Towlower_My_Random_ASCII);

static void BM_Towlower_Std_Random_ASCII(benchmark::State &state) {
  std::vector<wint_t> chars;
  std::mt19937 rng(42);
  std::uniform_int_distribution<wint_t> dist(0x20, 0x7E);

  for (int i = 0; i < 1000; ++i) {
    chars.push_back(dist(rng));
  }

  size_t idx = 0;
  for (auto _ : state) {
    wint_t result = std::towlower(chars[idx]);
    benchmark::DoNotOptimize(result);
    idx = (idx + 1) % chars.size();
  }
}

BENCHMARK(BM_Towlower_Std_Random_ASCII);

static void BM_Towlower_V8_Random_ASCII(benchmark::State &state) {
  std::vector<wint_t> chars;
  std::mt19937 rng(42);
  std::uniform_int_distribution<wint_t> dist(0x20, 0x7E);

  for (int i = 0; i < 1000; ++i) {
    chars.push_back(dist(rng));
  }

  size_t idx = 0;
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(chars[idx]);
    benchmark::DoNotOptimize(result);
    idx = (idx + 1) % chars.size();
  }
}

BENCHMARK(BM_Towlower_V8_Random_ASCII);

// Benchmark worst case - high Unicode codepoints
static void BM_Towlower_My_High_Unicode(benchmark::State &state) {
  wint_t c = 0x1F000; // High Unicode range
  for (auto _ : state) {
    wint_t result = my_wctype::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_My_High_Unicode);

static void BM_Towlower_Std_High_Unicode(benchmark::State &state) {
  wint_t c = 0x1F000; // High Unicode range
  for (auto _ : state) {
    wint_t result = std::towlower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_Std_High_Unicode);

static void BM_Towlower_V8_High_Unicode(benchmark::State &state) {
  wint_t c = 0x1F000; // High Unicode range
  for (auto _ : state) {
    wint_t result = v8_unicode::ToLower(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towlower_V8_High_Unicode);

int main(int argc, char **argv) {
  SetupBenchmarks();
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  return 0;
}
