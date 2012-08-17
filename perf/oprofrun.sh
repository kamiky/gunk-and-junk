#!/bin/sh

#start deamon
sudo opcontrol --no-vmlinux --callgraph=20 --image=$1 --start
#run
$*
#kill deamon
sudo opcontrol --shutdown
#display results
opreport $1 --demangle smart --symbols --exclude-symbols "malloc,_int_malloc,free,_int_free,mmap,mmap64,ft_mem_realloc,ft_mem_alloc,ft_memqrealloc" -xc | less
