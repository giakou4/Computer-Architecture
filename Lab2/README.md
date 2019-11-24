# LAB 2 REPORT

#### Make things faster
In order to make the commads run sequentially we made a function in fish to execute the commads one after the other.
Then we made a call to that function and waited for the commads to be executed.

## Questions Part 1

Run benchmarks with default cpu-clock, L1 instruction cache size and associativity , L1 data cache size and associativity,
L2 cache size and associativity and cache line
Results are presented in _spec_results1_

The commands:

```
./build/ARM/gem5.opt -d spec_results/specbzip configs/example/se.py --cpu-type=MinorCPU --caches --l2cache -c spec_cpu2006/401.bzip2/src/specbzip -o "spec_cpu2006/401.bzip2/data/input.program 10" -I 100000000

./build/ARM/gem5.opt -d spec_results/specmcf configs/example/se.py --cpu-type=MinorCPU --caches --l2cache -c spec_cpu2006/429.mcf/src/specmcf -o "spec_cpu2006/429.mcf/data/inp.in" -I 100000000

./build/ARM/gem5.opt -d spec_results/spechmmer configs/example/se.py --cpu-type=MinorCPU --caches --l2cache -c spec_cpu2006/456.hmmer/src/spechmmer -o "--fixed 0 --mean 325 --num 45000 --sd 200 --seed 0 spec_cpu2006/456.hmmer/data/bombesin.hmm" -I 100000000

./build/ARM/gem5.opt -d spec_results/specsjeng configs/example/se.py --cpu-type=MinorCPU --caches --l2cache -c  spec_cpu2006/458.sjeng/src/specsjeng -o "spec_cpu2006/458.sjeng/data/test.txt" -I 100000000

./build/ARM/gem5.opt -d spec_results/speclibm configs/example/se.py --cpu-type=MinorCPU --caches --l2cache -c spec_cpu2006/470.lbm/src/speclibm -o "20 spec_cpu2006/470.lbm/data/lbm.in 0 1 spec_cpu2006/470.lbm/data/100_100_130_cf_a.of" -I 100000000
```

### [1.1] Finding some parameters
from _config.ini_ we can find the requested parameters:

* L1 Instruction cache size: 32768 (line 813)
* L1 Instruction cache associativity: 2 (line 793)
* L1 Data cache size: 65535 (line 179)
* L1 Data cache associativity: 2 (line 159)
* L2 cache size: 2097152 (line 1018)
* L2 cache associativity: 8 (ine 998)
*cache line size: 64 (line 15)

### [1.2] Results

Results are presented in _spec_results1_/_Results1.txt_

| Benchmarks	| system.cpu.cpi |	sim_seconds | dcache-miss-rate	| icache-miss-rate	| l2-miss-rate |
| ----------- | -------------- | ------------ | ----------------- | ------------------| ------------ | 
| specbzip	| 1.613367 |	0.161337 |	0.014683	| 0.000074 |	0.281702 | 
| spechmmer	| 1.184534 | 0.118453 |	0.001638	| 0.000205	| 0.082233 | 
| speclibm	| 2.623555 | 0.262355 |	0.060971	| 0.000099	| 0.999927 | 
| specmcf		| 1.091249| 0.109125 |	0.002051	| 0.000037	| 0.724040 | 
| specsjeng	| 10.270810	| 0.513541 | 0.121829	| 0.000020	| 0.999979 | 

![sim_seconds1](https://user-images.githubusercontent.com/57758089/69497216-2804f500-0ee3-11ea-87c4-16bc7aa14705.png)
![miss-rate1](https://user-images.githubusercontent.com/57758089/69497217-289d8b80-0ee3-11ea-9c69-e76e80942de1.png)
![cpi1](https://user-images.githubusercontent.com/57758089/69497218-289d8b80-0ee3-11ea-941f-44a5df382299.png)

We observe that the instruction cache miss-rate is near 0%,  while data miss-rate is <13%. The l2 cache miss-rate though is very high, especially for speclibm specmcf and specsjeng, despite the fact that l2 cache is 2MB 8-way assiciativity. The higher the miss-rate, the higher the CPI(many misses results more acceses to memory, more acceses to memory results more cycles to fetch data). The specsjeng has the highest data cache and l2 cache miss rate and the highest CPI.

### [1.3] Run benchmarks with cpu-clock=2GHz

The commands:

```
./build/ARM/gem5.opt -d spec_results/specbzip configs/example/se.py --cpu-type=MinorCPU --cpu-clock=2GHz --caches --l2cache -c spec_cpu2006/401.bzip2/src/specbzip -o "spec_cpu2006/401.bzip2/data/input.program 10" -I 100000000

./build/ARM/gem5.opt -d spec_results/specmcf configs/example/se.py --cpu-type=MinorCPU --cpu-clock=2GHz --caches --l2cache -c spec_cpu2006/429.mcf/src/specmcf -o "spec_cpu2006/429.mcf/data/inp.in" -I 100000000

./build/ARM/gem5.opt -d spec_results/spechmmer configs/example/se.py --cpu-type=MinorCPU --cpu-clock=2GHz --caches --l2cache -c spec_cpu2006/456.hmmer/src/spechmmer -o "--fixed 0 --mean 325 --num 45000 --sd 200 --seed 0 spec_cpu2006/456.hmmer/data/bombesin.hmm" -I 100000000

./build/ARM/gem5.opt -d spec_results/specsjeng configs/example/se.py --cpu-type=MinorCPU --cpu-clock=2GHz --caches --l2cache -c  spec_cpu2006/458.sjeng/src/specsjeng -o "spec_cpu2006/458.sjeng/data/test.txt" -I 100000000

./build/ARM/gem5.opt -d spec_results/speclibm configs/example/se.py --cpu-type=MinorCPU --cpu-clock=2GHz --caches --l2cache -c spec_cpu2006/470.lbm/src/speclibm -o "20 spec_cpu2006/470.lbm/data/lbm.in 0 1 spec_cpu2006/470.lbm/data/100_100_130_cf_a.of" -I 100000000
```

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

We also observe that having 2 times better clock, doesnt make the benchmarks run twice faster, but it is very close to double it. As a result there is no perfect scaling.

## Questions Part 2

### [2.1]

#### [2.1.1] Improve specbzip benchmark's CPI

Best CPI(1.613367--->1.543471) was achived for:
```
./build/ARM/gem5.opt -d spec_results/specbzip9 configs/example/se.py --cpu-type=MinorCPU --caches --l2cache --l1d_size=128kB --l1i_size=64kB --l2_size=4MB --l1i_assoc=2 --l1d_assoc=16 --l2_assoc=8 --cacheline_size=256 --cpu-clock=1GHz -c spec_cpu2006/401.bzip2/src/specbzip -o "spec_cpu2006/401.bzip2/data/input.program 10" -I 100000000
```
Due to low l1 instruction misses, we increased the l1 data cache to 128KB which was the maximus possible. We tried different associativities for l1 data cache as follownging:  
* l1d_assoc = 4 ---> CPI = 1.56
* l1d_assoc = 8 ---> CPI = 1.55
* l1d_assoc = 16 ---> CPI = 1.54
* l1d_assoc = 32 ---> CPI = 1.55

As a result l1d_assoc = 16 gave the best result.  
By increasing cache line to 256 we got slightly better CPI.  
Then we tried different l2 cache size. The highest possible (4MB) gave better results(1.54371) with l2 associativity equals to 8. Different associativity gave slightly higher CPI.
Lastly, further increase to cache line, increases CPI.
Improvement: l2-miss-rate dropped from 28% to 16%

#### [2.1.2] Improve speccmf benchmark's CPI
Best CPI(1.109538--->1.062561) was achieved for 
```
./build/ARM/gem5.opt -d spec_results/specmcf11 configs/example/se.py --cpu-type=MinorCPU --caches --l2cache --l1d_size=128kB --l1i_size=64kB --l2_size=4MB --l1i_assoc=2 --l1d_assoc=16 --l2_assoc=8 --cacheline_size=512 --cpu-clock=1GHz -c spec_cpu2006/429.mcf/src/specmcf -o "spec_cpu2006/429.mcf/data/inp.in" -I 100000000
```
Due to low l1 instruction misses, we increased the l1 data cache to 128KB which was the maximus possible. We tried different associativities for l1 data cache as following:
* l1d_assoc = 2 ---> CPI = 1.06
* l1d_assoc = 4 ---> CPI = 1.10
* l1d_assoc = 8 ---> CPI = 1.10
As a result l1d_assoc = 2 gave the best result.  
Note we didnt change l1 instruction cache size and associativity because the misses from instruction l1 were very low.
Increasing cache line does not affect CPI(=ct).
L2 cache associativity didnt seem to affect CPI, so we kept it to 8
Lastly we gave the maximum possible l2 cache size of 4MB due to high l2 misses.
(We also observe with l1d_assoc = 16 and cache line=512 we achieve the same CPI, but it would be more expensive (see questions part 3))

#### [2.1.3] Improve spechmmer benchmark's CPI

#### [2.1.4] Improve specsjeng benchmark's CPI 

#### [2.1.5] Improve speclibm benchmark's CPI 

### [2.2]

## Questions Part 3

Cost function

