; ---------------------------------------------------------------------------
; - Stars - Video Routines (video.inc)                                      -
; - Copyright (C) 1998-2024 Alexandru Groza of Microprogramming TECHNIQUES  -
; - All rights reserved.                                                    -
; ---------------------------------------------------------------------------
; - License: GNU General Public License v3.0                                -
; ---------------------------------------------------------------------------

; routines:
;   + videoClearScreen
;   + videoMoveCursor
;   + videoWriteChar
; ---------------------------------------------------------------------------

; general VGA equates
; ---------------------------------------------------------------------------
  kVGAColumnCount    EQU  80
  kVGARowCount       EQU  25

; VGA color equates
; ---------------------------------------------------------------------------
  clBlack            EQU  00h
  clBlue             EQU  01h
  clGreen            EQU  02h
  clCyan             EQU  03h
  clRed              EQU  04h
  clMagenta          EQU  05h
  clBrown            EQU  06h
  clLightGray        EQU  07h
  clDarkGray         EQU  08h
  clLightBlue        EQU  09h
  clLightGreen       EQU  0Ah
  clLightCyan        EQU  0Bh
  clLightRed         EQU  0Ch
  clLightMagenta     EQU  0Dh
  clYellow           EQU  0Eh
  clWhite            EQU  0Fh

; Clears the screen by resetting the video mode to 80 x 25 / color.
; Input:
;     none
; Output:
;     none
; Affects:
;     AX
; Preserves:
;     none
; ---------------------------------------------------------------------------
videoClearScreen proc near

  mov ax,0003h
  int 10h

  ret

videoClearScreen endp

; Moves the cursor to the specified row and column.
; Input:
;     DH - row
;     DL - column
; Output:
;     none
; Affects:
;     AH, BH
; Preserves:
;     none
; ---------------------------------------------------------------------------
videoMoveCursor proc near

  mov ah,02h
  xor bh,bh
  int 10h

  ret

videoMoveCursor endp

; Writes a single character at cursor position.
; Input:
;     AL - character
;     BL - attribute
; Output:
;     none
; Affects:
;     AH, BH, CX
; Preserves:
;     none
; ---------------------------------------------------------------------------
videoWriteChar proc near

  mov ah,09h
  xor bh,bh
  mov cx,01h
  int 10h

  ret

videoWriteChar endp
