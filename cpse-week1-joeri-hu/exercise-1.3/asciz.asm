    .global print_asciz
    .global application

hello:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

application:
    ldr r0, =hello
    bl print_asciz

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
