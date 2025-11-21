# Benchmarks against glibc

### Classification (~46KB)

```
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Iswdigit_My_ASCII_Digit          0.517 ns        0.517 ns   1000000000
BM_Iswdigit_Std_ASCII_Digit          4.31 ns         4.31 ns    163217519
BM_Iswdigit_My_ASCII_Letter         0.511 ns        0.511 ns   1000000000
BM_Iswdigit_Std_ASCII_Letter         4.07 ns         4.07 ns    168199695
BM_Iswdigit_My_Unicode              0.519 ns        0.519 ns   1000000000
BM_Iswdigit_Std_Unicode              6.22 ns         6.22 ns    113307228
BM_Iswdigit_My_Bulk_Mixed            16.5 ns         16.5 ns     42748728 
BM_Iswdigit_Std_Bulk_Mixed           83.7 ns         83.6 ns      8255764 
BM_Iswalpha_My_ASCII_Letter         0.516 ns        0.515 ns   1000000000
BM_Iswalpha_Std_ASCII_Letter         4.51 ns         4.51 ns    155415819
BM_Iswalpha_My_ASCII_Digit          0.519 ns        0.519 ns   1000000000
BM_Iswalpha_Std_ASCII_Digit          4.51 ns         4.51 ns    154522102
BM_Iswalpha_My_Latin_Extended       0.514 ns        0.514 ns   1000000000
BM_Iswalpha_Std_Latin_Extended       6.26 ns         6.26 ns    112519086
BM_Iswalpha_My_Greek                0.515 ns        0.515 ns   1000000000
BM_Iswalpha_Std_Greek                6.28 ns         6.27 ns    112988829
BM_Iswalpha_My_CJK                  0.508 ns        0.508 ns   1000000000
BM_Iswalpha_Std_CJK                  6.28 ns         6.28 ns    113269387
BM_Iswalpha_My_Bulk_Mixed            27.6 ns         27.6 ns     25470123 
BM_Iswalpha_Std_Bulk_Mixed            100 ns          100 ns      6890225 
BM_Iswgraph_My_ASCII_Letter         0.516 ns        0.516 ns   1000000000
BM_Iswgraph_Std_ASCII_Letter         4.37 ns         4.37 ns    159848648
BM_Iswgraph_My_ASCII_Digit          0.511 ns        0.511 ns   1000000000
BM_Iswgraph_Std_ASCII_Digit          4.12 ns         4.12 ns    169145522
BM_Iswgraph_My_ASCII_Space          0.517 ns        0.517 ns   1000000000
BM_Iswgraph_Std_ASCII_Space          4.44 ns         4.44 ns    158827173
BM_Iswgraph_My_Latin_Extended       0.518 ns        0.518 ns   1000000000
BM_Iswgraph_Std_Latin_Extended       6.27 ns         6.27 ns    111743414
BM_Iswgraph_My_Bulk_Mixed            41.6 ns         41.6 ns     16742011 
BM_Iswgraph_Std_Bulk_Mixed           83.3 ns         83.3 ns      8405566 
```

### Binary search conversions (~23KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Towupper_My_ASCII_Lower          0.580 ns        0.580 ns   1000000000
BM_Towupper_Std_ASCII_Lower          6.31 ns         6.30 ns    112672652
BM_Towupper_My_ASCII_Upper          0.539 ns        0.539 ns   1000000000
BM_Towupper_Std_ASCII_Upper          6.09 ns         6.08 ns    114810493
BM_Towupper_My_Latin_Extended        22.6 ns         22.5 ns     31139954
BM_Towupper_Std_Latin_Extended       6.19 ns         6.19 ns    114189946
BM_Towupper_My_Greek                 19.5 ns         19.5 ns     35866253
BM_Towupper_Std_Greek                6.01 ns         6.01 ns    115993149
BM_Towupper_My_No_Case               27.3 ns         27.2 ns     26309773
BM_Towupper_Std_No_Case              4.81 ns         4.81 ns    139741545
BM_Towupper_My_Bulk_ASCII            85.0 ns         85.0 ns      8278122 
BM_Towupper_Std_Bulk_ASCII            303 ns          303 ns      2356609 
BM_Towupper_My_Bulk_Unicode           318 ns          318 ns      2228428
BM_Towupper_Std_Bulk_Unicode          154 ns          154 ns      4491474
BM_Towupper_My_Random_ASCII          9.78 ns         9.78 ns     71217920
BM_Towupper_Std_Random_ASCII         9.93 ns         9.93 ns     72436969
BM_Towupper_My_High_Unicode          22.9 ns         22.9 ns     30396271
BM_Towupper_Std_High_Unicode         4.75 ns         4.75 ns    147322056
```

### Lookup table conversions (~50KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Towupper_My_ASCII_Lower          0.525 ns        0.525 ns   1000000000
BM_Towupper_Std_ASCII_Lower          6.33 ns         6.33 ns    115581778
BM_Towupper_My_ASCII_Upper          0.527 ns        0.527 ns   1000000000
BM_Towupper_Std_ASCII_Upper          6.22 ns         6.22 ns    111958122
BM_Towupper_My_Latin_Extended       0.525 ns        0.525 ns   1000000000
BM_Towupper_Std_Latin_Extended       6.27 ns         6.27 ns    111887025
BM_Towupper_My_Greek                0.530 ns        0.530 ns   1000000000
BM_Towupper_Std_Greek                6.20 ns         6.20 ns    114215341
BM_Towupper_My_No_Case              0.559 ns        0.559 ns   1000000000
BM_Towupper_Std_No_Case              4.87 ns         4.87 ns    141601477
BM_Towupper_My_Bulk_ASCII            65.1 ns         65.1 ns     10989903 
BM_Towupper_Std_Bulk_ASCII            319 ns          319 ns      1968582
BM_Towupper_My_Bulk_Unicode          54.6 ns         54.6 ns     12671219 
BM_Towupper_Std_Bulk_Unicode          162 ns          162 ns      4318972 
BM_Towupper_My_Random_ASCII          10.1 ns         10.1 ns     69533983
BM_Towupper_Std_Random_ASCII         10.2 ns         10.2 ns     69953180
BM_Towupper_My_High_Unicode         0.558 ns        0.558 ns   1000000000
BM_Towupper_Std_High_Unicode         4.94 ns         4.93 ns    112931123
```