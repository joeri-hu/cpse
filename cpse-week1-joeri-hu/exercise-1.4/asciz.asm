    .global application

hello:
    .asciz "Hello world, Zhe ANSWER is 42! @[]`{}~\n"

application:
    push {lr}
    ldr r0, =hello
    bl print_asciz
    pop {pc}

print_asciz:
    push {r5, lr}
    mov r5, r0
loop:
    ldrb r0, [r5]
    add r0, r0, #0
    beq done
    bl convert_char
    bl uart_put_char
    add r5, r5, #1
    b loop
done:
    pop {r5, pc}

convert_char:
    .syntax unified
    push {r1-r2, lr}
upper_check:
    mov r2, r0
    mov r0, #'A' - 1
    mov r1, #'Z' + 1
    bl check_range
    bne convert
lower_check:
    mov r0, #'a' - 1
    mov r1, #'z' + 1
    bl check_range
    beq exit
convert:
    eor r2, r2, #'a' - 'A'
exit:
    mov r0, r2
    pop {r1-r2, pc}

@ parameters
@   r0 .... lower bound
@   r1 .... upper bound
@   r2 .... value to check
@
@ returns
@   when out of range, Z flag is set
check_range:
    push {r0-r2, lr}
    subs r2, r2, r1
    subs r0, r0, r1
    cmp r0, r2
    sbcs r1, r1, r1
    pop {r0-r2, pc}
