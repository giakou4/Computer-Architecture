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


```
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/specbzip/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specbzip.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip1/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip1/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip1.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip2/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip2/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip2.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip3/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip3/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip3.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip4/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip4/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip4.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip5/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip5/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip5.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip6/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip6/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip6.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip7/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip7/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip7.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip8/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip8/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip8.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip9/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip9/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip9.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip10/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip10/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip10.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip11/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip11/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip11.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip12/stats.txt ~/Desktop/Computer-Architecture/lab2/specbzip_improvement/specbzip12/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/spevbzip12.xml





```


