.global application

.data
message:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

.align 2
.text
application:
    push   {lr}
    ldr    r0, =message          @ pmsg = &message
    bl     print_asciz           @ print_asciz(pmsg)
    pop    {pc}                  @ return void

print_asciz:
    push   {r4, lr}              @ pmsg_lc
    mov    r4, r0                @ pmsg_lc = pmsg
print:
    ldrb   r0, [r4]              @ letter = *pmsg_lc
    tst    r0, r0                @ zflag = letter == 0 ? 1 : 0
    beq    print_end             @ if zflag == 1 goto done
    bl     convert_char          @ convert_char(letter)
    bl     uart_put_char         @ uart_put_char(letter)
    add    r4, #1                @ ++pmsg_lc
    b      print                 @ continue
print_end:                       @
    pop    {r4, pc}              @ return void

convert_char:
    mov    r1, #'a' - 1          @ range = 'a' - 1
    sub    r1, #'z' + 1          @ range -= 'z' + 1 = -27u
    mov    r2, r0                @ max = letter
    sub    r2, #'z' + 1          @ max -= 'z' + 1
    cmp    r1, r2                @ cflag = range >= max ? 1 : 0
    bcc    convert               @ if cflag == 0 goto convert
    mov    r2, r0                @ max = letter
    sub    r2, #'Z' + 1          @ max -= 'Z' + 1
    cmp    r1, r2                @ cflag = range >= max ? 1 : 0
    bcs    convert_end           @ if cflag == 1 goto convert_end
convert:                         @
    mov    r1, #'a' - 'A'        @ caps_bit = 'a' - 'A'
    eor    r0, r1                @ letter xor_eq caps_bit
convert_end:                     @
    bx     lr                    @ return letter
