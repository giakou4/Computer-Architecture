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
python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/spec_results1/speccmf/stats.txt ~/Desktop/Computer-Architecture/lab2/spec_results1/specmf/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/speccmf0.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf1/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf1/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf1.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf2/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf2/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf2.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf3/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf3/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf3.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf4/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf4/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf4.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf5/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf5/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf5.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf6/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf6/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf6.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf7/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf7/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf7.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf8/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf8/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf8.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf9/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf9/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf9.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf10/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf10/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf10.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf11/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf11/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf11.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf12/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf12/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf12.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf13/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf13/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf13.xml

python GEM5ToMcPAT.py ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf14/stats.txt ~/Desktop/Computer-Architecture/lab2/speccmf_improvement/speccmf14/config.json ~/my_mcpat/mcpat/ProcessorDescriptionFiles/inorder_arm.xml -o ~/Desktop/specmf14.xml






```


