; ---------------------------------------------------------------------------
; - Stars - Routines (routines.inc)                                         -
; - Copyright (C) 1998-2024 Alexandru Groza of Microprogramming TECHNIQUES  -
; - All rights reserved.                                                    -
; ---------------------------------------------------------------------------
; - License: GNU General Public License v3.0                                -
; ---------------------------------------------------------------------------

; routines:
;   + delay
;   + randomize
;   + random
; ---------------------------------------------------------------------------

; global variables section
; ---------------------------------------------------------------------------
  dRandSeed    DW  ?

; Delay by a given value in milliseconds.
; Input:
;     BX - number of milliseconds
; Output:
;     none
; Affects:
;     AX, CX, DX
; Preserves:
;     none
; ---------------------------------------------------------------------------
delay proc near

  mov ax,1000
  mul bx
  mov cx,dx
  mov dx,ax
  mov ah,86h

  int 15h

  ret

delay endp

; Initializes the random number generator.
; Input:
;     none
; Output:
;     DX - low order word of tick count
; Affects:
;     AX
; Preserves:
;     none
; ---------------------------------------------------------------------------
randomize proc near

  xor ax,ax
  int 1Ah

  mov word ptr [dRandSeed],dx

  ret

randomize endp

; Generates a random number.
; Input:
;     BX - maximum range
; Output:
;     BX - random number between 0 and maximum given range
; Affects:
;     AX, CX, DX
; Preserves:
;     CX, DX
; ---------------------------------------------------------------------------
random proc near

  push cx
  push dx

  mov ax,25173
  mul word ptr [dRandSeed]
  add ax,13849

  mov word ptr [dRandSeed],ax

  xor dx,dx
  inc bx
  div bx
  mov bx,dx

  pop dx
  pop cx

  ret

random endp
