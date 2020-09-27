/* ====================================================================== */
/* Entry Point								  */

ENTRY(Reset_Handler)

/* ====================================================================== */
/* Specify the memory areas						  */

MEMORY
{
  m_interrupts		(RX) : ORIGIN = 0x00000000, LENGTH = 0x00000400
  m_flash_config	(RX) : ORIGIN = 0x00000400, LENGTH = 0x00000010
  m_text_rodata		(RX) : ORIGIN = 0x00000410, LENGTH = 0x000FFBF0
  m_data_bss		(RW) : ORIGIN = 0x1FFF0000, LENGTH = 0x00010000
  m_heap_stack		(RW) : ORIGIN = 0x20000000, LENGTH = 0x00030000
}

/* ====================================================================== */
/* Define output sections						  */

SECTIONS
{
  .interrupts :
  {
    . = ALIGN(4);
    __vector_start__ = .;
    KEEP(*(.isr_vector))
    __vector_end__ = .;
  } > m_interrupts

  .flash_config :
  {
    . = ALIGN(4);
    __flashconfig_start__ = .;
    KEEP(*(.FlashConfig))
    __flashconfig_end__ = .;
  } > m_flash_config

  .text :
  {
    . = ALIGN(4);
    __text_start__ = .;
    *(.text)
    *(.text*)
    __text_end__ = .;
  } > m_text_rodata

  .rodata :
  {
    . = ALIGN(4);
    __rodata_start__ = .;
    *(.rodata)
    *(.rodata*)
    __rodata_end__ = .;
  } > m_text_rodata
  __etext = .;
   
  .data : AT(__etext)
  {
    . = ALIGN(4);
    __data_start__ = .;
    *(.data)
    *(.data*)
    __data_end__ = .;
  } > m_data_bss

  .bss :
  {
    . = ALIGN(4);
    __START_BSS = .;
    __bss_start__ = .;
    *(.bss)
    *(.bss*)
    __bss_end__ = .;
    __END_BSS = .;
  } > m_data_bss

  HEAP_SIZE = 0x18000;
  .heap :
  {
    . = ALIGN(8);
    __end__ = .;
    __heap_start__ = .;
    __HeapBase = .;
    . += HEAP_SIZE;
    __HeapLimit = .;
    __heap_limit = .;
    __heap_end__ = .;
  } > m_heap_stack

  STACK_SIZE = 0x18000;
  .stack :
  {
    . = ALIGN(8);
    __stack_start__ = .;
    . += STACK_SIZE;
    __stack_end__ = .;
  } > m_heap_stack

  __StackTop = __stack_end__;
  __StackLimit = __StackTop - STACK_SIZE;
}

/* ====================================================================== */
