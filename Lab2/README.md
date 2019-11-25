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


| Benchmarks	| l1i_size |	l1i_assoc | l1d_size	|l1d_assoc	| l2_size | l2_assoc | cache-line  | CPI    | improvement | 
| ----------- | -------- | ---------- | --------- | ----------| ------- | -------- | ----------  |------- | ----------- | 
| specbzip	  | 64KB   	 | 	 2        | 128KB     | 16      	| 4MB     | 8        |     256     |  1.613367 < 1.543471 |   4%  |
| specmcf     | 64KB   	 | 	 2        | 128KB    	| 16        | 4MB     | 8        |     512     |     1.109538 < 1.062561|    4% |
| spechmmer  	| 64KB   	 | 	 2        | 128KB    	| 8        	| 1MB     | 4        |     256     | 1.184534 < 1.178156  |    0.5%  |
| specsjeng   | 128KB  	 | 	 2        | 128KB    	| 4        	| 4MB     | 16       |     2048    | 10.270810 < 2.636428 |   77%  |
| specslibm	  | 0KB   	 | 	 0        | 0KB      	| 0        	| 0MB     | 0        |     0       |    3.493611 < 0   |  0%    |

Improvement = [ CPI(old) - CPI(new) ] / [ CPI(old) ]

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

We can define the circuit cost function via the number of the transistors. We know that cache consists of 6 transistors / bit. Also, for n-way associative, we need a mux with n-entries. The cost for 4-entries mux is 24 transistors source: [wikipedia.org](https://en.wikipedia.org/wiki/Transistor_count)

cost_function = A1*l1i_size + A2*l1i_assoc + B1*l1d_size + B2*l1d_assoc + C1*l2_size + C2*l2_assoc + D*cache_line

where

A1 = B1 = C1 = 6 transistors / bit 
A2, B2, C2 depends on the associativity(for direct mapped equals 0 , for 2,4-way equals 24, for 4+ equals no_of_muxs*24)
D is the cost of the wire for the cache line 

Transistors' cost has changed over the years.
In 1968 the average cost was 1, in 2002, the average cost was 0.00000026 source:[singularity.com](singularity.com)

Based on this function, the associativity does not affect the circuit complexity, due to the fact that the MUXs' number of transistors does not increase much. But, the higher the bits of cache, the more complex the circuit. Note that in cache we use from many KB to some MB.

The cost from the other hand can be defined with a similar function but with higher gravity to L1 cache's cost because L1 must be faster and smaller than the L2.
Regarding the speed, as mentioned before, L1(data and instruction) is faster than L2.

Based on the cost of the circuit, in order to achieve the best CPI with the lower cost we make the following choices:


| Benchmarks	| l1i_size |	l1i_assoc | l1d_size	|l1d_assoc	| l2_size | l2_assoc | cache-line  | improvement |
| ----------- | -------- | ---------- | --------- | ----------| ------- | -------- | ----------  |------------ | 
| specbzip	  | 32KB   	 | 	 2        | 64      	| 4        	| 2MB     | 8        |     64      | 4% --->0%   |
| specmcf     | 32KB   	 | 	 2        | 64      	| 4        	| 2MB     | 8        |     64      | 4% --->0%   |
| spechmmer  	| 32KB   	 | 	 2        | 64      	| 4        	| 2MB     | 8        |     64      | 4% --->0%   |
| specsjeng   | 128KB  	 | 	 2        | 128      	| 4        	| 1MB     | 16       |     256     |  77% --->63% |
| specslibm	  | 32KB   	 | 	 2        | 64      	| 4        	| 2MB     | 8        |     64      | 4% --->0%   |

We do not present any calculations for the choices because the initial size of L2 was 2MB and the best was 4MB. The cost is already very high so we prefer the default. Despite that, the improvement for the first 3 is very low, so we had better do nothing.
For the 4th benchmark specsjeng, by decreasing the L2 cache size to 1MB we benefit a lot regarding the cost. We choose this option with no calculations too.

#### Important Note

All simulations are held in the relative folders _<benchmarks_name>_better_CPI_.

## CONCLUSION

Running the benchmarks took a very long time, despite the fact that the simulated time was under 1 minute, actually around 10 seconds.
The lab was not hard to be implemented, but the executions took much time.

In order to have the best outcome, we assumed that the principle of superimposition can be applied. That means that we kept all thing to default and change l1d_size and l1d_assoc, then we changed l1i_size and l1i_assoc, then l2_size and l2_assoc and finally the cache-line (usually try 3 different values and some combinations among them). But most of the times, the L1 data and instruction size was set to maximum (128KB), l1i_assoc was not changed and only tried different l1d_assoc. Also we increased the l2_size to maximum and tried different associativities, because we can reduce conficts by increasing associativity. That means that we can balance lower L2 cache with higher associativity. Combining the results we had a very improved CPI. Changing some of the parameters furhter, resulted an even better CPI.

It should be mentioned that we could try all possible combinations among those 7 parameters with a bash scirpt with 7 loops (actually its much less since most of the parameters can be set at the beginning) and choose the best CPI. All we had to do was wait for the script to be completed.

We can learn how to fix the CPU's cache to imporve better in some benchmarks, depending on what we need our CPU to be for.

We also observe how having the "best" possible cache, and by that we mean the maximum size, a high associativity, does not guarantee the best result.


