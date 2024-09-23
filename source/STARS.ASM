; ---------------------------------------------------------------------------
; - Stars - Screen Saver (stars.asm)                                        -
; - Copyright (C) 1998-2024 Alexandru Groza of Microprogramming TECHNIQUES  -
; - All rights reserved.                                                    -
; ---------------------------------------------------------------------------
; - License: GNU General Public License v3.0                                -
; ---------------------------------------------------------------------------

LOCALS @@

P8086
MODEL TINY

CODESEG
  org 100h

STARTUPCODE

  jmp @start

; include section
; ---------------------------------------------------------------------------
include equates.inc
include data.inc
include routines.inc
include video.inc
include sky.inc

; Main program entrypoint.
; ---------------------------------------------------------------------------
@start:
  cld

  call videoClearScreen

  mov ah,01h
  mov ch,20h
  int 10h

@@doLoop:
  mov ah,01h
  int 16h

  jnz @@endLoop

  mov ah,02h
  int 1Ah

  shr dh,1
  jnc @@continue

  call randomize

@@continue:
  call skyScan

  mov bx,6
  call random
  shl bx,1
  call word ptr [bx + starRoutineTable]

  jmp @@doLoop

@@endLoop:
  xor ah,ah
  int 16h

  call videoClearScreen

  mov ah,01h
  mov cx,0607h
  int 10h

@exit:
  mov ax,4C00h
  int 21h

end
