.global decoder
.global read_asm

.equ buff_size, 100              @ #define buff_size 100

.bss
buffer:
    .space buff_size

.data
cursor:
    .word message

.text
.align 2
decoder:
    push   {lr}
    ldr    r0, =read             @ pread = &read_ext
    ldr    r1, =write            @ pwrite = &write_ext
    bl     decompress            @ decompress(pread, pwrite)
    ldr    r0, =message          @ pmsg = &message
    ldr    r1, =cursor           @ pcur = &cursor
    str    r0, [r1]              @ *pcur = pmsg
    pop    {pc}                  @ return void

read_asm:
    ldr    r2, =cursor           @ pcur = &cursor
    ldr    r1, [r2]              @ pmsg = *pcur = &message
    ldrb   r0, [r1]              @ letter = *pmsg = message[i]
    add    r1, #1                @ ++pmsg
    str    r1, [r2]              @ *pcur = pmsg
    bx     lr                    @ return letter

@ r0 = read function
@ r1 = write function
decompress:
    push   {r4-r6, lr}           @ read_lc, write_lc, match_lc.offset
    mov    r4, r0                @ read_lc = read
    mov    r5, r1                @ write_lc = write
decomp:                          @
    blx    r4                    @ letter = read_lc()
    tst    r0, r0                @ zflag = letter == '\0' ? 1 : 0
    beq    done_decomp           @ if zflag == 1 goto done_decomp
    cmp    r0, #'@'              @ zflag = letter == '@' ? 1 : 0
    beq    decomp_match          @ if zflag == 1 goto decomp_match
@decomp_char:                    @
    mov    r1, r5                @ write = write_lc
    bl     add_char              @ add_char(letter, write)
    b      decomp                @ continue
decomp_match:                    @
    blx    r4                    @ letter = read_lc()
    mov    r6, r0                @ match_lc.offset = letter
    sub    r6, #'0'              @ match_lc.offset -= '0'
    blx    r4                    @ letter = read_lc()
    sub    r0, #'0'              @ match.length = letter - '0'
    mov    r1, r5                @ write = write_lc
    mov    r2, r6                @ match.offset = match_lc.offset
    bl     add_match             @ add_match(match.length, write, match.offset)
    b      decomp                @ continue
done_decomp:                     @
    pop    {r4-r6, pc}           @ return void

@ r0 = match.length
@ r1 = write function
@ r2 = match.offset
add_match:
    push   {r4-r6, lr}           @ pbuff_match, write_lc, match_lc.length
    ldr    r4, =buffer           @ pbuff_match = &buffer
    add    r4, r2                @ pbuff_match += match.offset
    mov    r5, r1                @ write_lc = write
    mov    r6, r0                @ match_lc.length = match.length
expand:                          @
    tst    r6, r6                @ zflag = match_lc.length == 0 ? 1 : 0
    beq    done_match            @ if zflag == 1 goto done_match
    sub    r6, #1                @ --match_lc.length
    ldrb   r0, [r4]              @ letter = *pbuff_match
    mov    r1, r5                @ write = write_lc
    bl     add_char              @ add_char(letter, write)
    b      expand                @ continue
done_match:                      @
    pop    {r4-r6, pc}           @ return void

@ r0 = letter to write
@ r1 = write function
add_char:
    push   {r4, lr}              @ letter_lc
    mov    r4, r0                @ letter_lc = letter
    blx    r1                    @ write(letter)
    ldr    r0, =buffer           @ pbuff = &buffer
    mov    r1, r0                @ pbuff_end = pbuff
    add    r1, #buff_size - 1    @ pbuff_end += buff_size - 1
    mov    r2, r1                @ pbuff_prev = pbuff_end
write_buff:                      @
    cmp    r1, r0                @ zflag = pbuff_end == pbuff ? 1 : 0
    beq    done_char             @ if zflag == 1 goto done_char
    sub    r2, #1                @ --pbuff_prev
    ldrb   r3, [r2]              @ letter = *pbuff_prev
    strb   r3, [r1]              @ *pbuff_end = letter
    sub    r1, #1                @ --pbuff_end
    b      write_buff            @ continue
done_char:                       @
    strb   r4, [r0]              @ *pbuff = letter_lc
    pop    {r4, pc}              @ return void
