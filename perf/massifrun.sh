#!/bin/sh

valgrind --tool=massif --depth=15 --alloc-fn='operator new[](unsigned int)' --alloc-fn='operator new[](unsigned int, TLeave)' --alloc-fn='operator new(unsigned int)' --alloc-fn='operator new(unsigned int, TLeave)' --alloc-fn='operator new(unsigned long, TLeave)' --alloc-fn='operator new[](unsigned long, TLeave)'  --alloc-fn='ft_mem_qrealloc'  --alloc-fn='ft_mem_realloc'  --alloc-fn='ft_mem_alloc --alloc-fn='mmap' --alloc-fn='mmap64' --alloc-fn='shmat' --alloc-fn='_int_malloc' --alloc-fn='brk' --alloc-fn='sbrk' --pages-as-heap=no --threshold=0.4 --time-unit=ms $*
