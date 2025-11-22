# Benchmarks against glibc

### Classification (~46KB)

```
-------------------------------------------------------------------------
Benchmark                               Time             CPU   Iterations
-------------------------------------------------------------------------
BM_Iswdigit_My_ASCII_Digit          0.157 ns        0.157 ns   4469363458
BM_Iswdigit_Std_ASCII_Digit          3.13 ns         3.13 ns    216820115
BM_Iswdigit_My_ASCII_Letter         0.156 ns        0.156 ns   4285118986
BM_Iswdigit_Std_ASCII_Letter         2.96 ns         2.96 ns    236837813
BM_Iswdigit_My_Unicode              0.157 ns        0.157 ns   4494084908
BM_Iswdigit_Std_Unicode              3.55 ns         3.55 ns    194718481
BM_Iswdigit_My_Bulk_Mixed            9.38 ns         9.37 ns     74838284 items_per_second=1.60006G/s
BM_Iswdigit_Std_Bulk_Mixed           52.4 ns         52.4 ns     13332086 items_per_second=286.032M/s
BM_Iswalpha_My_ASCII_Letter         0.157 ns        0.157 ns   4464587615
BM_Iswalpha_Std_ASCII_Letter         2.96 ns         2.96 ns    227530707
BM_Iswalpha_My_ASCII_Digit          0.157 ns        0.157 ns   4485615301
BM_Iswalpha_Std_ASCII_Digit          3.12 ns         3.12 ns    224694956
BM_Iswalpha_My_Latin_Extended       0.157 ns        0.156 ns   4481559554
BM_Iswalpha_Std_Latin_Extended       3.75 ns         3.75 ns    186457370
BM_Iswalpha_My_Greek                0.157 ns        0.157 ns   4473185356
BM_Iswalpha_Std_Greek                3.75 ns         3.75 ns    187296475
BM_Iswalpha_My_CJK                  0.157 ns        0.157 ns   4474181188
BM_Iswalpha_Std_CJK                  3.75 ns         3.75 ns    187300750
BM_Iswalpha_My_Bulk_Mixed            15.5 ns         15.5 ns     44757833 items_per_second=1.54581G/s
BM_Iswalpha_Std_Bulk_Mixed           83.3 ns         83.3 ns      8416219 items_per_second=288.214M/s
BM_Iswgraph_My_ASCII_Letter         0.156 ns        0.156 ns   4494637503
BM_Iswgraph_Std_ASCII_Letter         3.27 ns         3.27 ns    214271763
BM_Iswgraph_My_ASCII_Digit          0.156 ns        0.156 ns   4493157230
BM_Iswgraph_Std_ASCII_Digit          3.27 ns         3.27 ns    214031445
BM_Iswgraph_My_ASCII_Space          0.156 ns        0.156 ns   4473248272
BM_Iswgraph_Std_ASCII_Space          3.42 ns         3.42 ns    204363433
BM_Iswgraph_My_Latin_Extended       0.155 ns        0.155 ns   4453162521
BM_Iswgraph_Std_Latin_Extended       3.59 ns         3.59 ns    189976596
BM_Iswgraph_My_Bulk_Mixed            25.4 ns         25.4 ns     27348857 items_per_second=787.054M/s
BM_Iswgraph_Std_Bulk_Mixed           75.6 ns         75.6 ns      9232290 items_per_second=264.456M/s
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
BM_Towlower_My_ASCII_Upper          0.156 ns        0.156 ns   4484494310
BM_Towlower_Std_ASCII_Upper          3.74 ns         3.74 ns    174266861
BM_Towlower_My_ASCII_Lower          0.156 ns        0.156 ns   4506145855
BM_Towlower_Std_ASCII_Lower          3.62 ns         3.62 ns    195182439
BM_Towlower_My_Latin_Extended        2.20 ns         2.20 ns    317539207
BM_Towlower_Std_Latin_Extended       3.58 ns         3.58 ns    195752910
BM_Towlower_My_Greek                 2.21 ns         2.21 ns    315771249
BM_Towlower_Std_Greek                3.59 ns         3.59 ns    195431611
BM_Towlower_My_No_Case               2.18 ns         2.18 ns    322218532
BM_Towlower_Std_No_Case              3.13 ns         3.13 ns    224865993
BM_Towlower_My_Bulk_ASCII            49.7 ns         49.7 ns     14112266 items_per_second=966.121M/s
BM_Towlower_Std_Bulk_ASCII            182 ns          182 ns      3845184 items_per_second=264.187M/s
BM_Towlower_My_Bulk_Unicode          50.6 ns         50.5 ns     13785060 items_per_second=494.607M/s
BM_Towlower_Std_Bulk_Unicode          103 ns          103 ns      6847900 items_per_second=241.654M/s
BM_Towlower_My_Random_ASCII          3.44 ns         3.44 ns    204841799
BM_Towlower_Std_Random_ASCII         3.75 ns         3.75 ns    187105518
BM_Towlower_My_High_Unicode          2.17 ns         2.17 ns    322264057
BM_Towlower_Std_High_Unicode         2.97 ns         2.96 ns    236771564
```
