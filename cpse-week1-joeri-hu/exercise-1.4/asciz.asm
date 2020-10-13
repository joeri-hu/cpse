.global application

message:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

.align 2
application:
    push   {lr}
    ldr    r0, =hello            @ pmsg = &message
    bl     print_asciz           @ print_asciz(pmsg)
    pop    {pc}                  @ return void

print_asciz:
    push   {r4, lr}              @ pmsg_lc
    mov    r4, r0                @ pmsg_lc = pmsg
loop:
    ldrb   r0, [r4]              @ letter = *pmsg_lc
    tst    r0, r0                @ zflag = letter == 0 ? 1 : 0
    beq    done                  @ if zflag == 1 goto done
    bl     convert_char          @ convert_char(letter)
    bl     uart_put_char         @ uart_put_char(letter)
    add    r4, #1                @ ++pmsg_lc
    b      loop                  @ continue
done:                            @
    pop    {r4, pc}              @ return void

convert_char:
    push   {r4, lr}              @ letter_lc
    mov    r4, r0                @ letter_lc = letter
@upper_check:                    @
    mov    r1, #'A' - 1          @ min = 'A' - 1
    mov    r2, #'Z' + 1          @ max = 'Z' + 1
    bl     check_range           @ check_range(letter, min, max)
    bcc    convert               @ if cflag == 0 goto convert
@lower_check:                    @
    mov    r0, r4                @ letter = letter_lc
    mov    r1, #'a' - 1          @ min = 'a' - 1
    mov    r2, #'z' + 1          @ max = 'z' + 1
    bl     check_range           @ check_range(letter, min, max)
    bcs    end                   @ if cflag == 1 goto end
convert:                         @
    mov    r0, #'a' - 'A'        @ caps_bit = 'a' - 'A'
    eor    r4, r0                @ letter_lc xor_eq caps_bit
end:                             @
    mov    r0, r4                @ letter = letter_lc
    pop    {r4, pc}              @ return letter

@ check_range
@
@ description
@   when out of range, carry flag is set:
@
@   uint num, min, max;
@   CF = min - max >= num - max;
@   // CF = num > low and num < max;
@
@ parameters
@   r0 .... number to check
@   r1 .... minimum
@   r2 .... maximum
@
check_range:
    sub    r1, r2                @ min -= max
    sub    r0, r2                @ num -= max
    cmp    r1, r0                @ cflag = min >= num ? 1 : 0
    bx     lr                    @ return cflag
