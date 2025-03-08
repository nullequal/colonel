ENTRY(_start)
SECTIONS
{
    phys = 2M;
    .text phys : AT(phys)
    {
        text = .;
        *(.multiboot)
        *(.text)
        . = ALIGN(4K);
    }
    .rodata : AT(phys + (rodata - text))
    {
        rodata = .;
        *(.rodata)
        . = ALIGN(4K);
    }
    .data : AT(phys + (data - text))
    {
        data = .;
        *(.data)
        . = ALIGN(4K);
    }
    .bss : AT(phys + (bss - text))
    {
        bss = .;
        *(COMMON)
        *(.bss)
        . = ALIGN(4K);
    }
}