# LAB 2 REPORT

#### Make things faster
In order to make the commads run sequentially we made a function in fish to execute the commads one after the other.
Then we made a call to that function and waited for the commads to be executed.

## QUESTIONS PART 1

Run benchmarks with default cpu-clock, L1 instruction cache size and associativity , L1 data cache size and associativity,
L2 cache size and associativity and cache line

### [1.1] FINDING SOME PARAMETERS
from _config.ini_ we can find the requested parameters:
* L1 Instruction cache size: 32768 (line 813)
* L1 Instruction cache associativity: 2 (line 793)
* L1 Data cache size: 65535 (line 179)
* L1 Data cache associativity: 2 (line 159)
* L2 cache size: 2097152 (line 1018)
* L2 cache associativity: 8 (ine 998)
* cache line size: 64 (line 15)

### [1.2] RESULTS

Results are presented in _spec_results1_/_Results1.txt_

| Benchmarks	| system.cpu.cpi |	sim_seconds | dcache-miss-rate	| icache-miss-rate	| l2-miss-rate |
| ----------- | -------------- | ------------ | ----------------- | ------------------| ------------ | 
| specbzip	| 1.613367 |	0.161337 |	0.014683	| 0.000074 |	0.281702 | 
| spechmmer	| 1.184534 | 0.118453 |	0.001638	| 0.000205	| 0.082233 | 
| speclibm	| 2.623555 | 0.262355 |	0.060971	| 0.000099	| 0.999927 | 
| specmcf		| 1.091249| 0.109125 |	0.002051	| 0.000037	| 0.724040 | 
| specsjeng	| 10.270810	| 0.513541 | 0.121829	| 0.000020	| 0.999979 | 

<img src="https://user-images.githubusercontent.com/57758089/69497216-2804f500-0ee3-11ea-87c4-16bc7aa14705.png" alt="sim_seconds" width="500" height="300">

<img src="https://user-images.githubusercontent.com/57758089/69497217-289d8b80-0ee3-11ea-9c69-e76e80942de1.png" alt="miss-rate" width="500" height="300">

<img src="https://user-images.githubusercontent.com/57758089/69497218-289d8b80-0ee3-11ea-941f-44a5df382299.png" alt="CPI" width="500" height="300">

We observe that the instruction cache miss-rate is near 0%,  while data miss-rate is <13%. The l2 cache miss-rate though is very high, especially for speclibm specmcf and specsjeng, despite the fact that l2 cache is 2MB 8-way assiciativity. The higher the miss-rate, the higher the CPI(many misses result more acceses to memory, more acceses to memory result more cycles to fetch data). The specsjeng has the highest data cache and l2 cache miss rate and the highest CPI.

### [1.3] RUN BECNCHMARKS WITH _cpu-clock=2GHz_

Results are presented in _spec_results2_/_Results2.txt_

| Benchmarks	| system.cpu.cpi |	sim_seconds | dcache-miss-rate	| icache-miss-rate	| l2-miss-rate |
| ----------- | -------------- | ------------ | ----------------- | ------------------| ------------ | 
| specbzip	| 1.683172	| 0.084159	| 0.014840	| 0.000074	| 0.281708 | 
| spechmmer	| 1.187362	| 0.059368	| 0.001645	| 0.000205	| 0.082246 | 
| speclibm	| 3.493611	| 0.174681	| 0.060971	| 0.000099	| 0.999927 | 
| specmcf		| 1.109538	| 0.055477	| 0.002051	| 0.000037	| 0.724040 | 
| specsjeng	| 10.270810	| 0.513541	| 0.121829	| 0.000020	| 0.999979 | 

We observe that in both executions, system.clk_domain = 1000 (line 289) but system.cpu_clk_domain.clock = 1000 (line 758) for 1GHz and 500 for 2GHz.
For 1 GHz,  system.cpu_clk_domain.clock = 500 means 500 ticks / cpu cycle = 1 GHz
For 2GHz  system.cpu_clk_domain.clock = 1000 means 1000 ticks / cpu cycle = 2 GHz

We also observe that having 2 times better clock, does not make the benchmarks run twice faster, but it is very close to double it. As a result we could say that there is no perfect scaling.

## QUESTIONS PART 2

### [2.1] IMPROVE BENCHMARKS' CPI

#### [2.1.1] IMPROVE _specbzip_ BENCHMARK'S CPI

Simulations are presented in _specbzip_better_CPI_

Best CPI(1.613367--->1.543471) was achived for:
* l1d_size = 128KB
* l1i_size = 64KB
* l2_ size = 4MB
* l1i_assoc = 2
* l1d_assoc = 16
* l2_assoc = 8
* cache_line = 256

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ] = 0.04332306 or 4%

#### [2.1.2] IMPROVE _speccmf_ BENCHMARK'S CPI

Simulations are presented in _speccmf_better_CPI_

Best CPI(1.109538--->1.062561) was achieved for:
* l1d_size = 128KB
* l1i_size = 64KB
* l2_ size = 4MB
* l1i_assoc = 2
* l1d_assoc = 16
* l2_assoc = 8
* cache_line = 512 

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ] = 0.04233924 or 4%

#### [2.1.3] IMPROVE _spechmmer_ BENCHMARK'S CPI

Simulations are presented in _spechmmer_better_CPI_

Best CPI(1.184534--->1.178156) was achieved for:
* l1d_size = 128KB
* l1i_size = 64KB
* l2_ size = 1MB
* l1i_assoc = 2
* l1d_assoc = 8
* l2_assoc = 4
* cache_line = 256

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ] = 0.0053844 or 0.5%

#### [2.1.4] IMPROVE _specsjeng_ BENCHMARK'S CPI 

Simulations are presented in _speccjengp_better_CPI_

Best CPI(10.270810--->2.636428) was achieved for:
* l1d_size = 128KB
* l1i_size = 128KB
* l2_ size = 4MB
* l1i_assoc = 2
* l1d_assoc = 4 
* l2_assoc = 16
* cache_line = 2048

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ] = 0.773308 or 77%

#### [2.1.5] IMPROVE _speclibm_ BENCHMARK'S CPI 

Simulations are presented in _speclibm_better_CPI_

Best CPI(--->) was achieved for:
* l1d_size = 
* l1i_size = 
* l2_ size = 
* l1i_assoc = 
* l1d_assoc = 
* l2_assoc = 
* cache_line = 

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ] =

### [2.2] DESCRIPTION OF CHANGES & GRAPHS 

#### [2.2.1] _specbzip_ BENCHMARK'S CPI

Due to low l1 instruction misses, we increased the L1 data cache to 128KB which was the maximus possible. We tried different associativities for L1 data cache (4,8,16,32) with l1d_assoc = 16 giving the best CPI.  
By increasing cache line to 256 we got slightly better CPI.  
Then we tried different L2 cache size. The highest possible (4MB) gave better results(1.54371) with L2 associativity equals to 8. Different associativity gave slightly higher CPI.
Lastly, further increase to cache line, increased CPI.
Noticeable improvement: l2-miss-rate dropped from 28% to 16%

Bigger cache line(bigger block size transfered to memory) resulted a better CPI. That could be a consequence of the benchmark's data locality.
Higher l1d_assoc(and l2_assoc) means that the data conflict quite frequent and with l1d_assoc=16(l2_assoc=8) we reduce the number of conflicts.


#### [2.2.2] _speccmf_ BENCHMARK'S CPI

Due to low l1 instruction misses, we increased the l1 data cache to 128KB which was the maximus possible. l1i_assoc was just increased to 64KB which was enough(could be 128KB aswell).
We tried different associativities for l1 data cache (2,4,8), with the best CPI at l1d_size = 16
Increasing cache line improved CPI.
L2 cache associativity also did not seem to affect CPI, so we kept it to 8
Lastly we gave the maximum possible l2 cache size of 4MB due to high l2 misses.

Increasing l1d_assoc and cache-line, increased the CPI because the L2 miss-rate was increased due to the fact that we did not exploit locality with the correct way(we did not need so many words from L2 cache).

#### [2.2.3] _spechmmer_ BENCHMARK'S CPI

At first, L1 instruction misses were very low so we kept l1_assoc at 2 but we increased the l1i_size to maximum possible (128KB) for slightly beter results.
We also increased l1d_size to maximum possible (128KB) for better results. The l1d-miss-rate was high so we would benefit from that choice. Regarding l1d_assoc, we had similar results for 4,8,16, but 8 were slightly better. Locality does not get harm for associativity.
By increasing l2 size, CPI was decreasing, with a better result at 1MB. The same CPI was achieved for 4MB too, but lower size is prefered due to lower cost and complexity(see QUESTIONS PART 3).
Lastly, cache line 256 gave quite lower CPI.  
In general, the improvement to the CPI was 1 in every 100 cycles.
We could not take advantage of locality or bigger size of cache, because the miss-errors were fixed and CPI was already very low.

#### [2.2.4] _specsjeng_ BENCHMARK'S CPI 

At first, L1 instruction misses were very low so we kept l1_assoc at 2 but we increased the l1i_size to maximum possible (128KB) for slightly beter results. 
We also increased l1d_size to maximum possible (128KB) for better results, so we did with the l2_size = 4MB
Then we tried different l1d_assoc (2,4,8) but the CPI remained the same. We can assume that collision do not happen often so increasing associativity does not avoid those collisions.
Regarding l2_assoc we tried different values (2,4,8,16) but the CPI remained the same, possible for the above reason.
Lastly we tried many values for cache_lines (32, 64 ,128, 256, 512, 1024, 2048) because by increasing the cache_line the CPI was getting lower and lower. We can assume that bringing more data in every miss we have a better CPI. But the l2 miss-rate remains the same, so we just benefit for L1 cache.

#### [2.2.5] _speclibm_ BENCHMARK'S CPI 

## QUSTIONS PART 3

Cost function

