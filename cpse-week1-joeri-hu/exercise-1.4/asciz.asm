.global application

hello:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

.align 2

application:
    push   {lr}
    ldr    r0, =hello
    bl     print_asciz
    pop    {pc}

print_asciz:
    push   {r4, lr}
    mov    r4, r0
loop:
    ldrb   r0, [r4]
    cmp    r0, #0
    beq    done
    bl     convert_char
    bl     uart_put_char
    add    r4, #1
    b      loop
done:
    pop    {r4, pc}

convert_char:
    push   {r4, lr}
    mov    r4, r0
@ upper_check:
    mov    r0, r4
    mov    r1, #'A' - 1
    mov    r2, #'Z' + 1
    bl     check_range
    bcc    convert
@ lower_check:
    mov    r0, r4
    mov    r1, #'a' - 1
    mov    r2, #'z' + 1
    bl     check_range
    bcs    end
convert:
    mov    r0, #'a' - 'A'
    eor    r4, r0
end:
    mov    r0, r4
    pop    {r4, pc}

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
    sub    r1, r2    @ min -= max;
    sub    r0, r2    @ num -= max;
    cmp    r1, r0    @ CF = min >= num;
    mov    pc, lr
