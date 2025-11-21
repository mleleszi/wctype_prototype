#include <benchmark/benchmark.h>
#include "mywctype.h"
#include <vector>
#include <random>
#include <locale>

static void SetupBenchmarks() {
  std::locale::global(std::locale("C.UTF-8"));
}

// Benchmark single character conversion - ASCII lowercase
static void BM_Towupper_My_ASCII_Lower(benchmark::State &state) {
  wint_t c = L'a';
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_ASCII_Lower);

static void BM_Towupper_Std_ASCII_Lower(benchmark::State &state) {
  wint_t c = L'a';
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_ASCII_Lower);

// Benchmark single character conversion - ASCII uppercase (no change)
static void BM_Towupper_My_ASCII_Upper(benchmark::State &state) {
  wint_t c = L'A';
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_ASCII_Upper);

static void BM_Towupper_Std_ASCII_Upper(benchmark::State &state) {
  wint_t c = L'A';
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_ASCII_Upper);

// Benchmark single character conversion - Latin Extended
static void BM_Towupper_My_Latin_Extended(benchmark::State &state) {
  wint_t c = 0x00E0; // à
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_Latin_Extended);

static void BM_Towupper_Std_Latin_Extended(benchmark::State &state) {
  wint_t c = 0x00E0; // à
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_Latin_Extended);

// Benchmark single character conversion - Greek
static void BM_Towupper_My_Greek(benchmark::State &state) {
  wint_t c = 0x03B1; // α
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_Greek);

static void BM_Towupper_Std_Greek(benchmark::State &state) {
  wint_t c = 0x03B1; // α
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_Greek);

// Benchmark single character conversion - No case conversion (CJK)
static void BM_Towupper_My_No_Case(benchmark::State &state) {
  wint_t c = 0x4E00; // CJK
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_No_Case);

static void BM_Towupper_Std_No_Case(benchmark::State &state) {
  wint_t c = 0x4E00; // CJK
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_No_Case);

// Benchmark bulk conversion - Mixed ASCII text
static void BM_Towupper_My_Bulk_ASCII(benchmark::State &state) {
  std::vector<wint_t> text;
  const char *sample = "The Quick Brown Fox Jumps Over The Lazy Dog 123!";
  for (const char *p = sample; *p; ++p) {
    text.push_back(static_cast<wint_t>(*p));
  }

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = my_wctype::towupper(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towupper_My_Bulk_ASCII);

static void BM_Towupper_Std_Bulk_ASCII(benchmark::State &state) {
  std::vector<wint_t> text;
  const char *sample = "The Quick Brown Fox Jumps Over The Lazy Dog 123!";
  for (const char *p = sample; *p; ++p) {
    text.push_back(static_cast<wint_t>(*p));
  }

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = std::towupper(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towupper_Std_Bulk_ASCII);

// Benchmark bulk conversion - Unicode text
static void BM_Towupper_My_Bulk_Unicode(benchmark::State &state) {
  std::vector<wint_t> text = {
      // Latin Extended
      0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4,
      // Greek
      0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5,
      // Cyrillic
      0x0430, 0x0431, 0x0432, 0x0433, 0x0434,
      // Mixed with ASCII
      L'a', L'b', L'c', L'd', L'e',
      // Uppercase (no conversion)
      L'A', L'B', L'C', L'D', L'E',
  };

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = my_wctype::towupper(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towupper_My_Bulk_Unicode);

static void BM_Towupper_Std_Bulk_Unicode(benchmark::State &state) {
  std::vector<wint_t> text = {
      // Latin Extended
      0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4,
      // Greek
      0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5,
      // Cyrillic
      0x0430, 0x0431, 0x0432, 0x0433, 0x0434,
      // Mixed with ASCII
      L'a', L'b', L'c', L'd', L'e',
      // Uppercase (no conversion)
      L'A', L'B', L'C', L'D', L'E',
  };

  for (auto _ : state) {
    for (wint_t c : text) {
      wint_t result = std::towupper(c);
      benchmark::DoNotOptimize(result);
    }
  }
  state.SetItemsProcessed(state.iterations() * text.size());
}

BENCHMARK(BM_Towupper_Std_Bulk_Unicode);

// Benchmark random characters from different ranges
static void BM_Towupper_My_Random_ASCII(benchmark::State &state) {
  std::vector<wint_t> chars;
  std::mt19937 rng(42);
  std::uniform_int_distribution<wint_t> dist(0x20, 0x7E);

  for (int i = 0; i < 1000; ++i) {
    chars.push_back(dist(rng));
  }

  size_t idx = 0;
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(chars[idx]);
    benchmark::DoNotOptimize(result);
    idx = (idx + 1) % chars.size();
  }
}

BENCHMARK(BM_Towupper_My_Random_ASCII);

static void BM_Towupper_Std_Random_ASCII(benchmark::State &state) {
  std::vector<wint_t> chars;
  std::mt19937 rng(42);
  std::uniform_int_distribution<wint_t> dist(0x20, 0x7E);

  for (int i = 0; i < 1000; ++i) {
    chars.push_back(dist(rng));
  }

  size_t idx = 0;
  for (auto _ : state) {
    wint_t result = std::towupper(chars[idx]);
    benchmark::DoNotOptimize(result);
    idx = (idx + 1) % chars.size();
  }
}

BENCHMARK(BM_Towupper_Std_Random_ASCII);

// Benchmark worst case - high Unicode codepoints
static void BM_Towupper_My_High_Unicode(benchmark::State &state) {
  wint_t c = 0x1F000; // High Unicode range
  for (auto _ : state) {
    wint_t result = my_wctype::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_My_High_Unicode);

static void BM_Towupper_Std_High_Unicode(benchmark::State &state) {
  wint_t c = 0x1F000; // High Unicode range
  for (auto _ : state) {
    wint_t result = std::towupper(c);
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(BM_Towupper_Std_High_Unicode);

int main(int argc, char **argv) {
  SetupBenchmarks();
  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();
  return 0;
}