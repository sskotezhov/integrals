section .rodata
    half dq 0.5
section .text

global f1
global f2
global f3

global f3_der
global f2_der
global f1_der

f1:
    finit
    push 3
    fild dword[esp]
    add esp, 4
    fld qword[esp+4]
    fld1
    fsubp
    sub esp, 8
    fst qword[esp]
    fld qword[esp]
    add esp, 8
    fmulp
    fld1
    faddp
    fdivp
    ret

f2:
    finit
    fld qword[esp+4]
    fld qword[half]
    faddp
    fsqrt
    ret

f3:
    finit
    fldl2e
    fld1
    fsubp
    f2xm1
    fld1
    faddp
    push 2
    fild dword[esp]
    add esp, 4
    fmulp
    fld qword[esp+4]
    fxch
    
    fyl2x

    sub esp, 4
    fist dword[esp]

    fild dword[esp]
    fsub
    f2xm1
    fld1
    faddp
    fild dword[esp]
    add esp, 4
    fxch
    fscale
    fld1
    fxch
    fdivp
    ret 

f3_der:
    finit
    sub esp, 8
    push dword[esp+16]
    push dword[esp+12]
    call f3
    add esp, 16
    fchs
    ret
    
f2_der:
    fld qword[esp+4]
    fld qword[half]
    faddp
    fsqrt
    push 2
    fild dword[esp]
    fmulp
    add esp, 4
    fld1
    fxch
    fdivp
    ret

f1_der:
    finit
    fld qword[esp+4]
    fld1
    fsubp
    sub esp, 8
    fst qword[esp]
    fld qword[esp]
    add esp, 8
    fmulp
    fld1
    faddp
    sub esp, 8
    fst qword[esp]
    fld qword[esp]
    add esp, 8
    fmulp
    fld qword[esp+4]
    fld1
    fsubp
    push 6
    fild dword[esp]
    add esp, 4
    fmulp
    fxch
    fdivp
    fchs
    ret
    