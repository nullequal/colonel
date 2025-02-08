.global isr0
isr0:                         
  push $0                 
  push $0                
  jmp exception_handler_wrap         
.global isr1
isr1:                         
  push $0                 
  push $1                
  jmp exception_handler_wrap         
.global isr2
isr2:                         
  push $0                 
  push $2                
  jmp exception_handler_wrap         
.global isr3
isr3:                         
  push $0                 
  push $3                
  jmp exception_handler_wrap         
.global isr4
isr4:                         
  push $0                 
  push $4                
  jmp exception_handler_wrap         
.global isr5
isr5:                         
  push $0                 
  push $5                
  jmp exception_handler_wrap         
.global isr6
isr6:                         
  push $0                 
  push $6                
  jmp exception_handler_wrap         
.global isr7
isr7:                         
  push $0                 
  push $7                
  jmp exception_handler_wrap         
.global isr8
isr8:                         
  push $8                
  jmp exception_handler_wrap   
.global isr9
isr9:                         
  push $0                 
  push $9                
  jmp exception_handler_wrap         
.global isr10
isr10:                         
  push $10                
  jmp exception_handler_wrap   
.global isr11
isr11:                         
  push $11               
  jmp exception_handler_wrap   
.global isr12
isr12:                         
  push $12                
  jmp exception_handler_wrap   
.global isr13
isr13:                         
  push $13                
  jmp exception_handler_wrap   
.global isr14
isr14:                         
  push $14                
  jmp exception_handler_wrap   
.global isr15
isr15:                         
  push $0                 
  push $15                
  jmp exception_handler_wrap         
.global isr16
isr16:                         
  push $0                 
  push $16                
  jmp exception_handler_wrap         
.global isr17
isr17:                         
  push $17               
  jmp exception_handler_wrap 
.global isr18
isr18:                         
  push $0                 
  push $18                
  jmp exception_handler_wrap         
.global isr19
isr19:                         
  push $0                 
  push $19                
  jmp exception_handler_wrap         
.global isr20
isr20:                         
  push $0                 
  push $20                
  jmp exception_handler_wrap         
.global isr21
isr21:                         
  push $21                
  jmp exception_handler_wrap 
.global isr22
isr22:                         
  push $0                 
  push $22                
  jmp exception_handler_wrap         
.global isr23
isr23:                         
  push $0                 
  push $23                
  jmp exception_handler_wrap         
.global isr24
isr24:                         
  push $0                 
  push $24                
  jmp exception_handler_wrap         
.global isr25
isr25:                         
  push $0                 
  push $25                
  jmp exception_handler_wrap         
.global isr26
isr26:                         
  push $0                 
  push $26                
  jmp exception_handler_wrap         
.global isr27
isr27:                         
  push $0                 
  push $27                
  jmp exception_handler_wrap         
.global isr28
isr28:                         
  push $0                 
  push $28                
  jmp exception_handler_wrap         
.global isr29
isr29:                         
  push $0                 
  push $29                
  jmp exception_handler_wrap         
.global isr30
isr30:                         
  push $0                 
  push $30                
  jmp exception_handler_wrap         
.global isr31
isr31:                         
  push $0                 
  push $31                
  jmp exception_handler_wrap         
 
.extern exception_handler

exception_handler_wrap: 
    pusha                    

    movw %ds,%ax             
    pushl %eax               

    movw $0x10,%ax 
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs

    call exception_handler

    popl %ebx      
    movw %bx,%ds
    movw %bx,%es
    movw %bx,%fs
    movw %bx,%gs

    popa                   
    addl $8,%esp
    iret           
