# Benchmarks against glibc

### Classification (~46KB)

```
-------------------------------------------------------------------------------
Benchmark                                     Time             CPU   Iterations
-------------------------------------------------------------------------------
BM_Iswdigit_My_ASCII_Digit                0.249 ns        0.249 ns   2846362358
BM_Iswdigit_Std_ASCII_Digit               0.753 ns        0.753 ns    933586808
BM_Iswdigit_My_ASCII_Letter               0.246 ns        0.246 ns   2838442894
BM_Iswdigit_Std_ASCII_Letter              0.746 ns        0.746 ns    973487892
BM_Iswdigit_My_Unicode                    0.238 ns        0.238 ns   2867985246
BM_Iswdigit_Std_Unicode                    2.25 ns         2.25 ns    310709673
BM_Iswdigit_My_Bulk_Mixed                  6.32 ns         6.32 ns    122417063 items_per_second=2.37236G/s
BM_Iswdigit_Std_Bulk_Mixed                 32.3 ns         32.3 ns     21908916 items_per_second=464.173M/s
BM_Iswalpha_My_ASCII_Letter               0.251 ns        0.251 ns   2884001564
BM_Iswalpha_Std_ASCII_Letter              0.610 ns        0.610 ns   1105658477
BM_Iswalpha_V8_ASCII_Letter                5.60 ns         5.60 ns    125531149
BM_Iswalpha_My_ASCII_Digit                0.246 ns        0.246 ns   2879662381
BM_Iswalpha_Std_ASCII_Digit               0.618 ns        0.618 ns   1153053696
BM_Iswalpha_My_Latin_Extended             0.251 ns        0.251 ns   2807154662
BM_Iswalpha_Std_Latin_Extended             2.34 ns         2.34 ns    298664815
BM_Iswalpha_V8_Latin_Extended              7.54 ns         7.54 ns     92266905
BM_Iswalpha_My_Greek                      0.251 ns        0.251 ns   2787507062
BM_Iswalpha_Std_Greek                      2.35 ns         2.35 ns    298592589
BM_Iswalpha_V8_Greek                       5.70 ns         5.70 ns    122877040
BM_Iswalpha_My_CJK                        0.251 ns        0.251 ns   2785413636
BM_Iswalpha_Std_CJK                        2.35 ns         2.35 ns    297038592
BM_Iswalpha_V8_CJK                         2.05 ns         2.05 ns    341331917
BM_Iswalpha_My_Bulk_Mixed                  12.2 ns         12.2 ns     57062695 items_per_second=1.96218G/s
BM_Iswalpha_Std_Bulk_Mixed                 39.3 ns         39.3 ns     18040405 items_per_second=611.451M/s
BM_Iswalpha_V8_Bulk_Mixed                   165 ns          165 ns      4223854 items_per_second=145.574M/s
BM_Iswgraph_My_ASCII_Letter               0.253 ns        0.253 ns   2773401032
BM_Iswgraph_Std_ASCII_Letter              0.633 ns        0.633 ns   1103988963
BM_Iswgraph_My_ASCII_Digit                0.253 ns        0.253 ns   2770343977
BM_Iswgraph_Std_ASCII_Digit               0.641 ns        0.641 ns   1086891021
BM_Iswgraph_My_ASCII_Space                0.257 ns        0.257 ns   2720969643
BM_Iswgraph_Std_ASCII_Space               0.641 ns        0.641 ns   1095097432
BM_Iswgraph_My_Latin_Extended             0.257 ns        0.257 ns   2726780331
BM_Iswgraph_Std_Latin_Extended             2.42 ns         2.42 ns    287475944
BM_Iswgraph_My_Bulk_Mixed                  20.8 ns         20.8 ns     32721012 items_per_second=963.559M/s
BM_Iswgraph_Std_Bulk_Mixed                 38.7 ns         38.7 ns     18009834 items_per_second=517.188M/s
BM_Iswupper_My_ASCII_Upper                0.257 ns        0.257 ns   2730131288
BM_Iswupper_Std_ASCII_Upper               0.641 ns        0.641 ns   1104864087
BM_Iswupper_V8_ASCII_Upper                 6.97 ns         6.97 ns    102187710
BM_Iswupper_My_ASCII_Lower                0.252 ns        0.252 ns   2751390123
BM_Iswupper_Std_ASCII_Lower               0.644 ns        0.644 ns   1085002792
BM_Iswupper_My_Latin_Extended_Upper       0.255 ns        0.255 ns   2730239423
BM_Iswupper_Std_Latin_Extended_Upper       2.34 ns         2.34 ns    298768070
BM_Iswupper_V8_Latin_Extended_Upper        5.86 ns         5.86 ns    117920271
BM_Iswupper_My_Greek_Upper                0.254 ns        0.254 ns   2827411711
BM_Iswupper_Std_Greek_Upper                2.36 ns         2.36 ns    307440978
BM_Iswupper_V8_Greek_Upper                 7.42 ns         7.42 ns     95628141
BM_Iswupper_My_Cyrillic_Upper             0.257 ns        0.256 ns   2708114195
BM_Iswupper_My_Bulk_Mixed                  21.6 ns         21.6 ns     33111146 items_per_second=1.1094G/s
BM_Iswupper_Std_Bulk_Mixed                 38.1 ns         38.1 ns     18398484 items_per_second=577.503M/s
BM_Iswupper_V8_Bulk_Mixed                   179 ns          179 ns      3763117 items_per_second=122.958M/s
```

### Binary search conversions (~22.6KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Towlower_My_ASCII_Upper          0.156 ns        0.156 ns   4345325743
BM_Towlower_Std_ASCII_Upper          3.77 ns         3.77 ns    186876539
BM_Towlower_My_ASCII_Lower          0.156 ns        0.156 ns   4434158913
BM_Towlower_Std_ASCII_Lower          3.59 ns         3.59 ns    192027455
BM_Towlower_My_Latin_Extended        8.84 ns         8.84 ns     78749225
BM_Towlower_Std_Latin_Extended       3.58 ns         3.58 ns    194292733
BM_Towlower_My_Greek                 11.9 ns         11.9 ns     59211941
BM_Towlower_Std_Greek                3.63 ns         3.62 ns    194658384
BM_Towlower_My_No_Case               9.57 ns         9.57 ns     72040431
BM_Towlower_Std_No_Case              3.12 ns         3.12 ns    224975541
BM_Towlower_My_Bulk_ASCII            35.5 ns         35.5 ns     19805919 items_per_second=1.35388G/s
BM_Towlower_Std_Bulk_ASCII            182 ns          182 ns      3860759 items_per_second=264.163M/s
BM_Towlower_My_Bulk_Unicode           196 ns          195 ns      3602406 items_per_second=127.903M/s
BM_Towlower_Std_Bulk_Unicode         94.6 ns         94.6 ns      7390744 items_per_second=264.382M/s
BM_Towlower_My_Random_ASCII          3.42 ns         3.42 ns    204793694
BM_Towlower_Std_Random_ASCII         3.74 ns         3.74 ns    187489830
BM_Towlower_My_High_Unicode          10.3 ns         10.3 ns     67832946
BM_Towlower_Std_High_Unicode         2.98 ns         2.98 ns    236148282
```

### Lookup table conversions (~53KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Towlower_My_ASCII_Upper          0.173 ns        0.173 ns   4501351589
BM_Towlower_Std_ASCII_Upper          3.77 ns         3.76 ns    178419308
BM_Towlower_My_ASCII_Lower          0.157 ns        0.157 ns   4472426586
BM_Towlower_Std_ASCII_Lower          3.61 ns         3.60 ns    194666627
BM_Towlower_My_Latin_Extended       0.157 ns        0.157 ns   4482527486
BM_Towlower_Std_Latin_Extended       3.63 ns         3.62 ns    189592759
BM_Towlower_My_Greek                0.157 ns        0.157 ns   4439466351
BM_Towlower_Std_Greek                3.59 ns         3.59 ns    195068712
BM_Towlower_My_No_Case              0.158 ns        0.157 ns   4478772974
BM_Towlower_Std_No_Case              3.13 ns         3.12 ns    223389275
BM_Towlower_My_Bulk_ASCII            36.9 ns         36.9 ns     19183834 items_per_second=1.30061G/s
BM_Towlower_Std_Bulk_ASCII            182 ns          182 ns      3872062 items_per_second=263.205M/s
BM_Towlower_My_Bulk_Unicode          27.0 ns         27.0 ns     25872212 items_per_second=925.573M/s
BM_Towlower_Std_Bulk_Unicode         95.4 ns         95.4 ns      7316496 items_per_second=262.107M/s
BM_Towlower_My_Random_ASCII          3.42 ns         3.42 ns    204048070
BM_Towlower_Std_Random_ASCII         3.77 ns         3.77 ns    183515865
BM_Towlower_My_High_Unicode         0.156 ns        0.156 ns   4461467165
BM_Towlower_Std_High_Unicode         2.96 ns         2.96 ns    235853408
```

### Hash Table Conversion (~24.5KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Towlower_My_ASCII_Upper          0.247 ns        0.247 ns   2849853096
BM_Towlower_Std_ASCII_Upper          2.24 ns         2.24 ns    308207894
BM_Towlower_V8_ASCII_Upper           8.86 ns         8.86 ns     78951688
BM_Towlower_My_ASCII_Lower          0.240 ns        0.240 ns   2911303088
BM_Towlower_Std_ASCII_Lower          2.25 ns         2.25 ns    312797821
BM_Towlower_V8_ASCII_Lower           7.37 ns         7.37 ns     94579645
BM_Towlower_My_Latin_Extended        1.86 ns         1.86 ns    380475425
BM_Towlower_Std_Latin_Extended       2.27 ns         2.27 ns    313141315
BM_Towlower_V8_Latin_Extended        7.63 ns         7.63 ns     93185081
BM_Towlower_My_Greek                 1.98 ns         1.98 ns    352814902
BM_Towlower_Std_Greek                2.34 ns         2.34 ns    287589373
BM_Towlower_V8_Greek                 8.61 ns         8.61 ns     79747250
BM_Towlower_My_No_Case               1.83 ns         1.83 ns    383594297
BM_Towlower_Std_No_Case              1.94 ns         1.94 ns    357436982
BM_Towlower_V8_No_Case              0.245 ns        0.245 ns   2888608410
BM_Towlower_My_Bulk_ASCII            22.8 ns         22.8 ns     30384842 items_per_second=2.10419G/s
BM_Towlower_Std_Bulk_ASCII            117 ns          117 ns      6045124 items_per_second=411.471M/s
BM_Towlower_V8_Bulk_ASCII             486 ns          486 ns      1427434 items_per_second=98.8365M/s
BM_Towlower_My_Bulk_Unicode          35.7 ns         35.7 ns     20083889 items_per_second=699.59M/s
BM_Towlower_Std_Bulk_Unicode         68.4 ns         68.4 ns     10271206 items_per_second=365.384M/s
BM_Towlower_V8_Bulk_Unicode           219 ns          218 ns      3170228 items_per_second=114.417M/s
BM_Towlower_My_Random_ASCII          3.89 ns         3.89 ns    179036811
BM_Towlower_Std_Random_ASCII         3.97 ns         3.96 ns    175623649
BM_Towlower_V8_Random_ASCII          9.73 ns         9.73 ns     68928790
BM_Towlower_My_High_Unicode          1.85 ns         1.85 ns    392887887
BM_Towlower_Std_High_Unicode         1.93 ns         1.93 ns    367819066
BM_Towlower_V8_High_Unicode         0.254 ns        0.253 ns   2785991311
```
