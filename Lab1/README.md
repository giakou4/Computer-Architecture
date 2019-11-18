# LAB 1 REPORT

#### _1. starter_se.py_

First we see the types of the CPU which can be atomic, minor or HPI. In our example we used minor (lines 69-79)

Inside the _SimpleSeSystem_ class:

* Cache size is 64 bytes (line 88)

* System voltage is set to 3.3V (line 99)
* System clock is set to 1GHz or 1000000000000 picoseconds (line 100)
* Memory bus is created (line 104)
* CPUs are added to the system. By default each CPU has a private L1 cache and shared L2 cache (lines 111-116)

#### 2. config.ini & config.json

We can verify that:

* Cache size is 64 byte (line 15)
* Clock is 1000MHz = 1GHz (line46) and _p_state_clk_gate_max_=1000000000000 picoseconds(line1139)
* CPU type is minor (line67)
* Voltage is 3.3V (line 1453)

#### 3. CPU Models

###### Minor

Minor is an in-order processor model with a fixed pipeline but configurable data structures and execute behaviour. It is intended to be used to model processors with strict in-order execution behaviour and allows visualisation of an instruction's position in the pipeline through the MinorTrace/minorview.py format/tool. The intention is to provide a framework for micro-architecturally correlating the model with a particular, chosen processor with similar capabilities. 

###### SimpleCPU

The SimpleCPU is a purely functional, in-order model that is suited for cases where a detailed model is not necessary. This can include warm-up periods, client systems that are driving a host, or just testing to make sure a program works.

It has recently been re-written to support the new memory system, and is now broken up into three classes.

###### BaseSimpleCPU

The BaseSimpleCPU serves several purposes:

- Holds architected state, stats common across the SimpleCPU models.
- Defines functions for checking for interrupts, setting up a fetch request, handling pre-execute setup, handling post-execute actions, and advancing the PC to the next instruction. These functions are also common across the SimpleCPU models.
- Implements the [ExecContext](http://gem5.org/Execution_Basics#ExecContext) interface.

The BaseSimpleCPU can not be run on its own. You must use one of the classes that inherits from BaseSimpleCPU, either AtomicSimpleCPU or TimingSimpleCPU.

###### AtomicSimpleCPU

 The AtomicSimpleCPU is the version of SimpleCPU that uses atomic memory accesses. It uses the latency estimates from the atomic accesses to estimate overall cache access time. The AtomicSimpleCPU is derived from BaseSimpleCPU, and implements functions to read and write memory, and also to tick, which defines what happens every CPU cycle. It defines the port that is used to hook up to memory, and connects the CPU to the cache. 

###### TimingSimpleCPU

 The TimingSimpleCPU is the version of SimpleCPU that uses timing memory accesses . It stalls on cache accesses and waits for the memory system to respond prior to proceeding. Like the AtomicSimpleCPU, the TimingSimpleCPU is also derived from BaseSimpleCPU, and implements the same set of functions. It defines the port that is used to hook up to memory, and connects the CPU to the cache. It also defines the necessary functions for handling the response from memory to the accesses sent out.

 Source: [gem5.org](http://gem5.org/SimpleCPU#BaseSimpleCPU)

#### 3a. Run my C programm with different cpu models
myprog.c

###### Run with Minor CPU model:
```
./build/ARM/gem5.opt -d results_minor_cpu configs/example/se.py --cpu-type=MinorCPU --caches -c myprog_arm
```
 According to _results_minor_cpu_, the programm myprog.c (after cross-compiled to myprog_arm) run for 0.000096 seconds at 1GHz clock which is 95628000 ticks.
 
 ###### Run with Timing Simple CPU model
 ```
./build/ARM/gem5.opt -d results_timing_simples_cpu configs/example/se.py --cpu-type=TimingSimpleCPU --caches -c myprog_arm
```
  According to _results_timing_simple_cpu_, the programm myprog.c (after cross-compiled to myprog_arm) run for 0.000180 seconds at 1GHz clock which is 179649000 ticks.

#### 3b. Observe similarities and differencies in [3a]
 We observe difference in the time of execution: Minor CPU model runs 1.875 times faster than the Timing Simple CPU model.
 This could be expected because the Timing Simple CPU model stalls on cache accesses and waits for the memory system to respond and as a result it would take more time to read from memory.

#### 3c. Some more changes

###### Run with Minor CPU model , CPU clock: 2GHz, Memory Type: DDR3 2133MHz 8x8
```
./build/ARM/gem5.opt -d results_minor_cpu2 configs/example/se.py --cpu-type=MinorCPU --mem-type=DDR3_2133_8x8 --caches -c myprog_arm
```
Note that we manually change the clock to 2GHz from the ./my_gem5/configs/common/Options.py line 85.
According to _results_minor_cpu2_, the programm myprog.c run for 0.000091 seconds.

###### Run with Timing Simple CPU model , CPU clock: 2GHz, Memory Type: DDR3 2133MHz 8x8
```
./build/ARM/gem5.opt -d results_timing_simple_cpu2 configs/example/se.py --cpu-type=TimingSimpleCPU --mem-type=DDR3_2133_8x8 --caches -c myprog_arm
```
Note that we manually change the clock to 2GHz from the ./my_gem5/configs/common/Options.py line 85.
According to _results_minor_cpu2_, the programm myprog.c run for 0.000022 seconds.


