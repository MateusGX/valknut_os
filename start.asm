bits 32
global _start
global _nop
extern main
extern init

section .text
      ; GRUB
      align 4
      dd 0x1BADB002            ; MAGIC
      dd 0x00                  ; FLAGS
      dd - (0x1BADB002 + 0x00) ; CHECKSUM

_start: 
cli
mov esp, stack
call init
call main
hlt

_nop:
nop

section .bss
resb 8192
stack: