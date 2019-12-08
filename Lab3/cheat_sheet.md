# McPAT

https://www.hpl.hp.com/research/mcpat/


```
git clone https://github.com/kingmouf/cmcpat.git my_mcpat

sudo apt install libc6-dev-i386
sudo apt install gcc-7-multilib g++-7-multilib

cd my_mcpat
make
```

```
./mcpat -infile ProcessorDescriptionFiles/Xeon.xml -print_level 1

./mcpat -infile my_cpu.xml -print_level 1 > results.txt
```

## GEM5 to McPAT
```
GEM5toMcPAT.py [options] <gem5 stats file> <gem5 config file (json)> <mcpat template xml file> -o <output xml file>
```
-h, --help	show help message and exit
-q, --quiet	don't print status messages to stdout

## McPAT print_energy

```
print_energy.py [options] <mcpat output file> <gem5 stats file> 
```

# TESTS

```
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/scepbzip_def.xml

./mcpat -infile my_cpu111.xml -print_level 1 > results.txt
```
### SPEC BZIP
```
./mcpat -infile ~/Desktop/specbzip_xml/specbzip0.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_0.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip1.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_1.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip2.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_2.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip3.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_3.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip4.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_4.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip5.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_5.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip6.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_6.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip7.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_7.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip8.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_8.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip9.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_9.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip10.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_10.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip11.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_11.txt
./mcpat -infile ~/Desktop/specbzip_xml/specbzip12.xml -print_level 5 > ~/Desktop/specbzip/RESULTS_12.txt
```

### SPEC MCF
```
./mcpat -infile ~/Desktop/specmcf_xml/specmcf0.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_0.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf1.xml -print_level 5> ~/Desktop/specmcf/RESULTS_1.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf2.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_2.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf3.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_3.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf4.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_4.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf5.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_5.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf6.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_6.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf7.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_7.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf8.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_8.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf9.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_9.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf10.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_10.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf11.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_11.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf12.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_12.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf13.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_13.txt
./mcpat -infile ~/Desktop/specmcf_xml/specmcf14.xml -print_level 5 > ~/Desktop/specmcf/RESULTS_14.txt
```
### SPEC HMMER
```
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer0.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_0.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer1.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_1.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer2.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_2.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer3.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_3.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer4.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_4.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer5.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_5.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer6.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_6.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer7.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_7.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer8.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_8.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer9.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_9.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer10.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_10.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer11.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_11.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer12.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_12.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer13.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_13.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer14.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_14.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer15.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_15.txt
./mcpat -infile ~/Desktop/spechmmer_xml/spechmmer16.xml -print_level 5 > ~/Desktop/spechmmer/RESULTS_16.txt
```

### SPEC SJENG
```
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng0.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_0.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng1.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_1.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng2.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_2.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng3.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_3.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng4.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_4.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng5.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_5.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng6.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_6.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng7.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_7.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng8.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_8.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng9.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_9.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng10.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_10.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng11.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_11.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng12.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_12.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng13.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_13.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng14.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_14.txt
./mcpat -infile ~/Desktop/specsjeng_xml/specsjeng15.xml -print_level 5 > ~/Desktop/specsjeng/RESULTS_15.txt
```

### SPEC LIBM
```
./mcpat -infile ~/Desktop/speclibm_xml/speclibm0.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_0.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm1.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_1.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm2.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_2.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm3.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_3.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm4.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_4.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm5.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_5.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm6.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_6.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm7.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_7.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm8.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_8.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm9.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_9.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm10.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_10.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm11.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_11.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm12.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_12.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm13.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_13.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm14.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_14.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm15.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_15.txt
./mcpat -infile ~/Desktop/speclibm_xml/speclibm16.xml -print_level 5 > ~/Desktop/speclibm/RESULTS_16.txt
```
