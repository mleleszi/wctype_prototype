# Benchmarks against glibc

### Classification (~46KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Iswdigit_My_ASCII_Digit          0.249 ns        0.249 ns   2809168812
BM_Iswdigit_Std_ASCII_Digit         0.733 ns        0.733 ns    956253375
BM_Iswdigit_My_ASCII_Letter         0.243 ns        0.243 ns   2859751581
BM_Iswdigit_Std_ASCII_Letter        0.752 ns        0.752 ns    990698936
BM_Iswdigit_My_Unicode              0.245 ns        0.245 ns   2842806214
BM_Iswdigit_Std_Unicode              2.61 ns         2.61 ns    273468486
BM_Iswdigit_My_Bulk_Mixed            6.60 ns         6.60 ns    109274568 items_per_second=2.27228G/s
BM_Iswdigit_Std_Bulk_Mixed           32.4 ns         32.4 ns     21252053 items_per_second=463.101M/s
BM_Iswalpha_My_ASCII_Letter         0.232 ns        0.232 ns   2835621187
BM_Iswalpha_Std_ASCII_Letter        0.577 ns        0.577 ns   1223897565
BM_Iswalpha_V8_ASCII_Letter          5.22 ns         5.22 ns    132382727
BM_Iswalpha_My_ASCII_Digit          0.229 ns        0.229 ns   3043067777
BM_Iswalpha_Std_ASCII_Digit         0.573 ns        0.573 ns   1223104414
BM_Iswalpha_My_Latin_Extended       0.232 ns        0.232 ns   3062700220
BM_Iswalpha_Std_Latin_Extended       2.37 ns         2.37 ns    295131605
BM_Iswalpha_V8_Latin_Extended        6.93 ns         6.93 ns    101175682
BM_Iswalpha_My_Greek                0.230 ns        0.230 ns   3064126302
BM_Iswalpha_Std_Greek                2.35 ns         2.35 ns    300110178
BM_Iswalpha_V8_Greek                 5.19 ns         5.19 ns    135104053
BM_Iswalpha_My_CJK                  0.229 ns        0.229 ns   3038101297
BM_Iswalpha_Std_CJK                  2.36 ns         2.36 ns    293151133
BM_Iswalpha_V8_CJK                   1.88 ns         1.88 ns    372989759
BM_Iswalpha_My_Bulk_Mixed            11.3 ns         11.3 ns     62483946 items_per_second=2.12911G/s
BM_Iswalpha_Std_Bulk_Mixed           35.4 ns         35.4 ns     19879748 items_per_second=677.539M/s
BM_Iswalpha_V8_Bulk_Mixed             154 ns          154 ns      4573651 items_per_second=156.343M/s
BM_Iswgraph_My_ASCII_Letter         0.229 ns        0.229 ns   3049243492
BM_Iswgraph_Std_ASCII_Letter        0.576 ns        0.576 ns   1210278843
BM_Iswgraph_My_ASCII_Digit          0.231 ns        0.231 ns   3061928939
BM_Iswgraph_Std_ASCII_Digit         0.573 ns        0.573 ns   1224874842
BM_Iswgraph_My_ASCII_Space          0.229 ns        0.229 ns   3012588281
BM_Iswgraph_Std_ASCII_Space         0.577 ns        0.577 ns   1223292211
BM_Iswgraph_My_Latin_Extended       0.232 ns        0.232 ns   3045482400
BM_Iswgraph_Std_Latin_Extended       2.37 ns         2.37 ns    299271550
BM_Iswgraph_My_Bulk_Mixed            21.1 ns         21.1 ns     33833398 items_per_second=946.55M/s
BM_Iswgraph_Std_Bulk_Mixed           35.3 ns         35.3 ns     19923898 items_per_second=566.828M/s
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
